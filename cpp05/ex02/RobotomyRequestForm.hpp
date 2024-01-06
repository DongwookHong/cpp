#pragma once

#include "AForm.hpp"
class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm();
  ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& ref);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

  void execute(Bureaucrat const& Shrub);
};