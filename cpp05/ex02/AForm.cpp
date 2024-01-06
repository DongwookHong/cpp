#include "AForm.hpp"

AForm::~AForm() {}
AForm ::AForm(const std::string _name, const unsigned int _grade,
              const unsigned int _exe)
    : name(_name), SignGrade(_grade), ExecuteGrade(_exe) {
  this->IsSigned = false;
}

AForm::AForm(const AForm& ref)
    : name(ref.getName()),
      SignGrade(ref.getSignGrade()),
      ExecuteGrade(ref.getExecuteGrade()) {
  *this = ref;
}

void AForm::beSigned(const Bureaucrat& Burea) {
  if (Burea.getGrade() <= this->getSignGrade()) {
    this->IsSigned = true;
  } else {
    throw GradeTooLowException();
  }
}

bool AForm::beExecute() {
  if (this->IsSigned == true &&
      this->getExecuteGrade() <= this->getSignGrade()) {
    return 1;
  } else {
    return 0;
  }
}

const char* AForm::GradeTooHighException::what(void) const throw() {
  return "Check grade , Grade is too High";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
  return "Check grade , Grade is too Low";
}

bool AForm::getType() const { return this->IsSigned; }

const std::string AForm::getName() const { return this->name; }

unsigned int AForm::getSignGrade() const { return this->SignGrade; }

unsigned int AForm::getExecuteGrade() const { return this->ExecuteGrade; }

AForm& AForm::operator=(const AForm& ref) {
  if (this != &ref) {
    this->IsSigned = ref.getType();
  }
  return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& ref) {
  out << ref.getName() << ", ref signgrade " << ref.getSignGrade()
      << " ref ExecuteGrade " << ref.getExecuteGrade() << ".";
  return out;
}