/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:06:07 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/11 18:20:05 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 		Google C++ Style Guide
			VARIABLES
	- Initialize variables in the declaration.
 	- Place a function's variables in the narrowest scope possible,
	- Variables needed for if, while and for statements should normally be
		 declared within those statements, so that such variables are confined
		 to those scopes. E.g.:

					while (const char* p = strchr(str, '/')) str = p + 1;
			FUNCTIONS
	- Prefer using return values over output parameters: they improve
		readability, and often provide the same or better performance.
	- Prefer to return by value or, failing that, return by reference.
 		Avoid returning a pointer unless it can be null.
	- Use overloaded functions (including constructors) only if a reader looking
		at a call site can get a good idea of what is happening without having
		to first figure out exactly which overload is being called.
	- Default arguments are allowed on non-virtual functions when the default is
		guaranteed to always have the same value.
			NAMING
	- The names of variables (including function parameters) and data members
 		are all lowercase, with underscores between words. Data members of
 		classes (but not structs) additionally have trailing underscores.
 			std::string table_name;
	- Data members of classes, both static and non-static, are named like
 		ordinary nonmember variables, but with a trailing underscore.
			std::string table_name_;
	- Variables declared constexpr or const, and whose value is fixed for the
		duration of the program, are named with a leading "k" followed by mixed
		case. Underscores can be used as separators in the rare cases where
		capitalization cannot be used for separation. For example:
			const int kDaysInAWeek = 7;
			const int kAndroid8_0_0 = 24;
	- Regular functions have mixed case; accessors and mutators may be named
 		like variables. Ordinarily, functions should Start with a capital letter
 		and have a capital letter for each new word.
			AddTableEntry();
	- Namespace names are all lower-case, with words separated by underscores
 	- Enumerators should be named like constants
 			COMMENTS
	- Function Definitions: if there is anything tricky about how a function
 		does its job, the function definition should have an explanatory comment.
 		For example, in the definition comment you might describe any coding
 		tricks you use, give an overview of the steps you go through, or explain
 		why you chose to implement the function in the way you did rather than
 		using a viable alternative. For instance, you might mention why it must
 		acquire a lock for the first half of the function but why it is not
 		needed for the second half.
		Note you should not just repeat the comments given with the function
		declaration, in the .h file or wherever. It's okay to recapitulate
		briefly what the function does, but the focus of the comments should be
		on how it does it.


		Description
	1. Variables in constructor are initialized with  the member initialization
		list. In contrary to assignment - in the constructor's {} body - must be
		used  in order for a program to compile:
			1. When initializing a reference member
			2. When initializing a const member
			3. When invoking a base or member class constructor with a set of
				arguments
			4. A few efficiency cases.
				Here the program is correct w/o member initialization list)
	2. Destructor is set to default explicitly
 */
#include "Book.h"

Book::Book()
	: size_(0), oldest_modified_(0) {}

Book::~Book() = default;

//	Main method. Shows the prompt and handles the received commands.
//	bool err - error flag, as far as we will uncower exceptions a bit later..
//
void Book::Start() {
	const std::string kPromptMessage = "Enter your command:";
	bool err = false;

	UI::ShowGreeting();
	for (std::string usr_input;
		 usr_input != "EXIT";
		 UI::PrintAndGetLine(kPromptMessage, err)) {
		if (err) {
			return;
		} else if (usr_input == "ADD") {
			AddModify();
		} else if (usr_input == "SEARCH") {
			Search();
		}
	}
	UI::ShowExitMessage();
}

//	Performs addition / altering of a user field by field
//	Static_cast conversion between types using a combination of implicit and
//		user-defined conversions. Basically redundant, but -WWW compilation flags
//		enforces an explicit cast, and write static_cast<int>(size_t) is one of
//		the C++-ish ways to say (int)size_t
//
//
void Book::AddModify() {
	std::string input;
	bool err = false;

	if (oldest_modified_ >= static_cast<int>(contacts_.size()))
		oldest_modified_ = 0;
	if (size_ < static_cast<int>(contacts_.size()))
		size_++;
	input = UI::PrintAndGetLine("Enter first name:", err);
	if (err)
		return;
	contacts_.at(oldest_modified_).SetFirstName(input);
	input = UI::PrintAndGetLine("Enter last name:", err);
	if (err)
		return;
	contacts_.at(oldest_modified_).SetLastName(input);
	input = UI::PrintAndGetLine("Enter nick name:", err);
	if (err)
		return;
	contacts_.at(oldest_modified_).SetNickName(input);
	input = UI::PrintAndGetLine("Enter phone number:", err);
	if (err)
		return;
	contacts_.at(oldest_modified_).SetPhoneNumber(input);
	input = UI::PrintAndGetLine("Enter darkest secret:", err);
	if (err)
		return;
	contacts_.at(oldest_modified_).SetDarkestSecret(input);
	++oldest_modified_;
}

//	shows all existing users in a table, then asks for an ID to show
//		detailed user info
//
void Book::Search() {
	const std::string kPromptMessage = "Enter contact ID to see the details:";
	const std::string kErrorMessage = "Please enter valid ID (see the table):";
	int ID_to_show;

	if (size_ == 0) {
		UI::ShowEmptyTableMessage();
	} else {
		UI::ShowTableHeader();
		for (int i = 0; i < size_; ++i) {
			contacts_.at(i).Display(i + 1);
		}
		ID_to_show = UI::PrintAndGetInt(kPromptMessage);
		while (ID_to_show <= 0 || ID_to_show > size_)
			ID_to_show = UI::PrintAndGetInt(kErrorMessage);
		contacts_.at(ID_to_show - 1).ShowDetails();
	}
}
