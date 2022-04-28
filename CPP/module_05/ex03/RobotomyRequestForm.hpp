#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
#include <fstream>
#include <iostream>

class RobotomyRequestForm;


class RobotomyRequestForm : public Form {

  // Constructor & Operator & Destructor
  public:
  RobotomyRequestForm(std::string const &target);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(RobotomyRequestForm const &other);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

  // Getters & Setters

  // Methodes

  private:
    std::string _Target;
    void beExecute(void) const;

};

#endif
