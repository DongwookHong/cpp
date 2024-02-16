#include "BitcoinExchange.hpp"

void BitcoinExchange::checkFile(char* file) {
    try{
        checkCsvForm();
        checkInputFile(file);
        ownCoin(file);
    }catch(const std::exception& e){
        std::cout <<e.what()<<std::endl;
        return ;
    }
}



void BitcoinExchange::checkCsvForm() {
        const std::string filename = "data.csv";
        const std::string sub = "date,exchange_rate";
        std::ifstream csv(filename);
        std::string read;
        float value;

        if (!csv) {
            std::cout<<"Error: could not open file.";
            throw Error();
        }

        if (std::getline(csv, read) && read != sub) {
            std::cout<<"Error: invalid form";
            throw Error();
        }

        while(std::getline(csv, read)) {
            std::istringstream iss(read);
            std::string date,valueStr;
            
            std::getline(iss, date, ',');
            if (!validDate(date)) {
                std::cout<<"invalid Date.";
                throw Error();
            }
            std::getline(iss,valueStr);
            if (!validInput(valueStr)) {
                std::cout<<"Error: invalid Input.";
                throw Error();
            }
            value = std::stof(valueStr);
            coinData[date] = value;
        }
}


bool BitcoinExchange::validDate(const std::string& date) {
     if (date.length() != 10) 
        return false;
    std::istringstream iss(date);
    std::string data;
    int year = 0, month = 0, day = 0;
    int i = 0;

    while (std::getline(iss, data, '-')) {
        std::istringstream dataStream(data);
        if (i == 0) {
            dataStream >> year;
            if (year < 1000 || year > 9999) 
                return false;
        } else if (i == 1) {
            dataStream >> month;
            if (month < 1 || month > 12) return false;
        } else if (i == 2) { 
            dataStream >> day;
            if (day < 1 || day > 31) return false;
            if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) return false; 
            if (month == 2) {
                if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && day > 29) return false; 
                else if (day > 28) return false; 
            }
        }
        ++i;
    }
    return i == 3;
}


bool BitcoinExchange::validInput(const std::string& str) {
    char* end = NULL;
    double value = std::strtod(str.c_str(), &end);

    if ((value == 0.0 && !std::isdigit(str[0])) || str[0] == '-') {
        return false;
    }
    if (*end && std::strcmp(end, "") != 0) {
        return false;
    }
    if (value < 0) {
        return false;
    }
    return true;
}




void BitcoinExchange::checkInputFile(char* file)
{
    std::ifstream fs(file);
    std::string str;

    if (!fs.is_open()) {
        std::cout<<"Error: could not open file.";
        throw Error();
    }

    if (!std::getline(fs, str)) {
        std::cout<<"Error: check file form.";
        throw Error();
    }

    if (str.compare("date | value") != 0) {
        std::cout<<"Error: check file form.";
        throw Error();
    }
    fs.close();
}


void BitcoinExchange::ownCoin(std::string file) {
    std::ifstream config(file);

    if (!config.is_open()) {
        throw std::runtime_error("Error: could not open file " + file);
    }

    std::string read;
    
    if (!getline(config, read) || read.empty()) {
      std::cout<<"Error: file empty or no data.";
      throw Error();
    }
    while (getline(config, read)) 
    checkInfo(read);

}

   void BitcoinExchange::checkInfo(const std::string& info) {
        std::istringstream format(info);
        std::string date, separator,valuestr;
        float value;
        int year, month, day= 0;

        if (!(format >> date >> separator >> value) || separator != "|") {
            std::cout << "Error: bad input => " << info << std::endl;
            return ;
        }
        valuestr = floatToString(value);
        if (!checkDate(date, year, month, day) || !checkValue(valuestr)) {
            return ;
        }

        printData(date, value);
        return ;
    }

bool BitcoinExchange::checkDate(const std::string& date, int& year, int& month, int& day) {
    std::istringstream dateStream(date);
    std::string part;
    int idx = 0;

 if (date.empty() || date[date.length() - 1] == '-') {
        std::cout << "Error: incorrect date format => " << date << std::endl;
        return false; 
    }

    while (std::getline(dateStream, part, '-')) {
        std::istringstream partStream(part);
        switch (idx) {
            case 0: 
                partStream >> year;
                if (year < MinYear || year > MaxYear) {
                    std::cout << "Error: invalid year => " << date << std::endl;
                    return false;
                }
                break;
            case 1: 
                partStream >> month;
                if (month < 1 || month > 12) {
                    std::cout << "Error: invalid month => " << date << std::endl;
                    return false;
                }
                break;
            case 2: 
                partStream >> day;
                if (day < 1 || day > 31) {
                    std::cout << "Error: invalid day => " << date << std::endl;
                    return false;
                }
                break;
        }
        ++idx;
    }

    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
        std::cout << "Error: invalid day => " << date << std::endl;
        return false;
    }
    if (month == 2) {
                if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && day > 29) {
                    std::cout << "Error: invalid day => " << date << std::endl;
                    return false;
                } 
                else if (day > 28) {
                      std::cout << "Error: invalid day => " << date << std::endl;
                    return false;
                    } 
            }
    if (idx !=3)
    {
        std::cout << "Error: invalid form";
        return false;
    }
    return true;
}



bool BitcoinExchange::checkValue(const std::string& str) {
    char *ptr = NULL;
    double value = std::strtod(str.c_str(), &ptr);

    if (str.empty() || str[0] == '.' || str[str.length() - 1] == '.') {
        std::cout << "Error: not a valid number." << std::endl;
        return false;
    }

    if (value == 0.0 && (ptr == str.c_str() || !std::isdigit(str[0]))) {
        std::cout << "Error: not a valid number." << std::endl;
        return false;
    }

    if (*ptr != '\0') { 
        std::cout << "Error: not a valid number." << std::endl;
        return false;
    }

    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    if (str.length() > 10 || (str.length() == 10 && value > 2147483647)) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}


void BitcoinExchange::printData(const std::string& date, float n) {
    float res = 0;
    std::map<std::string, float>::const_iterator iter = coinData.find(date);

    if (iter != coinData.end()) {
        res = iter->second * n;
    } else {
        iter = coinData.lower_bound(date);
        if (iter != coinData.begin()) {
            --iter; 
            res = iter->second * n;
        } else {
            std::cout << "Error: invalid date." << std::endl;
            return;
        }
    }

    if (n == static_cast<int>(n)) {
        std::cout << date << " => " << static_cast<int>(n) << " = " << res << std::endl;
    } else {
        std::cout << date << " => " << n << " = " << res << std::endl;
    }
}







BitcoinExchange::BitcoinExchange(char *file){
    checkFile(file);
}

BitcoinExchange::~BitcoinExchange(){}










std::string BitcoinExchange::floatToString(float value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

const char* BitcoinExchange::Error::what(void) const throw() {
  return "";
}

