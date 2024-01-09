#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.getName()) {
  *this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
  if (this != &ref) {
    this->grade = ref.getGrade();
  }
  return *this;
}

void Bureaucrat::signForm(const Form& form) {
  if (this->grade > form.getSignGrade()) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " becuase "
              << " you don't have enough Grade" << std::endl;
  } else if (form.getType()) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " becuase "
              << " already signed" << std::endl;
  } else
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const& form) {
  if (form.execute(*this)) {
    std::cout << this->name << " executed " << form.getName() << std::endl;
  } else {
    std::cout << this->name << " can't executed " << form.getName() << std::endl;
  }
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