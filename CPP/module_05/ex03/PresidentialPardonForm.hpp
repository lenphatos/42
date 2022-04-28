#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
#include <fstream>
#include <iostream>

class PresidentialPardonForm;


class PresidentialPardonForm : public Form {

  // Constructor & Operator & Destructor
  public:
  PresidentialPardonForm(std::string const &target);
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(PresidentialPardonForm const &other);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

  // Getters & Setters

  // Methodes

  private:
    std::string _Target;
    void beExecute(void) const;

};

#endif
