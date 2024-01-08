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
int main() {
  test1();

  return 0;
}

void test1() {
  Intern someRandomIntern;
  Form* rrf;
  Bureaucrat b("a", 30);
  rrf = someRandomIntern.makeForm("robotomy request", "bender");
  rrf->beSigned(b);
  rrf->execute(b);
}