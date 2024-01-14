#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& ref) { *this = ref; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) {
  if (this != &ref) {
  }
  return *this;
}

void ScalarConverter::showResult(const converter_t& convertedVal,
                                 const validadtionFlag_t& flags) {
  std::cout << std::showpoint << std::fixed << std::setprecision(1);

  if (flags.impossible) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
  } else if (flags.realOverflow) {
    std::cout << "char: overflow\n";
    std::cout << "int: overflow\n";
    std::cout << "float: overflow\n";
    std::cout << "double: overflow\n";
  } else if (flags.notNum) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << convertedVal.toFloatForm << "f" << std::endl;
    std::cout << "double: " << convertedVal.toDoubleForm << std::endl;
  } else if (flags.intOverflow) {
    std::cout << "char: overflow\n";
    std::cout << "int: overflow\n";
    std::cout << "float: " << convertedVal.toFloatForm << "f" << std::endl;
    std::cout << "double: " << convertedVal.toDoubleForm << std::endl;
  } else if (flags.charOverflow) {
    std::cout << "char: overflow\n";
    std::cout << "int: " << convertedVal.toIntForm << std::endl;
    std::cout << "float: " << convertedVal.toFloatForm << "f" << std::endl;
    std::cout << "double: " << convertedVal.toDoubleForm << std::endl;
  } else if (!std::isprint(convertedVal.toCharForm)) {
    std::cout << "char: Non Displayable\n";
    std::cout << "int: " << convertedVal.toIntForm << std::endl;
    std::cout << "float: " << convertedVal.toFloatForm << "f" << std::endl;
    std::cout << "double: " << convertedVal.toDoubleForm << std::endl;
  } else {
    std::cout << "char: "
              << "\'" << convertedVal.toCharForm << "\'" << std::endl;
    std::cout << "int: " << convertedVal.toIntForm << std::endl;
    std::cout << "float: " << convertedVal.toFloatForm << "f" << std::endl;
    std::cout << "double: " << convertedVal.toDoubleForm << std::endl;
  }
}
void ScalarConverter::ConvertForm(const std::string& str) {
  converter_t ChangeForm;
  type_define type = Check_Type(str, ChangeForm);

  if (type == Char_Form) {
    convertFromChar(ChangeForm);
  } else if (type == Int_Form) {
    convertFromInt(ChangeForm);
  } else if (type == Float_Form) {
    convertFromFloat(ChangeForm);
  } else if (type == Double_Form) {
    convertFromDouble(ChangeForm);
  }
  validadtionFlag_t flags = Check_Valid(str, type);
  showResult(ChangeForm, flags);
}

ScalarConverter::type_define ScalarConverter::Check_Type(
    const std::string& str, converter_t& converter) {
  if (Check_Int(str, converter.toIntForm)) {
    return Int_Form;
  } else if (Check_Float(str, converter.toFloatForm)) {
    return Float_Form;
  } else if (Check_Double(str, converter.toDoubleForm)) {
    return Double_Form;
  } else if (Check_Char(str, converter.toCharForm))
    return Char_Form;
  return Literal_Form;
}

bool ScalarConverter::Check_Int(const std::string& str, int& intForm) {
  char* end = NULL;
  long temp = strtol(str.c_str(), &end, 10);

  if (end != str.c_str() && *end == 0) {
    intForm = static_cast<int>(temp);
    return true;
  } else {
    return false;
  }
}

bool ScalarConverter::Check_Float(const std::string& str, float& floatForm) {
  char* end = NULL;
  float temp = strtof(str.c_str(), &end);

  if (end != str.c_str() && *end == 'f' && *(end + 1) == '\0') {
    floatForm = static_cast<float>(temp);
    return true;
  } else {
    return false;
  }
}

bool ScalarConverter::Check_Double(const std::string& str, double& doubleForm) {
  char* end = NULL;
  double temp = strtod(str.c_str(), &end);

  if (end != str.c_str() && *end == 0) {
    doubleForm = static_cast<double>(temp);
    return true;
  } else {
    return false;
  }
}

bool ScalarConverter::Check_Char(const std::string& input, char& charForm) {
  if (input.size() == 1) {
    charForm = static_cast<char>(input[0]);
    return (true);
  } else if (input.size() == 0) {
    charForm = '\0';
    return (true);
  } else {
    return (false);
  }
}

void ScalarConverter::convertFromChar(converter_t& convertedVal) {
  convertedVal.toIntForm = static_cast<int>(convertedVal.toCharForm);
  convertedVal.toFloatForm = static_cast<float>(convertedVal.toCharForm);
  convertedVal.toDoubleForm = static_cast<double>(convertedVal.toCharForm);
}

void ScalarConverter::convertFromInt(converter_t& convertedVal) {
  convertedVal.toCharForm = static_cast<char>(convertedVal.toIntForm);
  convertedVal.toFloatForm = static_cast<float>(convertedVal.toIntForm);
  convertedVal.toDoubleForm = static_cast<double>(convertedVal.toIntForm);
}

void ScalarConverter::convertFromFloat(converter_t& convertedVal) {
  convertedVal.toCharForm = static_cast<char>(convertedVal.toFloatForm);
  convertedVal.toIntForm = static_cast<int>(convertedVal.toFloatForm);
  convertedVal.toDoubleForm = static_cast<double>(convertedVal.toFloatForm);
}

void ScalarConverter::convertFromDouble(converter_t& convertedVal) {
  convertedVal.toCharForm = static_cast<char>(convertedVal.toDoubleForm);
  convertedVal.toIntForm = static_cast<int>(convertedVal.toDoubleForm);
  convertedVal.toFloatForm = static_cast<float>(convertedVal.toDoubleForm);
}

ScalarConverter::validadtionFlag_t ScalarConverter::Check_Valid(
    const std::string& input, ScalarConverter::type_define type) {
  validadtionFlag_t flags;
  const double INF = std::numeric_limits<double>::infinity();
  double num = strtod(input.c_str(), NULL);

  if (type == Literal_Form) {
    flags.impossible = true;
    return flags;
  } else {
    if ((type == Float_Form || type == Double_Form) &&
        (isnan(num) || num == INF || num == -INF)) {
      flags.notNum = true;
    } else if (num > INT_MAX || num < INT_MIN) {
      flags.charOverflow = true;
      flags.intOverflow = true;
      if (type != Int_Form) {
        flags.realOverflow = true;
      }
    } else if (num > CHAR_MAX || num < CHAR_MIN) {
      flags.charOverflow = true;
    }
    return flags;
  }
}
