#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1();
void test2();
void test3();
int main() {
  test1();
  test2();
  test3();

  return 0;
}

void test1() {
  try {
    Bureaucrat bureaucrat("shrubbery", 145);
    ShrubberyCreationForm shrubberyForm("shrubbery");

    shrubberyForm.beSigned(bureaucrat);
    // shrubberyForm.execute(bureaucrat);
    bureaucrat.executeForm(shrubberyForm);
  } catch (std::exception& e) {
    std::cout << "catch exception of shrubberyCreationFormTest" << std::endl;
  }
}

void test2() {
  try {
    Bureaucrat bureaucrat("Robo", 3);
    RobotomyRequestForm robo("robo");
    robo.beSigned(bureaucrat);
    bureaucrat.executeForm(robo);
  } catch (std::exception& e) {
    std::cout << "catch exception of RobotomyRequestForm" << std::endl;
  }
}

void test3() {
  try {
    Bureaucrat bureaucrat("presi", 1);
    PresidentialPardonForm pre("pre");
    pre.beSigned(bureaucrat);
    bureaucrat.executeForm(pre);
  } catch (std::exception& e) {
    std::cout << "catch exception of PresidentialPardonForm" << std::endl;
  }
}