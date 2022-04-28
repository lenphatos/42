#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  public:
    // Constructor & Operator & Destructor
    Form(std::string const name, int execGrade, int signedGrade);
    ~Form();
    Form(Form const &other);
    Form &operator=(Form const &other);

    // Getters & Setters
    std::string getName() const;
    bool        getSigned() const;
    int         getExecGrade() const;
    int         getSignedGrade() const;

    // Methodes
    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHightExecption : public std::exception {
      public:
        // Constructor & Operator & Destructor
        GradeTooHightExecption() throw ();
        virtual ~GradeTooHightExecption() throw ();
        GradeTooHightExecption(GradeTooHightExecption const &other) throw ();
        GradeTooHightExecption &operator=(GradeTooHightExecption const &other) throw ();
        // Methodes
        virtual const char* what() const throw();

    };
    class GradeTooLowExecption : public std::exception {
      public:
        // Operator & Destructor
        GradeTooLowExecption() throw ();
        virtual ~GradeTooLowExecption() throw ();
        GradeTooLowExecption(GradeTooLowExecption const &other) throw ();
        GradeTooLowExecption &operator=(GradeTooLowExecption const &other) throw ();
        // Methodes
        virtual const char* what() const throw();
    };

  private:
    std::string   _Name;
    bool          _Signed;
    int           _ExecGrade;
    int           _SignedGrade;
};

std::ostream &operator<<(std::ostream &flux, Form const &other);


#endif
