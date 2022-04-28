#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify_from_pointer(Base *p){

  Base *ptr = NULL;
  if ((ptr = dynamic_cast<A*>(p)))
    std::cout << "TYPE from (PTR) : A" << std::endl;
  else if ((ptr = dynamic_cast<B*>(p)))
    std::cout << "TYPE from (PTR) : B" << std::endl;
  else if ((ptr = dynamic_cast<C*>(p)))
    std::cout << "TYPE from (PTR) : C" << std::endl;
}

void identify_from_reference(Base &p){

  try {
		Base &ref = dynamic_cast<A&>(p);
    (void)ref;
    std::cout << "TYPE from (REF) : A" << std::endl;
	}
	catch (std::exception e){}

  try {
    Base &ref = dynamic_cast<B&>(p);
    (void)ref;
    std::cout << "TYPE from (REF) : B" << std::endl;
  }
  catch (std::exception e){}

  try {
    Base &ref = dynamic_cast<C&>(p);
    (void)ref;
    std::cout << "TYPE from (REF) : C" << std::endl;
  }
  catch (std::exception e){}
}

Base *generate(void){

  Base *value = NULL;
  int random = rand() % 3;

  if (random == 0){
    value = new A;
    std::cout << "TYPE A GENERATED" << std::endl;
  }
  else if (random == 1){
    std::cout << "TYPE B GENERATED" << std::endl;
    value = new B;
  }
  else if (random == 2){
    std::cout << "TYPE C GENERATED" << std::endl;
    value = new C;
  }
  return (value);
}

int main(){

  srand(time(NULL));

  Base *ptr;
  for (int i = 0; i < 5; i++){

    std::cout << "\n-----[TEST : " << i << "]-----o" << std::endl; 
      ptr = generate();
      Base &ref = *ptr;
      identify_from_pointer(ptr);
      identify_from_reference(ref);

  }
  return (0);
}
