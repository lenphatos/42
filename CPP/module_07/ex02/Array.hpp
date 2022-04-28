#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array {

  private:
    T           *_Array;
    unsigned int _Size;

  public:
    // Constructor & Operator & Destructor
    Array() : _Array(new T[0]), _Size(0) {}

    Array(unsigned int n) : _Array(new T[n]), _Size(n) {}

    Array(Array const &other){
      this->_Array = new T[other.size()];
      this->_Size = other.size();
      for (size_t i = 0; i < other.size(); i++)
        this->_Array[i] = other._Array[i];
    }
    ~Array(){
      delete [] _Array;
    }

    Array &operator=(Array const &other){
      if (this != &other){
        this->_Array = new T[other.size()];
        this->_Size = other.size();
        for (size_t i = 0; i < other.size(); i++)
          this->_Array[i] = other._Array[i];
      }
      return (*this);
    }
    T &operator[](unsigned int index){
      if (index > this->_Size)
        throw Error();
      return (this->_Array[index]);
    }
    // Getter;
    unsigned int size() const {return (this->_Size);}


    class Error : public std::exception {

      public:
        virtual const char *what() const throw() {return ("array index out of range.");}
    };
};

#endif
