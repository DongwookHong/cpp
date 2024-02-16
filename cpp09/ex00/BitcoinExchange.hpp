#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <fstream>



#define MinYear 2009
#define MaxYear 2022

class BitcoinExchange
{
private:
    std::map<std::string, float> coinData;

    void checkCsvForm();
    void checkInputFile(char* );
    bool validDate(const std::string& );
    bool validInput(const std::string&);
    
    void ownCoin(std::string );
    void checkInfo(const std::string& info);
    bool checkDate(const std::string& date, int& year, int& month, int& day);
    bool checkValue(const std::string& str);
    void printData(const std::string& , float );

    BitcoinExchange();
public:
    BitcoinExchange(char *);

    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& ref);
    BitcoinExchange& operator=(const BitcoinExchange& ref);

    void checkFile(char* file);
    std::string floatToString(float value);

 class Error : public std::exception {
   public:
    const char* what(void) const throw();
  };

};
