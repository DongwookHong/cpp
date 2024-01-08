#pragma once

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public Form {
 private:
  RobotomyRequestForm();

 public:
  RobotomyRequestForm(const std::string& _name);
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& ref);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

  bool execute(Bureaucrat const& robot) const;
};