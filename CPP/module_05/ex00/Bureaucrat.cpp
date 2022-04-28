#include "Bureaucrat.hpp"

// Operator & Constructor & Destructor
Bureaucrat::Bureaucrat(std::string const name, int level){
  if (level > 150)
    throw Bureaucrat::GradeTooLowExecption();
  if (level < 1)
    throw Bureaucrat::GradeTooHightExecption();
  _Name = name;
  _Level = level;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _Name(other._Name), _Level(other._Level){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
  if (this != &other){
    _Name = other.getName();
    _Level = other.getGrade();
  }
  return (*this);
}

// Getters & Setters
std::string   Bureaucrat::getName(void) const {return (_Name);}
int           Bureaucrat::getGrade(void) const {return (_Level);}

// Methodes

void Bureaucrat::UpGrade(){
  if ((_Level - 1) < 1)
    throw Bureaucrat::GradeTooHightExecption();
  _Level -= 1;
}
void Bureaucrat::DownGrade(){
  if ((_Level + 1) > 150)
    throw Bureaucrat::GradeTooLowExecption();
  _Level += 1;
}

//----------------------------------------------------//

// Constructor & Destructor
Bureaucrat::GradeTooHightExecption::GradeTooHightExecption() throw (){}

Bureaucrat::GradeTooHightExecption::~GradeTooHightExecption() throw (){}

Bureaucrat::GradeTooHightExecption::GradeTooHightExecption(GradeTooHightExecption const &other) throw (){(void)other;}

Bureaucrat::GradeTooHightExecption &Bureaucrat::GradeTooHightExecption::operator=(GradeTooHightExecption const &other) throw (){
  (void)other;
  return (*this);
}

// Methodes
const char* Bureaucrat::GradeTooHightExecption::what() const throw(){
  return ("GradeTooHightExecption...");
}

//----------------------------------------------------//

Bureaucrat::GradeTooLowExecption::GradeTooLowExecption() throw (){}

Bureaucrat::GradeTooLowExecption::~GradeTooLowExecption() throw (){}

Bureaucrat::GradeTooLowExecption::GradeTooLowExecption(GradeTooLowExecption const &other) throw (){(void)other;}

Bureaucrat::GradeTooLowExecption &Bureaucrat::GradeTooLowExecption::operator=(GradeTooLowExecption const &other) throw (){
  (void)other;
  return (*this);
}

// Methodes
const char* Bureaucrat::GradeTooLowExecption::what() const throw(){
  return ("GradeTooLowExecption...");
}

std::ostream &operator<<(std::ostream &flux, Bureaucrat const &other){
  flux << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
  return (flux);
}
