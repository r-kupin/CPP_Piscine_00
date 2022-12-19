/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:55:54 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/03 20:55:56 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
		Description

	So, basically here we have $$ blocs of methods, broken down by types:
 		1. Defining and initializing static member variables
			When we declare a static member variable inside a class, we’re
			telling the compiler about the existence of a static member variable,
			but not actually defining it (much like a forward declaration).
			Because static member variables are not part of the individual class
			objects (they are treated similarly to global variables, and get
			initialized when the program starts), you must explicitly define the
			static member outside of the class, in the global scope.
		2. Constructors and destructor
			As far as some of the member variables are static, we can't handle
			all of them using initialisation list. Statics should be handled in
			a constructor's \ destructors {} body
		3. Getters - they show us current state of fields in "read-only" mode
			This particular ones are static, meaning they belong to the class,
			not the	object - therefore they do not require an object creation to
			get called() and, obviously can refer only to static variables which
			are "global" for all objects of a particular class
		4. Object's API, all trivial, nothing interesting
		5. The C++ standard library does not provide a proper date type.
			C++ inherits the structs and functions for date and time
			manipulation from C. To access date and time related functions and
			structures, you would need to include <ctime> header file in your
			C++ program. So yes, It is not a big sin to use C and all that goes
			with it here..
*/
#include "Account.class.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

// Defining and initializing static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors and destructor
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
				_amount(initial_deposit),
				_nbDeposits(0),
				_nbWithdrawals(0) {
	++_nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<
		"amount:" << _amount << ";" <<
		"created" << std::endl;
}

Account::~Account() {
	--_nbAccounts;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<
			  "amount:" << _amount << ";" <<
			  "closed" << std::endl;
}

//Getters
int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

// Class Display-method
// Shows Account static data altogether
//
void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" <<
		"total:" << _totalAmount << ";" <<
		"deposits:" << _totalNbDeposits << ";" <<
		"withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Actually object functional interface
//
void Account::makeDeposit(int deposit) {
	int p_amount = _amount;

	_totalAmount += deposit;
	_amount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<
		"p_amount:" << p_amount << ";" <<
		"deposit:" << deposit << ";" <<
		"amount:" << _amount << ";" <<
		"nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<
		"p_amount:" << _amount << ";" <<
		"withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	} else {
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		std::cout << withdrawal << ";" <<
			  "amount:" << _amount << ";" <<
			  "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

int Account::checkAmount() const {
	return _amount;
}

// Object Display-method
// Shows particular Account data altogether
//
void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" <<
			  "amount:" << _amount << ";" <<
			  "deposits:" << _nbDeposits << ";" <<
			  "withdrawals:" << _nbWithdrawals << std::endl;
}

// Timestamp function
//
void Account::_displayTimestamp() {
	const int kGMTYearBegin = 1900;

	std::time_t time = std::time(nullptr);

	std::cout << "[" << std::gmtime(&time)->tm_year + kGMTYearBegin <<
	std::setw(2) << std::setfill('0') << std::gmtime(&time)->tm_mon <<
	std::setw(2) << std::setfill('0') << std::gmtime(&time)->tm_mday <<
	"_" <<
	std::setw(2) << std::setfill('0') << std::gmtime(&time)->tm_hour <<
	std::setw(2) << std::setfill('0') << std::gmtime(&time)->tm_min <<
	std::setw(2) << std::setfill('0') << std::gmtime(&time)->tm_sec << "] ";
}
