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
/*
		Description
	There are numerous ways to get input in c++:
 	$var = std::cin.get() - reads 1 character
 	std::getline(std::cin, $var) - reads 1 line
	std::cin >> $var - reads the first word from standard input,
	in particular case - assigns it to variable. If variable type doesnt match -
 	let's say $var is an int, and we got a "asdf" from cin - it sets internal
 	error code and stops execution. If there were more than 1 word - the rest of
 	the word are left in a buffer, and will be taken out on the next calls to cin.

 	here's are a couple of methods to solve this issues;
 	std::cin.rdstate() - returns internal state indicator, if not 0 - something
		went wrong. cin>> also returns the status of read operation.
	std::cin.clear() - sets internal state indicator to 0 (cleaning the errors)
 	std::cin.ignore(INT_MAX, '\n') - takes INT_MAX chars from the buffer up to
 		'\n' and discards them.

 	Every time you put something on input (stream) you leave at the end white
 	character which is ENTER ('\n'). You have to somehow enter values to console.
 	So after reading the user input you should do the following:
 	- cin characteristics is that it ignores whitespace, so when you are reading
		information from cin, the newline character '\n' doesn't matter. It gets
		ignored.
	- getline() gets the entire line up to the newline character ('\n'), and
		when the newline char is the first thing the getline function gets '\n',
		and that's all to get. You extract newline character that was left on
		stream, and getline stops. That's why you have no input is you call getline()
		after cin>>.
	So in order to fix it is to always invoke cin.ignore(); each time you use
 	cin to get any value if you are ever going to use getline() inside your
 	program.
*/

#include "UI.h"

#include <iostream>
#include <iomanip>
#include <climits>

// Prints the message
// Reads the line
// if something went wrong - clears the error in the stream, prints error message
// 	and sets the error flag
std::string UI::PrintAndGetLine(const std::string &print, bool &err) {
	std::string get;

	std::cout << print;
	std::getline(std::cin, get);
	if (std::cin.rdstate() != 0) {
		std::cin.clear();
		std::cout << "Oops, something went wrong.." << std::endl;
		err = true;
	}
	return (get);
}
// Prints the message
// Reads 1 char
// If it is '\n' - returns invalid number,so the prompt will be printed again
// If not - tries to convert ascii to int digit (luckily we are bounded from 1 to 8)
// ignore - just to remove '\n' if it's get left
int UI::PrintAndGetInt(const std::string &print) {
	int get;

	std::cout << print;
	get = std::cin.get();
	if (get == '\n') {
		get = -1;
	} else {
		get -= '0';
		std::cin.ignore(INT_MAX, '\n');
	}
	return (get);
}
// Here we do not need to ignore(), cause '\n' is what we are taking
void UI::PrintAndWaitForEnter(const std::string &print) {
	std::cout << print;
	while (true) {
		if (std::cin.get() == '\n')
			break;
	}
}

void UI::ShowFormattedTableCell(int data) {
	std::cout << std::setw(UI::kCellMaxsize) << std::right << data << "|";
}

void UI::ShowFormattedTableCell(const std::string &data) {
	if (data.length() > UI::kCellMaxsize) {
		std::string kDataSubstr = data.substr(0, 9) + ".";
		std::cout << std::setw(UI::kCellMaxsize) << std::right << kDataSubstr << "|";
	} else {
		std::cout << std::setw(UI::kCellMaxsize) << std::right << data << "|";
	}
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
