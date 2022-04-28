#include "ClassContact.hpp"

int main(void)
{
    int             contact_index;
    Contact         phonebook[8];
    std::string     command;

    contact_index = 0;
    std::cout << "\n\tWelcome to PhoneBook\n" << std::endl;
    std::cout << "\n[ ADD | SEARCH | EXIT ]\n" << std::endl;
    while (1)
    {

        getline(std::cin, command, '\n');
        if (command == "ADD")
        {
            if (contact_index < 8)
                phonebook[contact_index++] = addContact();
            else
                std::cout << "Phonebook is full! Brace yourself." << std::endl;
        }
        else if (command == "SEARCH")
        {
             if (contact_index > 0)
                show(phonebook, contact_index);
             else
                std::cout << "Phonebook is empty." << std::endl;
        }
        else if (command == "EXIT")
            break ;
        else if (!command.empty())
            std::cout << "Wrong Argument" << std::endl;
    }
    return (0);
}
