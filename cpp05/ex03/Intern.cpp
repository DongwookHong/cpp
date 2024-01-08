#include "Intern.hpp"

const std::string Intern::types[3] = {"shrubbery creation", "robotomy request",
                                      "presidential pardon"};

Form* (Intern::*Intern::forms[3])(const std::string&) const = {
    &Intern::getNewShrubberyCreationForm, &Intern::getRobotomyRequestForm,
    &Intern::getPresidentialPardonForm};

Intern::Intern() {}

Intern::Intern(const Intern& ref) { *this = ref; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& ref) { return *this; }

Form* Intern::getNewShrubberyCreationForm(const std::string& name) const {
  return new ShrubberyCreationForm(name);
}

Form* Intern::getRobotomyRequestForm(const std::string& name) const {
  return new RobotomyRequestForm(name);
}

Form* Intern::getPresidentialPardonForm(const std::string& name) const {
  return new PresidentialPardonForm(name);
}

Form* Intern::makeForm(const std::string type, const std::string name) {
  int index;

  for (index = 0; index < 3; index++) {
    if (types[index] == type) {
      return (this->*forms[index])(name);
    }
  }
  throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
  return "form type is not exist.";
}