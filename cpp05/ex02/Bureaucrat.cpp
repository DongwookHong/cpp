#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
  std::cout << "default constructor called " << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "destructor constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.getName()) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  *this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
  if (this != &ref) {
    this->grade = ref.getGrade();
  }
  return *this;
}

Bureaucrat::Bureaucrat(const std::string _name, const unsigned int _grade)
    : name(_name) {
  std::cout << "constructor called" << std::endl;
  this->grade = _grade;
  if (this->grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}
void Bureaucrat::increment() {
  if (this->grade <= 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else
    this->grade -= 1;
}

void Bureaucrat::decrement() {
  if (this->grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (this->grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else
    this->grade += 1;
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

std::ostream& operator<<(std::ostream& print, const Bureaucrat& ref) {
  print << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
  return print;
}