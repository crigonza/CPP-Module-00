/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:00:20 by crigonza          #+#    #+#             */
/*   Updated: 2023/09/07 17:59:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->_id = 0;
    std::cout << "Welcome to the mighty phonebook!!" << std::endl;
    std::cout << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "Goodbye!" << std::endl;
}

void Phonebook::add(void)
{
    std::string input;

    std::cout << "Enter first name: ";
    while (std::getline(std::cin, input) && input.empty())
        std::cout << "Field cannot be empty. Enter first name: ";
    this->_contacts[this->_id % 8].set_firstName(input);
    std::cout << "Enter last name: ";
    while (std::getline(std::cin, input) && input.empty())
        std::cout << "Field cannot be empty. Enter last name: ";
    this->_contacts[this->_id % 8].set_lastName(input);
    std::cout << "Enter nickname: ";
    while (std::getline(std::cin, input) && input.empty())
        std::cout << "Field cannot be empty. Enter nickname: ";
    this->_contacts[this->_id % 8].set_nick(input);
    std::cout << "Enter phone number: ";
    while (std::getline(std::cin, input) && input.empty())
        std::cout << "Field cannot be empty. Enter phone number: ";
    this->_contacts[this->_id % 8].set_phoneNumber(input);
    std::cout << "Enter darkest secret: ";
    while (std::getline(std::cin, input) && input.empty())
        std::cout << "Field cannot be empty. Enter darkest secret: ";
    this->_contacts[this->_id % 8].set_darkestSecret(input);
    std::cout << std::endl;
    this->_id++;
}

void Phonebook::search(void)
{
    int i;
    std::string idx;

    i = 0;
    std::cout << std::endl;
    std::cout << "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    while (i < this->_id && i != 8)
    {
        std::cout << "|         " << i + 1 << "|";
        this->print(this->_contacts[i]);
        i++;
    }
    std::cout << std::endl;
    std::cout << "Select contact number:";
    std::getline(std::cin, idx);
    while (idx.size() != 1 || idx[0] < '1' || idx[0] > this->_id + '0')
    {
        std::cout << "That entry does not exist in the phonebook, try again:";
        std::getline(std::cin, idx);
    }
    this->list(this->_contacts[std::stoi(idx) - 1]);
}

void Phonebook::print(Contact contact)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;

    firstName = contact.get_firstName();
    if (firstName.length() > 10)
        firstName = firstName.substr(0, 9) + '.';
    lastName = contact.get_lastName();
    if (lastName.length() > 10)
        lastName = lastName.substr(0, 9) + '.';
    nickName = contact.get_nick();
    if (nickName.length() > 10)
        nickName = nickName.substr(0, 9) + '.';
    std::cout << std::setw(10) << firstName << "|";
    std::cout << std::setw(10) << lastName << "|";
    std::cout << std::setw(10) << nickName << "|";
    std::cout << std::endl;
}

void Phonebook::list(Contact contact)
{
    /* if (!contact.get_firstName().length())
    {
        std::cout << "Empty entry" << std::endl;
        return;
    } */
    std::cout << "First name: " << contact.get_firstName() << std::endl;
    std::cout << "Last name: " << contact.get_lastName() << std::endl;
    std::cout << "Nickname: " << contact.get_nick() << std::endl;
    std::cout << "Phone number: " << contact.get_phoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contact.get_darkestSecret() << std::endl;
    std::cout << std::endl;
}