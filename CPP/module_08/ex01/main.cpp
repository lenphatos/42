#include "span.hpp"

int main(){
  Span first = Span(10);

  Span second = Span(first);


  try {
    first.addNumber(2);
    first.addNumber(1);
    first.addNumber(500);
    first.addNumber(10001);
    first.addNumber(15);

  }
  catch(std::exception const &e){
    std::cout << e.what() << std::endl;
  }

  Span third = Span(first);

  try {
    std::cout << "Shortest : " << first.shortestSpan() << std::endl;

  }
  catch(std::exception const &e){
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "Longest : " << first.longestSpan() << std::endl;
  }
  catch(std::exception const &e){
    std::cout << e.what() << std::endl;
  }

        std::cout << "\n-----------------------\n" << std::endl;


    Span longL = Span(10000);
    std::vector<int> V(10000, 0);
    generate(V.begin(), V.end(), rand);
    V[500] = 40;
    longL.addNumber(V.begin(), V.end());

    try {std::cout << longL.shortestSpan() << std::endl;}
    catch(const std::exception& e){std::cout << "Error : " << e.what() <<  std::endl;}
    try {std::cout << longL.longestSpan() << std::endl;}
    catch(const std::exception& e){std::cout << "Error : " << e.what() <<  std::endl;}
  return (0);
}
