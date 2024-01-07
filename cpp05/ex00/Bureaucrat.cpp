#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) { *this = ref; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
  if (this != &ref) {
    this->grade = ref.getGrade();
  }
  return *this;
}

Bureaucrat::Bureaucrat(const std::string _name, const unsigned int _grade)
    : name(_name) {
  this->grade = _grade;
  if (this->grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}

void Bureaucrat::increment() {
  if (this->grade - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->grade -= 1;
}

void Bureaucrat::decrement() {
  if (this->grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade += 1;
}

std::ostream& operator<<(std::ostream& print, const Bureaucrat& ref) {
  print << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
  return print;
}

const std::string Bureaucrat::getName() const { return this->name; }

unsigned int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::setGrade(const unsigned int grade) { this->grade = grade; }

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  const char* msg;
  msg = "Check grade , Grade is too High";
  return msg;
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  const char* msg;
  msg = "Check grade , Grade is too Low";
  return msg;
};