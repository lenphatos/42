#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
Form("PresidentialPardonForm", 5, 25, target)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :
Form(other)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
  if (this != &other){
    Form::operator=(other);
  }
  return (*this);
}

void PresidentialPardonForm::beExecute(void) const{
    std::cout << this->getTarget() << " was pardonned by Zafod Beeblebrox." << std::endl;
}
