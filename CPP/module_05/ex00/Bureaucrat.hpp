#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat {

  public:
    // Constructor & Operator & Destructor
    Bureaucrat(const std::string name, int level);
    virtual ~Bureaucrat();
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);

    // Getters & Setters
    std::string getName(void) const;
    int         getGrade(void) const;

    // Methodes
    void    UpGrade();
    void    DownGrade();

  private:
    std::string    _Name;
    int            _Level;

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
};

std::ostream &operator<<(std::ostream &flux, Bureaucrat const &other);

#endif
