#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  static const std::string types[3];
  static Form* (Intern::*forms[3])(const std::string&) const;

  Form* getNewShrubberyCreationForm(const std::string& name) const;
  Form* getRobotomyRequestForm(const std::string& name) const;
  Form* getPresidentialPardonForm(const std::string& name) const;

 public:
  Intern();
  Intern(const Intern& ref);
  ~Intern();

  Intern& operator=(const Intern& ref);

  Form* makeForm(const std::string type, const std::string name);

  class FormNotFoundException : public std::exception {
    const char* what() const throw();
  };
};