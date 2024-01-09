#include "ShrubberyCreationForm.hpp"

#define ASCII_TREES                   \
  "         &&& &&  & &&\n"           \
  "      && &\\/&\\|& ()|/ @, &&\n"   \
  "      &\\/(/&/&||/& /_/)_&/_&\n"   \
  "   &() &\\/&|()|/&\\/ '%\" & ()\n" \
  "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n" \
  "&&   && & &| &| /& & % ()& /&&\n"  \
  " ()&_---()&\\&\\|&&-&&--%---()~\n" \
  "     &&     \\|||\n"               \
  "             |||\n"                \
  "             |||\n"                \
  "             |||\n"                \
  "       , -=-~  .-^- _\n"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _name)
    : Form(_name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : Form(ref) {
  *this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& ref) {
  if (this != &ref) {
    this->IsSigned = ref.getType();
  }
  return *this;
}

bool ShrubberyCreationForm::execute(Bureaucrat const& Shrub) const {
  std::ofstream file;
  std::string filename;
  filename = Shrub.getName() + "_shrubbery";

  if (beExecute() == false) {
    std::cout << Shrub.getName()
              << "'s grade is lower than ShrubberyCreation's execute grade."
              << std::endl;
    return false;
  }

  file.open(filename.c_str());
  if (file.fail()) {
    std::cout << "check, this " << filename << " file." << std::endl;
    return false;
  }

  file << ASCII_TREES;

  return true;
}