/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:47:53 by crigonza          #+#    #+#             */
/*   Updated: 2023/09/25 19:19:02 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:
            std::string         _firstName;
            std::string         _lastName;
            std::string         _nick;
            std::string         _phoneNumber;
            std::string         _darkestSecret;
    public:
            Contact(void);
            ~Contact(void);
            std::string         get_firstName(void);
            std::string         get_lastName(void);
            std::string         get_nick(void);
            std::string         get_phoneNumber(void);
            std::string         get_darkestSecret(void);
            void                set_firstName(std::string fname);
            void                set_lastName(std::string lname);
            void                set_nick(std::string nick);
            void                set_phoneNumber(std::string pnumber);
            void                set_darkestSecret(std::string dsecret);
};

#endif