#include <iostream>
#include <string>

using namespace std;

int main()
{
  std::string string("HI THIS IS BRAIN");

  std::string *ptr = &string;
  std::string &ref = string;

  cout << "Voici le pointeur : " << *ptr << endl;
  cout << "Voici la référence : " << ref << endl;
  return (0);
}
