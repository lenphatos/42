#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
Form("ShrubberyCreationForm", 137, 145, target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
Form(other)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
  if (this != &other){
    Form::operator=(other);
  }
  return (*this);
}

void ShrubberyCreationForm::beExecute(void) const{
  std::ofstream file;
  std::string file_name = this->getTarget() + "_shrubbery";

  file.open(file_name, std::ios::out);
  if (file.bad()){
    std::cout << "Error, can't open file" << std::endl;
    return ;
  }
  file << "          \\  _  /" << std::endl;
  file << "           (\\o/)"  << std::endl;
  file << "       ---  / \\  ---" << std::endl;
  file << "            >*<" << std::endl;
  file << "           >0<@<" << std::endl;
  file << "          @<<*>><" << std::endl;
  file << "         >@>*<0<<<" << std::endl;
  file << "        >*>>@<<<@<<" << std::endl;
  file << "       >@>>0<<<*<<@<" << std::endl;
  file << "      >*>>0<<@<<<@<<<" << std::endl;
  file << "     >@>>*<<@<>*<<0<*<" << std::endl;
  file << "    >0>>*<<@<>0><<*<@<<" << std::endl;
  file << "   >*>>@><0<<*>>@><*<0<<" << std::endl;
  file << "  >@>>0<*<<0>>@<<0<<<*<@<" << std::endl;
  file << " >((*))_>0><*<0><@<<<0<*<<" << std::endl;
  file << ">((*))_>0>>@<<*<<@>><0<@<<<" << std::endl;
  file << "           \\db//" << std::endl;
  file.close();
}
