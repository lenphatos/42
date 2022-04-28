#include "Intern.hpp"

Form *CreateShrub(std::string const &target);
Form *CreatePresident(std::string const &target);
Form *CreateRobot(std::string const &target);

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const &other){(void)other;}

Intern &Intern::operator=(Intern const &other){
  (void)other;
  return (*this);
}

typedef Form *(*form_tab)(std::string const &target);

Form *Intern::makeForm(std::string const &form, std::string const &target){

  Form *formulaire = NULL;

  form_tab forms[] =
  {
    &CreateShrub,
    &CreatePresident,
    &CreateRobot,
  };

  std::string tab[3] = {
    "ShrubberyCreationForm",
    "PresidentialPardonForm",
    "RobotomyRequestForm"
  };

  for (int i = 0; i < 3; i++){
    if (form == tab[i]){
      formulaire = forms[i](target);
      return (formulaire);
    }
  }
  throw Intern::UnknowForm();
  return (formulaire);
}

Form *CreateShrub(std::string const &target){return (new ShrubberyCreationForm(target));};
Form *CreatePresident(std::string const &target){return (new PresidentialPardonForm(target));};
Form *CreateRobot(std::string const &target){return (new RobotomyRequestForm(target));};

Intern::UnknowForm::UnknowForm() throw (){}

Intern::UnknowForm::~UnknowForm() throw (){}

Intern::UnknowForm::UnknowForm(UnknowForm const &other) throw (){(void)other;}

Intern::UnknowForm &Intern::UnknowForm::operator=(UnknowForm const &other) throw (){
  (void)other;
  return (*this);
}

// Methodes
const char* Intern::UnknowForm::what() const throw(){
  return ("Unknow form...");
}
