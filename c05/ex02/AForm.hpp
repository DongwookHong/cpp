#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 protected:
  const std::string name;
  bool IsSigned;
  const unsigned int SignGrade;
  const unsigned int ExecuteGrade;
  Form();

 public:
  virtual ~Form();

  Form(const std::string _name, const unsigned int _grade,
       const unsigned int _exe);
  Form(const Form& ref);
  Form& operator=(const Form& ref);

  const std::string getName() const;
  unsigned int getSignGrade() const;
  unsigned int getExecuteGrade() const;
  bool getType() const;

  virtual bool execute(Bureaucrat const& executor) const = 0;

  void beSigned(const Bureaucrat& Burea);
  bool beExecute() const;

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
