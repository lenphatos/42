#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
Form("RobotomyRequestForm", 45, 72, target)
{srand(time(NULL));}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
Form(other)
{srand(time(NULL));}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
  if (this != &other){
    Form::operator=(other);
  }
  return (*this);
}

void RobotomyRequestForm::beExecute(void) const{
  std::cout << "Pzzzzz Pshhhhhh Pzzzzzzzz Pshhhhhh" << std::endl;
  if((1 + (rand() % 3)) == 2)
		std::cout << this->getTarget() << " was robotomized!" << std::endl;
	else
		std::cout << "The robotization messed up..." << std::endl;
}
