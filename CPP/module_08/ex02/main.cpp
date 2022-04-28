#include "mutantstack.hpp"

int main(){

  MutantStack<int> mutant;

  mutant.push(1);
  mutant.push(2);
  mutant.push(3);
  mutant.push(4);
  mutant.push(5);
  mutant.push(6);
  mutant.push(7);
  mutant.push(8);
  mutant.push(9);


  std::cout << "---------Iterator---------" << std::endl;
  MutantStack<int>::iterator ite = mutant.end();
  for (MutantStack<int>::iterator it = mutant.begin(); it != ite; it++)
    std::cout << *it << std::endl;

  std::cout << "\n-----Const_Iterator-----" << std::endl;
  MutantStack<int>::const_iterator cite = mutant.end();

  for (MutantStack<int>::const_iterator cit = mutant.begin(); cit != cite; cit++)
    std::cout << *cit << std::endl;



  std::cout << "\n-----Rever_Iterator-----" << std::endl;
  MutantStack<int>::reverse_iterator rite = mutant.rend();

  for (MutantStack<int>::reverse_iterator rit = mutant.rbegin(); rit != rite; rit++)
    std::cout << *rit << std::endl;

  std::cout << "\n--Const_Rever_Iterator--" << std::endl;
  MutantStack<int>::const_reverse_iterator rcite = mutant.rend();

  for (MutantStack<int>::const_reverse_iterator rcit = mutant.rbegin(); rcit != rcite; rcit++)
    std::cout << *rcit << std::endl;

std::cout << "============42================" << std::endl;

    MutantStack<int>    mstack;

  mstack.push(5);
  mstack.push(99);

  std::cout << "TOP : " << mstack.top() << std::endl;

  mstack.pop();

  std::cout << "SIZE : " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);

  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator itee = mstack.end();

  ++it;
  --it;

  while(it != itee){
      std::cout << *it << std::endl;
      ++it;
  }

  std::stack<int> s(mstack);


  return (0);
}
