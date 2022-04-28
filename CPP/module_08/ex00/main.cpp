#include "easyfind.hpp"
#include <vector>
#include <list>


int main(){

  std::vector<int> v;
  std::list<int>   l;

  v.push_back(1);
  v.push_back(2);
  v.push_back(5);
  v.push_back(6);
  v.push_back(77);


  l.push_back(444);
  l.push_back(412);
  l.push_back(456);
  l.push_back(54);
  l.push_back(-1);
  l.push_back(0);


  std::cout << "\n--VECTOR--" << std::endl;
  try {std::cout << "output : " << easyfind(v, -1) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  try {std::cout << "output : " << easyfind(v, 7) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  try {std::cout << "output : " << easyfind(v, 2) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  try {std::cout << "output : " << easyfind(v, 77) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}


  std::cout << "\n---LIST---" << std::endl;
  
  try {std::cout << "output : " << easyfind(l, 444) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  try {std::cout << "output : " << easyfind(l, 412) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  try {std::cout << "output : " << easyfind(l, -1) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  try {std::cout << "output : " << easyfind(l, 9999) << std::endl;}
    catch (std::exception &e){std::cout << "couldn't find value" << std::endl;}
  return (0);
}
