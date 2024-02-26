#pragma once

#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define MinYear 2009
#define MaxYear 2022

class BitcoinExchange {
 private:
  std::map<std::string, double> coinData;

  void checkCsvForm();
  void checkInputFile(char*);
  bool validDate(const std::string&);
  bool validInput(const std::string&);

  void ownCoin(std::string);
  void checkInfo(const std::string& info);
  bool checkDate(const std::string& date, int& year, int& month, int& day);
  bool checkValue(const std::string& str);
  void printData(const std::string&, double);

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& ref);
  BitcoinExchange& operator=(const BitcoinExchange& ref);

 public:
  BitcoinExchange(char*);
  ~BitcoinExchange();

  void checkFile(char* file);
  std::string doubleToString(double value);

  class Error : public std::exception {
   public:
    const char* what(void) const throw();
  };
};
