#include "Form.hpp"

// Constructor & Operator & Destructor
Form::Form(std::string const name, int execGrade, int signedGrade){
  if (signedGrade > 150 || execGrade > 150)
    throw Form::GradeTooLowExecption();
  else if (signedGrade < 1 || execGrade < 1)
    throw Form::GradeTooHightExecption();
  _Name = name;
  _Signed = false;
  _ExecGrade = execGrade;
  _SignedGrade = signedGrade;
}

Form::~Form(){}

Form::Form(Form const &other){
  if (other.getSignedGrade() > 150 || other.getExecGrade() > 150)
    throw Form::GradeTooLowExecption();
  if (other.getSignedGrade() < 1 || other.getExecGrade() < 1)
    throw Form::GradeTooHightExecption();
  _Name = other.getName();
  _Signed = other.getSigned();
  _ExecGrade = other.getExecGrade();
  _SignedGrade = other.getSignedGrade();
}

Form &Form::operator=(Form const &other){
  if (this != &other){
    _Name = other._Name;
    _Signed = other._Signed;
    _ExecGrade = other._ExecGrade;
    _SignedGrade = other._SignedGrade;
  }
  return (*this);
}

// Getters & Setters
std::string Form::getName() const {return (_Name);}
bool        Form::getSigned() const {return (_Signed);}
int         Form::getExecGrade() const {return (_ExecGrade);}
int         Form::getSignedGrade() const {return (_SignedGrade);}

// Methodes
void Form::beSigned(Bureaucrat &bureaucrat){
  if (_SignedGrade >= bureaucrat.getGrade())
    _Signed = true;
  else
    throw Form::GradeTooLowExecption();
}


//----------------------------------------------------//

// Constructor & Destructor
Form::GradeTooHightExecption::GradeTooHightExecption() throw (){}

Form::GradeTooHightExecption::~GradeTooHightExecption() throw (){}

Form::GradeTooHightExecption::GradeTooHightExecption(GradeTooHightExecption const &other) throw (){(void)other;}

Form::GradeTooHightExecption &Form::GradeTooHightExecption::operator=(GradeTooHightExecption const &other) throw (){
  (void)other;
  return (*this);
}

// Methodes
const char* Form::GradeTooHightExecption::what() const throw(){
  return ("GradeTooHightExecption");
}

//----------------------------------------------------//

Form::GradeTooLowExecption::GradeTooLowExecption() throw (){}

Form::GradeTooLowExecption::~GradeTooLowExecption() throw (){}

Form::GradeTooLowExecption::GradeTooLowExecption(GradeTooLowExecption const &other) throw (){(void)other;}

Form::GradeTooLowExecption &Form::GradeTooLowExecption::operator=(GradeTooLowExecption const &other) throw (){
  (void)other;
  return (*this);
}

// Methodes
const char* Form::GradeTooLowExecption::what() const throw(){
  return ("GradeTooLowExecption");
}

std::ostream &operator<<(std::ostream &flux, Form const &other){
  if (other.getSigned() == true)
    flux << other.getName() << " already signed.\nExec Grade requiere : " << other.getExecGrade() << "\nSign Grade require : " << other.getSignedGrade() << std::endl;
  else
    flux << other.getName() << " not signed.\nExec Grade requiere : " << other.getExecGrade() << "\nSign Grade require : " << other.getSignedGrade() << std::endl;
  return (flux);
}
