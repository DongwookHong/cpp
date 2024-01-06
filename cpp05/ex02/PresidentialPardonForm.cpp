#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& ref):AForm {

	}
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& ref) {}