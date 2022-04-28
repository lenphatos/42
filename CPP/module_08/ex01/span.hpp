#ifndef SPAN_HPP
#define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>

class Span {

  private:
    int              _Min;
    int              _Max;
    unsigned int     _NbValue;
    std::vector<int> _Values;

  public:
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();
    Span &operator=(const Span &other);

    void addNumber(int);
    int  shortestSpan(void);
    int  longestSpan(void);

        template <class Iterator>
        void        addNumber(Iterator begin, Iterator end)
        {
            if (end - begin <= _NbValue){
                std::copy(begin, end, std::back_inserter(this->_Values));
                for (size_t i = 0; i < _NbValue; i++){
                  if (i == 0){
                    _Min = _Values[i];
                    _Max = _Values[i];
                  }
                  (_Values[i] < _Min) ? _Min = _Values[i] : 0;
                  (_Values[i] > _Max) ? _Max = _Values[i] : 0;

                }

            }
            else
                throw(NoEnoughSpace());
        }

    class NoEnoughSpace : public std::exception {
      public:
        virtual const char *what() const throw() {return ("No Enough Space for ADD another Number");};
    };
    class NoEnoughNumbers : public std::exception {
      public:
        virtual const char *what() const throw() {return ("No Enough Numbers");};
    };

};

#endif
