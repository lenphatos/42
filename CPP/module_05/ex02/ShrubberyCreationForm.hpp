#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm;


class ShrubberyCreationForm : public Form {

  // Constructor & Operator & Destructor
  public:
  ShrubberyCreationForm(std::string const &target);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(ShrubberyCreationForm const &other);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

  // Getters & Setters

  // Methodes

  private:
    std::string _Target;
    void beExecute(void) const;

};

#endif
