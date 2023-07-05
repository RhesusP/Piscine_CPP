/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:57:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 10:41:23 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "./Account.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

/* ------------- CONSTRUCTORS AND DESTRUCTOR ------------- */
Account::Account(void) {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created;" << std::endl;
}

Account::Account(int initial_deposit) {
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created;" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed;" << std::endl;
}

/* ------------- GETTERS ------------- */
int	Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

/* ------------- DISPLAY ------------- */

void Account::_displayTimestamp(void) {
	time_t		rawtime = time(NULL);
	struct tm	*timeinfo = localtime(&rawtime);

	int	year = timeinfo->tm_year + 1900;
	std::cout << "[" << year;
	int	month = timeinfo->tm_mon + 1;
	if (month < 10)
		std::cout << "0";
	std::cout << month;
	int	day = timeinfo->tm_mday;
	if (day < 10)
		std::cout << "0";
	std::cout << day << "_";
	int	hour = timeinfo->tm_hour;
	if (hour < 10)
		std::cout << "0";
	std::cout << hour;
	int	min = timeinfo->tm_min;
	if (min < 10)
		std::cout << "0";
	std::cout << min;
	int	sec = timeinfo->tm_sec;
	if (sec < 10)
		std::cout << "0";
	std::cout << sec << "]";
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* ------------- BANK OPERATIONS------------ */
void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (this->_amount - withdrawal >= 0) {
		Account::_displayTimestamp();
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount-=withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	} 
	else {
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:refused" << std::endl; 
		return (false);	
	}
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

