/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:03:39 by crigonza          #+#    #+#             */
/*   Updated: 2023/07/28 20:10:06 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook   phone;
    std::string cmd;

    while (cmd != "EXIT")
    {
        std::cout << "Insert command[ADD, SEARCH or EXIT]>>";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            phone.add();
        if (cmd == "SEARCH")
            phone.search();
    }
    std::cout << std::endl;
    return (0);
}