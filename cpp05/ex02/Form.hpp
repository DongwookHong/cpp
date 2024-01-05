#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
 private:
  const std::string name;
  bool IsSigned;
  const unsigned int grade;

  Form();

 public:
  ~Form();

  Form(const std::string _name, const unsigned int _grade);
  Form(const Form& ref);
  Form operator=(const Form& ref);

  const std::string getName() const;
  unsigned int getGrade() const;

  void beSigned(const Bureaucrat& Burea);

  void signForm(const Bureaucrat& burea);

  class GradeTooHighException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what(void) const throw();
  };
};
std::ostream& operator<<(std::ostream& out, const Form& ref);
