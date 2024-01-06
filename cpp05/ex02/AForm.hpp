#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
 protected:
  const std::string name;
  bool IsSigned;
  const unsigned int SignGrade;
  const unsigned int ExecuteGrade;
  AForm();

 public:
  ~AForm();

  AForm(const std::string _name, const unsigned int _grade,
        const unsigned int _exe);
  AForm(const AForm& ref);
  AForm& operator=(const AForm& ref);

  const std::string getName() const;
  unsigned int getSignGrade() const;
  unsigned int getExecuteGrade() const;
  bool getType() const;

  virtual void execute(Bureaucrat const& executor) = 0;

  void beSigned(const Bureaucrat& Burea);
  bool beExecute();

  class GradeTooHighException : public std::exception {
   public:
    const char* what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what(void) const throw();
  };
};
std::ostream& operator<<(std::ostream& out, const AForm& ref);
