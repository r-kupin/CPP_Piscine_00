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
		0. Constructors and destructor
		1. "getters" - they show us current state of fields in "read-only" mode
		2. "display" - shows all data about this object in a pretty format
*/
#include "Account.class.hpp"


Account::Account(int initial_deposit) {

}

Account::Account(void) {

}

Account::~Account(void) {

}
//		Getters
//	This particular ones are static, meaning they belong to the class, not the
//	object - therefore they do not require an object creation to get called()
//	and, obviously can refer only to static variables which are "global" for all
//	objects of a particular class
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
// Display
void Account::displayAccountsInfos() {

}
// Actually object functional interface
void Account::makeDeposit(int deposit) {

}

bool Account::makeWithdrawal(int withdrawal) {
	return false;
}

int Account::checkAmount(void) const {
	return 0;
}

void Account::displayStatus(void) const {

}

void Account::_displayTimestamp(void) {

}
