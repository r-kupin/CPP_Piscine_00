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

Contact::Contact() = default;

Contact::~Contact() = default;


void Contact::SetFirstName(std::string &first_name) {
	first_name_ = first_name;
}

void Contact::SetLastName(std::string &last_name) {
	last_name_ = last_name;
}

void Contact::SetNickName(std::string &nick_name) {
	nick_name_ = nick_name;
}

void Contact::SetPhoneNumber(std::string &phone_number) {
	phone_number_ = phone_number;
}

void Contact::SetDarkestSecret(std::string &darkest_secret) {
	darkest_secret_ = darkest_secret;
}

void Contact::Display(int index) {

	UI::ShowFormattedTableCell(index);
	UI::ShowFormattedTableCell(first_name_);
	UI::ShowFormattedTableCell(last_name_);
	UI::ShowFormattedTableCell(nick_name_);
	UI::ShowFormattedTableCell(phone_number_);
	std::cout << std::endl;
}

void Contact::ShowDetails() {
	UI::PrintAndWaitForEnter("First Name: " + first_name_);
	UI::PrintAndWaitForEnter("Last Name: " + last_name_);
	UI::PrintAndWaitForEnter("Nick Name: " + nick_name_);
	UI::PrintAndWaitForEnter("Phone Number: " + phone_number_);
	UI::PrintAndWaitForEnter("Darkest secret: " + darkest_secret_);
}
