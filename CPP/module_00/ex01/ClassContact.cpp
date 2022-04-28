#include "ClassContact.hpp"

Contact::Contact(){}

Contact::~Contact(){}


// GETTER
std::string Contact::getFirstName(void) {return (this->_firstName);}
std::string Contact::getLastName(void) {return (this->_lastName);}
std::string Contact::getNickname(void) {return (this->_nickname);}
std::string Contact::getLogin(void) {return (this->_login);}
std::string Contact::getPostalAddress(void){return (this->_postalAddress);}
std::string Contact::getEmailAddress(void){return (this->_emailAdress);}
std::string Contact::getPhoneNumber(void){return (this->_phoneNumber);}
std::string Contact::getBirthdayDate(void){return (this->_birthdayDate);}
std::string Contact::getFavoriteMeal(void){return (this->_favoriteMeal);}
std::string Contact::getUnderWearColor(void){return (this->_underwearColor);}
std::string Contact::getDarkestSecret(void){return (this->_darkestSecret);}
// SETTER
void        Contact::setFirstName(std::string str){this->_firstName = str;}
void        Contact::setLastName(std::string str){this->_lastName = str;}
void        Contact::setNickname(std::string str){this->_nickname = str;}
void        Contact::setLogin(std::string str){this->_login = str;}
void        Contact::setPostalAddress(std::string str) {this->_postalAddress = str;}
void        Contact::setEmailAddress(std::string str) {this->_emailAdress = str;}
void        Contact::setPhoneNumber(std::string str) {this->_phoneNumber = str;}
void        Contact::setBirthdayDate(std::string str) {this->_birthdayDate = str;}
void        Contact::setFavoriteMeal(std::string str) {this->_favoriteMeal = str;}
void        Contact::setUnderwearColor(std::string str) {this->_underwearColor = str;}
void        Contact::setDarkestSecret(std::string str) {this->_darkestSecret = str;}


Contact addContact(void)
{
    Contact     new_contact;
    std::string buffer;

    std::cout << "First name : ";
    std::cin >> buffer;
    new_contact.setFirstName(buffer);
    std::cout << "Last name : ";
    std::cin >> buffer;
    new_contact.setLastName(buffer);
    std::cout << "Nick name : ";
    std::cin >> buffer;
    new_contact.setNickname(buffer);
    std::cout << "Login : ";
    std::cin >> buffer;
    new_contact.setLogin(buffer);
    std::cout << "Postal Address : ";
    std::cin >> buffer;
    new_contact.setPostalAddress(buffer);
    std::cout << "Email Address : ";
    std::cin >> buffer;
    new_contact.setEmailAddress(buffer);
    std::cout << "Phone Number : ";
    std::cin >> buffer;
    new_contact.setPhoneNumber(buffer);
    std::cout << "Birthday : ";
    std::cin >> buffer;
    new_contact.setBirthdayDate(buffer);
    std::cout << "Favorite Meal : ";
    std::cin >> buffer;
    new_contact.setFavoriteMeal(buffer);
    std::cout << "Underwear Color : ";
    std::cin >> buffer;
    new_contact.setUnderwearColor(buffer);
    std::cout << "Darkest Secret : ";
    std::cin >> buffer;
    new_contact.setDarkestSecret(buffer);
    std::cout << std::endl << "> Contact saved <\n" << std::endl;
    return (new_contact);
}

void searchContact(Contact phonebook[], int nbr_contacts)
{
    int          index;

    std::cout << "\nEnter the index of a contact: ";
    std::cin >> index;
    std::cout << std::endl;
    if (!std::cin.good())
    {
        std::cin.clear();
        std::cout << "Argument is not digit" << std::endl;
    }

    else if (std::cin.good() && (index >= 0 && index < nbr_contacts))
    {
        std::cout << phonebook[index].getFirstName() << std::endl;
        std::cout << phonebook[index].getLastName() << std::endl;
        std::cout << phonebook[index].getNickname() << std::endl;
        std::cout << phonebook[index].getLogin() << std::endl;
        std::cout << phonebook[index].getPostalAddress() << std::endl;
        std::cout << phonebook[index].getEmailAddress() << std::endl;
        std::cout << phonebook[index].getPhoneNumber() << std::endl;
        std::cout << phonebook[index].getBirthdayDate() << std::endl;
        std::cout << phonebook[index].getFavoriteMeal() << std::endl;
        std::cout << phonebook[index].getUnderWearColor() << std::endl;
        std::cout << phonebook[index].getDarkestSecret() << std::endl;
    }
    else
    {
        std::cin.clear();
        std::cout << "Index cannot be found." << std::endl;
    }
}

static std::string setup_info(std::string str)
{
    int space;
    std::string result;

    if (str.length() > 10){
        result = str.substr(0, 9);
        result += ".";
    }
    else
    {

        space = 10 - str.length();
        for (int i = 0; i < space; i++){
            result += " ";
        }
        result += str;    
    }
    return (result);
}

void show(Contact phonebook[], int nbr_contacts)
{
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < nbr_contacts; i++)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << setup_info(phonebook[i].getFirstName());
        std::cout << "|" << setup_info(phonebook[i].getLastName());
        std::cout << "|" << setup_info(phonebook[i].getNickname()) << "|" << std::endl;
    }
    searchContact(phonebook, nbr_contacts);
}
