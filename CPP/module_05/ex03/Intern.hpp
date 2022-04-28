#ifndef INTERN_HPP
#define INTERN_HPP
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

  // Constructor & Operator & Destructor
  public:
    Intern();
    ~Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);

    // Getters & Setters

    // Methodes
    Form *makeForm(std::string const &form, std::string const &target);


    class UnknowForm : public std::exception {
      public:
        // Constructor & Operator & Destructor
        UnknowForm() throw ();
        virtual ~UnknowForm() throw ();
        UnknowForm(UnknowForm const &other) throw ();
        UnknowForm &operator=(UnknowForm const &other) throw ();
        // Methodes
        virtual const char* what() const throw();

    };
};

#endif
