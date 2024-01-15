#pragma once

#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& ref);
  ScalarConverter& operator=(const ScalarConverter& ref);

  typedef struct converter_s {
    char toCharForm;
    int toIntForm;
    float toFloatForm;
    double toDoubleForm;
  } converter_t;

  enum type_define {
    Int_Form = 0,
    Float_Form,
    Double_Form,
    Char_Form,
    Literal_Form,
  };

  typedef struct validationFlag_s {
    bool charOverflow;
    bool intOverflow;
    bool realOverflow;
    bool notNum;
    bool impossible;

    validationFlag_s()
        : charOverflow(false),
          intOverflow(false),
          realOverflow(false),
          notNum(false),
          impossible(false) {}
  } validadtionFlag_t;

  static bool Check_Int(const std::string&, int&);
  static bool Check_Float(const std::string& str, float&);
  static bool Check_Double(const std::string& str, double&);
  static bool Check_Char(const std::string& str, char&);

  static void convertFromChar(converter_t&);
  static void convertFromInt(converter_t&);
  static void convertFromFloat(converter_t&);
  static void convertFromDouble(converter_t&);

  static void showResult(const converter_t&, const validadtionFlag_t&);

 public:
  static void ConvertForm(const std::string&);
  static type_define Check_Type(const std::string&, converter_t&);
  static validadtionFlag_t Check_Valid(const std::string&, type_define);
};
