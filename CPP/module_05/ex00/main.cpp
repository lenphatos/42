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
    std::cout << *test1;
    test1->DownGrade();
    std::cout << *test1;
    test1->DownGrade();

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
  return 0;
}
