#include "Form.hpp"

Form::~Form() {}
Form ::Form(const std::string _name, const unsigned int _grade)
    : name(_name), grade(_grade) {
  this->IsSigned = false;
  if (this->grade < 1) {
    throw Form::GradeTooHighException();
  } else if (this->grade > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form& ref) : name(ref.getName()), grade(getGrade()) {
  *this = ref;
}

void Form::signForm(const Bureaucrat& Burea) {
  if (this->IsSigned) {
    std::cout << Burea.getName() << " signed " << this->getName() << std::endl;
  } else {
    std::cout << Burea.getName() << " couldn't sign " << this->getName()
              << " becuase "
              << " can't be bothered" << std::endl;
  }
}

void Form::beSigned(const Bureaucrat& Burea) {
  if (Burea.getGrade() <= this->getGrade()) {
    this->IsSigned = true;
  }
}

const char* Form::GradeTooHighException::what(void) const throw() {
  return "Check grade , Grade is too High";
}

const char* Form::GradeTooHighException::what(void) const throw() {
  return "Check grade , Grade is too Low";
}

const std::string Form::getName() const { return this->name; }

unsigned int Form::getGrade() const { return this->grade; }

Form Form::operator=(const Form& ref) { *this = ref; }

std::ostream& operator<<(std::ostream& out, const Form& ref) {
  out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
  return out;
}