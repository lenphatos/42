#include <iostream>
#include <cstdlib>

struct Data {
  int         n;
  std::string s1;
  std::string s2;
};

void *check(void){

  Data *data = new Data();

  data->s1 = "bonjour";
  data->s2 = "aurevoir";
  data->n = 123456789;

  return (data);
}

std::string random_string(){

  char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
                      ,'o','p','q','r','s','t','u','v','w','x','y','z'};
  std::string ran = "";
  for (int i = 0; i < 8; i++)
    ran = ran + letters[rand() % 26];
  return (ran);
}

void *serialize(void){

  Data *data = new Data();

  data->s1 = random_string();
  data->s2 = random_string();
  data->n = rand() % 214783647;

  return (data);
}

Data *deserialize(void *raw){

  return (reinterpret_cast<Data*>(raw));
}

int main(){

  srand(time(NULL));

  void *raw = serialize();



  Data *data = deserialize(raw);



  std::cout << data->s1 << std::endl;
  std::cout << data->n << std::endl;
  std::cout << data->s2 << std::endl;
  
  std::cout << "-------------------" << std::endl;

  void *raw1 = check();

  Data *data1 = deserialize(raw1);

  std::cout << data1->s1 << std::endl;
  std::cout << data1->n << std::endl;
  std::cout << data1->s2 << std::endl;

  delete data;

  return (0);
}
