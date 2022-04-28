# include "iter.hpp"

/*class Awesome
  {
    public:
      Awesome( void ) : _n( 42 ) { return; }
      int get( void ) const { return this->_n; }
    private:
      int _n;
  };
  std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
  template< typename T >
  void print( T const & x ) { std::cout << x << std::endl; return; }
  int main() {
    int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];

    iter( tab, 5, print<int> );
    iter( tab2, 5, print<Awesome> );

    return 0;
  }*/

int main(){

  int array[] = {1, 2, 3, 4, 5, 6 , 7, 8, 9};

  std::cout << "=======INT_ARRAY=======" << std::endl;

  iter(array, 9, &print_something);



  std::string arrayB[] = {"bonjour", "ca va", "tfq", "Merci"};

  std::cout << "======STRING_ARRAY=====" << std::endl;

  iter(arrayB, 4, &print_something);


  return (0);
}
