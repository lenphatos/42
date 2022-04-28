#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int   check_error(char *text, std::string s1, std::string s2)
{
  bool myfile;
  // error
  if (s1.size() == 0){
    cout << "s1 is empty..." << endl;
    return (1);
  }
  if (s2.size() == 0){
    cout << "s2 is empty..." << endl;
    return (1);
  }
  ifstream fin(text);
  if (fin.fail()) {
    cout << "file doesn't exist..." << endl;
    return (1);
  }
  return (0);
}

std::string replace_ocurrence(std::string s1, std::string s2, std::string text)
{
  size_t pos = 0;
  // replace occurence
  while (1){
    pos = text.find(s1, pos);
    if (pos > text.size())
      break ;
    text.replace(pos, s1.size(), s2);
  }
  return (text);
}

int main (int ac, char **av) {

  // check arg number
   if (ac != 4){
    cout << "Wrong number of args..." << endl;
    return (0);
  }
  std::string s1 = av[2];
  std::string s2 = av[3];

  // check all error
  if (check_error(av[1], s1, s2))
    return (0);
  // write all file in TEXT std::string
  ifstream ifs(av[1]);
  std::string text((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
  text = replace_ocurrence(s1, s2, text);

  // Create and write in FILENAME.replace
  ofstream myfile;
  std::string prefix = av[1];

  myfile.open((prefix + ".replace"),  fstream::in | fstream::out | fstream::trunc);
  myfile << text;
  myfile.close();
  return 0;
}
