#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public Form {
 private:
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(const std::string& _name);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& ref);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

  bool execute(Bureaucrat const& Presidential) const;
};