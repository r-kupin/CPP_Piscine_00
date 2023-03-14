/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:06:07 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/11 18:20:05 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

#include <iostream>
#include <iomanip>

#include "UI.h"

Contact::Contact() {};

Contact::~Contact() {};


void Contact::SetFirstName(const std::string &first_name) {
	first_name_ = first_name;
}

void Contact::SetLastName(const std::string &last_name) {
	last_name_ = last_name;
}

void Contact::SetNickName(const std::string &nick_name) {
	nick_name_ = nick_name;
}

void Contact::SetPhoneNumber(const std::string &phone_number) {
	phone_number_ = phone_number;
}

void Contact::SetDarkestSecret(const std::string &darkest_secret) {
	darkest_secret_ = darkest_secret;
}
//	shows user data in table-aligned format
//
void Contact::Display(int index) {

	UI::ShowFormattedTableCell(index);
	UI::ShowFormattedTableCell(first_name_);
	UI::ShowFormattedTableCell(last_name_);
	UI::ShowFormattedTableCell(nick_name_);
	UI::ShowFormattedTableCell(phone_number_);
	std::cout << std::endl;
}
//	shows detailed user info line-by-line, and each time waits for ENTER to show
//	next line
//
void Contact::ShowDetails() {
	UI::PrintAndWaitForEnter("First Name: " + first_name_);
	UI::PrintAndWaitForEnter("Last Name: " + last_name_);
	UI::PrintAndWaitForEnter("Nick Name: " + nick_name_);
	UI::PrintAndWaitForEnter("Phone Number: " + phone_number_);
	UI::PrintAndWaitForEnter("Darkest secret: " + darkest_secret_);
}
