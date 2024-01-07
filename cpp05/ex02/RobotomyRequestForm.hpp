#pragma once

#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm();
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& ref);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

  bool execute(Bureaucrat const& robot) const;
};