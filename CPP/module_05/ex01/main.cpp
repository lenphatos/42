#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(){

  Bureaucrat *test = new Bureaucrat("bob", 1);
  Bureaucrat *test1 = new Bureaucrat("john", 149);

  std::cout << *test;
  std::cout << *test1;

  std::cout << "----------------------------------" << std::endl;

  try {
    test->UpGrade();
  }
  catch(std::exception const& e){
    std::cout << *test;
    std::cerr << "ERROR :" << e.what() << std::endl;
  }

  std::cout << "----------------------------------" << std::endl;


  try {
    test1->DownGrade();
    std::cout << *test1;
    test1->DownGrade();
    std::cout << *test1;
  }
  catch(std::exception const& e){
    std::cout << *test1;
    std::cerr << "ERROR : " << e.what() << std::endl;
  }
  std::cout << "----------------------------------" << std::endl;

  // ----------------------------------------------- //

  try {
    std::cout << *test;
    test->DownGrade();
    std::cout << "[-] " << *test;
    test->DownGrade();
    std::cout << "[-] " << *test;
    test->UpGrade();
    std::cout << "[+] " << *test;
  }
  catch(std::exception const& e){
    std::cout << *test;
    std::cerr << "ERROR : " << e.what() << std::endl;
  }
  std::cout << "----------------------------------" << std::endl;


  // ----------------------------------------------- //

  try {
    std::cout << *test1;
    test1->UpGrade();
    std::cout << "[+] " << *test1;
    test1->UpGrade();
    std::cout << "[+] " << *test1;
    test1->UpGrade();
    std::cout << "[+] " << *test1;
    test1->DownGrade();
    std::cout << "[-] " << *test1;

  }
  catch(std::exception const& e){
    std::cout << *test1;
    std::cerr << "ERROR : " << e.what() << std::endl;
  }

  std::cout << "\n//* ======================================= *\\\\\n" << std::endl;

  Form *form;
  Form *form1;

  try {
    std::cout << "\n###-----FORMULAIRE_TOO_HIGHT------###\n" << std::endl;
    form = new Form("FORMULAIRE_TOO_HIGHT", 5, 0);
  }
  catch (std::exception const& e) {
    std::cerr << "ERROR : " << e.what() << std::endl;
  }

  try {
    std::cout << "\n###------FORMULAIRE_TOO_LOW-------###\n" << std::endl;
    form1 = new Form("FORMULAIRE_TOO_LOW", 5, 151);
  }
  catch (std::exception const& e) {
    std::cerr << "ERROR : " << e.what() << std::endl;
  }

  try {
    std::cout << "\n###------FORMULAIRE_CORRECT-------###\n" << std::endl;
    form1 = new Form("FORMULAIRE_CORRECT", 5, 149);
    std::cout << *form1;
    std::cout << "----------------------------------" << std::endl;
    test1->signForm(*form1);
    std::cout << "----------------------------------" << std::endl;
    std::cout << *form1;
    std::cout << "----------------------------------" << std::endl;
    test1->signForm(*form1);
    std::cout << "----------------------------------" << std::endl;
  }
  catch (std::exception const& e) {
    std::cerr << "ERROR : " << e.what() << std::endl;
  }

  try {
    std::cout << "\n###---FORMULAIRE_CANT_BE_SIGNED---###\n" << std::endl;
    form1 = new Form("FORMULAIRE_CANT_BE_SIGNED", 5, 15);
    std::cout << *form1;
    std::cout << "----------------------------------" << std::endl;
    test1->signForm(*form1);
  }
  catch (std::exception const& e) {
    std::cerr << "ERROR : " << e.what() << std::endl;
  }

  return 0;
}
