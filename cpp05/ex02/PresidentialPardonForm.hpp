#pragma once

#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& ref);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

  void execute(Bureaucrat const& Shrub);
};