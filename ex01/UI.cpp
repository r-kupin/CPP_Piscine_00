/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:35:48 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/30 19:40:35 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UI.h"

#include <iostream>
#include <iomanip>
#include <climits>

void UI::ShowGreeting() {
	std::cout <<  "Right from the" << std::endl;
	std::cout <<  "   ___   ___  _     " << std::endl;
	std::cout <<  "  / _ \\ / _ \\( )    " << std::endl;
	std::cout <<  " | (_) | | | |\\|___ " << std::endl;
	std::cout <<  "  > _ <| | | | / __|" << std::endl;
	std::cout <<  " | (_) | |_| | \\__ \\" << std::endl;
	std::cout <<  "  \\___/ \\___/  |___/" << std::endl;
	std::cout <<  "                    " << std::endl;
	std::cout << "= Freaking Flipping Crappy Awesome Phone Book =" << std::endl;
	std::cout << "Available commands: ADD, SEARCH and EXIT" << std::endl;
}

void UI::PrintAndSet(const std::string &print, std::string &get, bool &err) {
	std::cout << print;
	std::getline(std::cin, get);
	if (std::cin.rdstate() != 0) {
		std::cin.clear();
		std::cout << "Oops, something went wrong.." << std::endl;
		err = true;
	}
}

void UI::PrintAndSetInt(const std::string &print, int &get) {
	std::cout << print;
	get = std::cin.get();
	if (get == '\n') {
		get = -1;
		return;
	} else {
		get -= '0';
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

void UI::ShowExitMessage() {
	std::cout << "Farewell!" << std::endl;
}

void UI::ShowEmptyTableMessage() {
	std::cout << "No one:" << std::endl;
	std::cout << "Absolutely no one:" << std::endl;
	std::cout << "Psst! The phonebook is empty..." << std::endl;
}

void UI::ShowTableHeader() {
	ShowFormattedTableCell("ID");
	ShowFormattedTableCell("first name");
	ShowFormattedTableCell("last name");
	ShowFormattedTableCell("nick name");
	ShowFormattedTableCell("phone");
	std::cout << std::endl;
}

void UI::ShowFormattedTableCell(int data) {
	std::cout << std::setw(CELL_MAXSIZE) << std::right << data << "|";
}

void UI::ShowFormattedTableCell(const std::string &data) {
	if (data.length() > CELL_MAXSIZE) {
		std::string kDataSubstr = data.substr(0, 9) + ".";
		std::cout << std::setw(CELL_MAXSIZE) << std::right << kDataSubstr << "|";
	} else {
		std::cout << std::setw(CELL_MAXSIZE) << std::right << data << "|";
	}
}

void UI::PrintAndWaitForEnter(const std::string &print) {
	std::cout << print;
	while (true) {
		if (std::cin.get() == '\n')
			break;
	}
}
