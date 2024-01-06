#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int main() {
  Bureaucrat bureaucrat("shrubbery_executor", 1);
  ShrubberyCreationForm shrubberyForm;

  try {
    shrubberyForm.beSigned(bureaucrat);
  } catch (std::exception& e) {
    std::cout << "catch exception of shrubberyCreationFormTest" << std::endl;
  }
  shrubberyForm.execute(bureaucrat);
  return 0;
}
