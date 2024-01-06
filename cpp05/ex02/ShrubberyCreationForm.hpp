#pragma once

#include "AForm.hpp"
#include "fstream"
class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm();
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& ref);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

  void execute(Bureaucrat const& Shrub);
};