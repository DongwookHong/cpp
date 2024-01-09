#include "Form.hpp"

Form::~Form() {}
Form ::Form(const std::string _name, const unsigned int _grade,
            const unsigned int _exe)
    : name(_name), SignGrade(_grade), ExecuteGrade(_exe) {
  this->IsSigned = false;
  if (SignGrade < 1)
    throw GradeTooHighException();
  else if (SignGrade > 150)
    throw GradeTooLowException();
}

Form::Form(const Form& ref)
    : name(ref.getName()),
      SignGrade(ref.getSignGrade()),
      ExecuteGrade(ref.getExecuteGrade()) {
  *this = ref;
}

void Form::beSigned(const Bureaucrat& Burea) {
  if (Burea.getGrade() <= this->getSignGrade()) {
    this->IsSigned = true;
  } else {
    throw GradeTooLowException();
  }
}

const char* Form::GradeTooHighException::what(void) const throw() {
  return "Check grade , Grade is too High";
}

const char* Form::GradeTooLowException::what(void) const throw() {
  return "Check grade , Grade is too Low";
}

bool Form::getType() const { return this->IsSigned; }

const std::string Form::getName() const { return this->name; }

unsigned int Form::getSignGrade() const { return this->SignGrade; }

unsigned int Form::getExecuteGrade() const { return this->ExecuteGrade; }

Form& Form::operator=(const Form& ref) {
  if (this != &ref) {
    this->IsSigned = ref.getType();
  }
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& ref) {
  out << ref.getName() << ", ref signgrade " << ref.getSignGrade()
      << " ref ExecuteGrade " << ref.getExecuteGrade() << ".";
  return out;
}