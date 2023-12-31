#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& _name)
    : Form(_name, 145, 137) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
    : Form(ref) {
  *this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& ref) {
  if (this != &ref) {
    this->IsSigned = ref.getType();
  }
  return *this;
}

bool RobotomyRequestForm::execute(Bureaucrat const& robo) const {
  std::srand(time(NULL));

  if (beExecute() == true) {
    std::cout << "Drilling Drlling zzz" << std::endl;
    if (rand() % 2 == 0) {
      std::cout << robo.getName() << " has been robotomized successfully."
                << std::endl;
      return true;
    } else
      std::cout << "The robotomy failed." << std::endl;

  } else {
    std::cout << "The robotomy failed." << std::endl;
  }
  return false;
}
