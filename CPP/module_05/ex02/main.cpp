#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

  Bureaucrat *test = new Bureaucrat("bob", 1);
  Bureaucrat *test1 = new Bureaucrat("john", 73);
  Bureaucrat *test2 = new Bureaucrat("toby", 145);

  Form *rob = new RobotomyRequestForm("ROBOTOMY");;
  Form *shrub = new ShrubberyCreationForm("MAISON");
  Form* president = new PresidentialPardonForm("PARDON");

  std::cout << "\n-----------[ROBOTOMY]------------\n"<< std::endl;

  test1->signForm(*rob);
  test1->executeForm(*rob);
  std::cout << "------------------"<< std::endl;
  test->signForm(*rob);
  test->executeForm(*rob);

  std::cout << "\n----------[SHRUBBERY]------------\n"<< std::endl;

  test->signForm(*shrub);
  test->signForm(*shrub);
  test->executeForm(*shrub);

  std::cout << "\n----------[PRESIDENT]------------\n"<< std::endl;

  test->signForm(*president);
  test2->executeForm(*president);
  test->executeForm(*president);

  return 0;
}
