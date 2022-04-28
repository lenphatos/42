#include "Whatever.hpp"

int main(){

  int s_a = 1, s_b = 2;

  std::cout << "=======SWAP=======" << std::endl;
  std::cout << "-----INT------" << std::endl;
  std::cout << "Value of A : " << s_a << std::endl;
  std::cout << "Value of B : " << s_b << std::endl;
  std::cout << "--------------" << std::endl;
  swap(s_a, s_b);
  std::cout << "Value of A : " << s_a << std::endl;
  std::cout << "Value of B : " << s_b << std::endl;

  float fa = 1.1, fb = 2.2;

  std::cout << "\n----FLOAT-----" << std::endl;
  std::cout << "Value of A : " << fa << std::endl;
  std::cout << "Value of B : " << fb << std::endl;
  std::cout << "--------------" << std::endl;
  swap(fa, fb);
  std::cout << "Value of A : " << fa << std::endl;
  std::cout << "Value of B : " << fb << std::endl;



  std::cout << "\n\n=======MIN=======" << std::endl;

  int min_a = 1, min_b = 2;

  std::cout << "-----INT------" << std::endl;
  std::cout << "Value of A : " << min_a << std::endl;
  std::cout << "Value of B : " << min_b << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Value of MIN : " << min(min_a, min_b) << std::endl;

  float min_fa = 1.0, min_fb = 1.0;

  std::cout << "\n----FLOAT-----" << std::endl;
  std::cout << "Value of A : " << min_fa << std::endl;
  std::cout << "Value of B : " << min_fb << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Value of MIN : " << min(min_fa, min_fb) << std::endl;

  double min_da = 57.12, min_db = 23.34;

  std::cout << "\n----DOUBLE----" << std::endl;
  std::cout << "Value of A : " << min_da << std::endl;
  std::cout << "Value of B : " << min_db << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Value of MIN : " << min(min_da, min_db) << std::endl;


  std::cout << "\n\n=======MAX=======" << std::endl;

  int max_a = 1, max_b = 2;

  std::cout << "-----INT------" << std::endl;
  std::cout << "Value of A : " << max_a << std::endl;
  std::cout << "Value of B : " << max_b << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Value of MAX : " << max(max_a, max_b) << std::endl;

  float max_fa = 1.0, max_fb = 1.0;

  std::cout << "\n----FLOAT-----" << std::endl;
  std::cout << "Value of A : " << max_fa << std::endl;
  std::cout << "Value of B : " << max_fb << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Value of MAX : " << max(max_fa, max_fb) << std::endl;

  double max_da = 57.12, max_db = 23.34;

  std::cout << "\n----DOUBLE----" << std::endl;
  std::cout << "Value of A : " << max_da << std::endl;
  std::cout << "Value of B : " << max_db << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Value of MAX : " << max(max_da, max_db) << std::endl;


  std::cout << "\n\n========42=======" << std::endl;
    int a = 2;
    int b = 3;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  return (0);
}
