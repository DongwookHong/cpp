#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"
class Form;

class Bureaucrat {
 private:
  const std::string name;
  unsigned int grade;

  Bureaucrat();

 public:
  ~Bureaucrat();

  Bureaucrat(const std::string _name, const unsigned int _grade);
  Bureaucrat(const Bureaucrat& ref);
  Bureaucrat& operator=(const Bureaucrat& ref);

  const std::string getName() const;
  unsigned int getGrade() const;
  void setGrade(const unsigned int grade);

  void increment();
  void decrement();

  void signForm(const Form& ref);

  class GradeTooHighException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what(void) const throw();
  };
};
std::ostream& operator<<(std::ostream& print, const Bureaucrat& ref);
