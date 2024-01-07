#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& ref)
    : AForm(ref) {
  *this = ref;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& ref) {
  if (this != &ref) {
    this->IsSigned = ref.getType();
  }
  return *this;
}

bool PresidentialPardonForm::execute(Bureaucrat const& Presidential) const {
  if (beExecute() == true) {
    std::cout << Presidential.getName()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return true;
  } else {
    std::cout << Presidential.getName()
              << " has not been pardoned and remains convicted." << std::endl;
    return false;
  }
}