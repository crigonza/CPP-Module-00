/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:36:37 by crigonza          #+#    #+#             */
/*   Updated: 2023/09/07 20:42:45 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_amount = initial_deposit;
    this->_accountIndex = this->getNbAccounts();
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->checkAmount();
    std::cout << ";created" << std::endl;
    _nbAccounts++;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount" << this->checkAmount();
    std::cout << ";closed" << std::endl;
}

int     Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int     Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int     Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts();
    std::cout << ";total:" << Account::getTotalAmount();
    std::cout << ";desposits:" << Account::getNbDeposits();
    std::cout << ";withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl; 
}

void    Account::_displayTimestamp(void)
{
    std::time_t  date;

    date = time(nullptr);
    std::cout << std::put_time(localtime(&date), "[%Y%m%d_%H%M%S]");
}

void    Account::makeDeposit(int deposit)
{
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << "p_amount" << this->_amount;
    std::cout << ";deposit:" << deposit;
    this->_amount += deposit;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    this->_nbWithdrawals++;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal;
    this->_amount -= withdrawal;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    return (true);
}

int     Account::checkAmount(void) const
{
    return(this->_amount);
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->checkAmount();
    std::cout << ":deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}