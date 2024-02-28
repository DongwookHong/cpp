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
  void checkInfo(const std::string&);
  bool checkDate(const std::string&, int&, int&, int&);
  bool checkValue(const std::string&);
  void printData(const std::string&, double);

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

 public:
  BitcoinExchange(char*);
  ~BitcoinExchange();

  void checkFile(char*);
  std::string doubleToString(double);
  bool isDigits(const std::string&);
  
  class Error : public std::exception {
   public:
    const char* what(void) const throw();
  };
};
