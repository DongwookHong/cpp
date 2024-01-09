#pragma once

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public Form {
 private:
  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(const std::string& _name);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& ref);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

  bool execute(Bureaucrat const& Shrub) const;
};