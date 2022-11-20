/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Book.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:27:33 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/08 23:27:35 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		Google C++ Style Guide
//				HEADERS
//	- Header files should be self-contained (compile on their own) and end in .h.
//	- All header files should have #define guards to prevent multiple inclusion.
//	- The format of the symbol name should be <PROJECT>_<PATH>_<FILE>_H_.
//	- Include What You Use
//	- Avoid using forward declarations where possible. Instead, include the headers you need.
//	- Include headers in the following order:
//		Related header to implement or test
//		C system headers (more precisely: headers in angle brackets with the .h extension)
//		C++ standard library headers (without file extension)
//		other libraries' headers
//		your project's headers.
//				CONSTRUCTORS
//	- Do not define implicit conversions. Use the explicit keyword for conversion operators and single-argument
//		constructors.

//		Description
//	1.Declaring a class
//		Declaration of fields (private variables) of a class goes after a *private:* keyword
//		Declaration of methods (external interface) of a class goes after a *public:* keyword
//	2.Declaring a class's fields
//		*::* are used in C++ as a scope resolution operator. It tells compiler where to look
//			for the name specified after it.
//		std - is a standard namespace, collection of related names or identifiers
//		 	(functions, class, variables) which helps to separate these identifiers from
//		 	similar identifiers in other (::namespace::identifier)
//		 	or the global namespace(::identifier).
//		<Contact, BOOK_MAXSIZE> - is a template. In the std::array declaration specified like
//			this:
//						template<typename _Tp, std::size_t _Nm>
//	3.Class's constructors declaration
//		To customize how a class initializes its members, or to invoke functions when an
//			object of your class is created, define a constructor. A constructor has the same name
//			as the class and no return value. You can define as many overloaded constructors as
//			needed to customize initialization in various ways. Typically, constructors have
//			public accessibility so that code outside the class definition or inheritance
//			hierarchy can create objects of the class. But you can also declare a constructor
//			as protected or private.
//		explicit -  prevents the compiler from using that constructor for implicit conversions.
//			Implicit conversions allow an object of one type (called the source type) to be used
//			where a different type (called the destination type) is expected, such as when
//			passing an int argument to a function that takes a double parameter. That can hide
//			bugs.
//		&& - Specifies, that given argument must be an rvalue reference. Constructor that uses &&-argument
//			is called "Move constructor",  enables the resources owned by an rvalue object to be moved into an
//			lvalue without copying
//


#ifndef EX01_BOOK_H_
#define EX01_BOOK_H_

#include <array>
#include <string>

#include "Contact.h"

#define BOOK_MAXSIZE 8

class Book {
	private:
		std::string name;
		std::array<Contact, BOOK_MAXSIZE> contacts{};
		int size;
	public:
		explicit Book(const std::string &&name);
		void 	start();
		void 	add();
//		Contact search();
		int 	oldest();
		void 	exit();
};

#endif // EX01_BOOK_H_
