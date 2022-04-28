#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){

  Intern some;
  Bureaucrat *test = new Bureaucrat("bob", 1);

  Form *rff;
  Form *wrong_form = NULL;


  std::cout << "------WRONG_FORM--------\n" << std::endl;

  try {
    wrong_form = some.makeForm("UNKNOW", "UNKNOW");
    test->signForm(*wrong_form);
  }
  catch(std::exception const &e){
    std::cout << "ERROR : " << e.what() << std::endl;
  }

  std::cout << "\n------GOOD_FORM--------\n" << std::endl;

  rff = some.makeForm("RobotomyRequestForm", "maison");
  test->signForm(*rff);
  test->executeForm(*rff);

  return (0);
}