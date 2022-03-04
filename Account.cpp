/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 05:45:22 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/03/02 07:47:20 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"
int Account::_nbAccounts;
int Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

	int	Account::getNbAccounts(void)
	{
		return (_nbAccounts);
	}
	int	Account::getTotalAmount(void)
	{
		return (_totalAmount);
	}
	int	Account::getNbDeposits(void)
	{
		return (_totalNbDeposits);
	}
	int	Account::getNbWithdrawals(void)
	{
		return (_totalNbWithdrawals);
	}
	void	Account::displayAccountsInfos(void)
	{
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts << ";";
		std::cout << "total:" << _totalAmount << ";";
		std::cout << "deposits:" << _totalNbDeposits << ";";
		std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
	}
	Account::~Account(void)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "closed" << std::endl;
	}
	Account::Account(int initial_deposit)
	{
		_amount = initial_deposit;
		_accountIndex = Account::_nbAccounts;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "created" << std::endl;
		++_nbAccounts;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		_totalAmount += initial_deposit;
	}
	void	Account::makeDeposit(int deposit)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		_amount += deposit;
		_totalAmount += deposit;
		++_nbDeposits;
		++_totalNbDeposits;
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	}
	bool	Account::makeWithdrawal(int withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		if (withdrawal <= _amount)
		{
			_amount -= withdrawal;
			_totalAmount -= withdrawal;
			++_totalNbWithdrawals;
			++_nbWithdrawals;
			std::cout << "amount:" << _amount << ";";
			std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		}
		else
		{
			std::cout << "withdrawl:refused" << std::endl;
			return (false);
		}
		return (true);
	}
	int	Account::checkAmount(void) const
	{
		return (_amount);
	}
	void	Account::displayStatus(void) const
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "deposits:" << _nbDeposits << ";";
		std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
	}
	void	Account::_displayTimestamp(void)
	{
		time_t	currtime;
		char	buffer[50];
		tm		*ct;

		time(&currtime);
		ct = localtime(&currtime);
		strftime(buffer, 50, "[%y%m%d_%H%M] ", ct);
		std::cout << buffer; 
	}

	Account::Account(void)
	{
		_accountIndex = Account::_nbAccounts;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "created" << std::endl;
		++_nbAccounts;
		_amount = 0;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
	}
