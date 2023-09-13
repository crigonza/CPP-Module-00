/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:42:55 by crigonza          #+#    #+#             */
/*   Updated: 2023/07/25 19:42:55 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::get_firstName(void)
{
    return (this->_firstName);
}

std::string Contact::get_lastName(void)
{
    return (this->_lastName);
}

std::string Contact::get_nick(void)
{
    return (this->_nick);
}

std::string Contact::get_phoneNumber(void)
{
    return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret(void)
{
    return (this->_darkestSecret);
}

void    Contact::set_firstName(std::string fname)
{
    this->_firstName = fname;
}
void    Contact::set_lastName(std::string lname)
{
    this->_lastName = lname;
}

void    Contact::set_nick(std::string nick)
{
    this->_nick = nick;
}

void    Contact::set_phoneNumber(std::string pnumber)
{
    this->_phoneNumber = pnumber;
}

void    Contact::set_darkestSecret(std::string dsecret)
{
    this->_darkestSecret = dsecret;
}
