#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1();
void test2();
void test3();
void test4();

int main() {
  test1();
  test2();
  test3();
  test4();

  return 0;
}

void test1() {
  Bureaucrat bureaucrat("shrubbery executor", 1);
  Intern intern;
  Form* form;

  form = intern.makeForm("shrubbery creation", "shrubbery form");
  if (form == 0) return;

  try {
    form->beSigned(bureaucrat);
  } catch (std::exception& e) {
    std::cout << "catch exception of shrubberyCreationFormTest" << std::endl;
  }
  form->execute(bureaucrat);

  delete form;
}

void test2() {
  Bureaucrat bureaucrat("robotomy executor", 1);
  Intern intern;
  Form* form;

  form = intern.makeForm("robotomy request", "robotomy form");
  if (form == 0) return;

  try {
    form->beSigned(bureaucrat);
  } catch (std::exception& e) {
    std::cout << "catch exception of robotomyRequestFormTest" << std::endl;
  }
  form->execute(bureaucrat);

  delete form;
}

void test3() {
  Bureaucrat bureaucrat("presidential executor", 1);
  Intern intern;
  Form* form;

  form = intern.makeForm("presidential pardon", "presidential form");
  if (form == 0) return;

  try {
    form->beSigned(bureaucrat);
  } catch (std::exception& e) {
    std::cout << "catch exception of presidentialPardonFormTest" << std::endl;
  }
  form->execute(bureaucrat);

  delete form;
}

void test4() {
  Bureaucrat bureaucrat("presidential executor", 1);
  Intern intern;
  Form* form = 0;

  try {
    form = intern.makeForm("no form", "presidential form");
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  if (form == 0) return;

  try {
    form->beSigned(bureaucrat);
  } catch (std::exception& e) {
    std::cout << "catch exception of presidentialPardonFormTest" << std::endl;
  }
  form->execute(bureaucrat);

  delete form;
}