/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:18:50 by schuah            #+#    #+#             */
/*   Updated: 2022/08/18 17:49:54 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <thread>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

struct str
{
	std::string string;
};
str		classes[100];
int		classes_max = 0;
int		classes_index = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_nbAccounts++;
	classes_max++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	classes_index++;
	classes[classes_index].string = " index:" + std::to_string(_accountIndex) + ";amount:" + std::to_string(_amount) + ";closed";
	if (classes_index == classes_max)
	{
		for (int i = classes_max; i > 0; i--)
		{
			_displayTimestamp();
			std::cout << classes[i].string << std::endl;
		}
	}
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbDeposits;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " account:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawls:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amout:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = _amount;
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex
			<< ";p_amout:" << p_amount
			<< ";deposit:" << withdrawal
			<< ";amount" << _amount
			<< ";nb_deposits:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex
			<< ";p_amout:" << p_amount
			<< "withdrawl:refused" << std::endl;
	}
	return (false);
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	rawtime;
	std::tm		*timeinfo;
	char		buffer[16];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);

	std::strftime(buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "]";
}
