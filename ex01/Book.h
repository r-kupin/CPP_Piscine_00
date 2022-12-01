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
/*
		Google C++ Style Guide
				HEADERS
	- Header files should be self-contained (compile on their own) and end in .h
	- All header files should have #define guards to prevent multiple inclusion.
	- The format of the symbol name should be <PROJECT>_<PATH>_<FILE>_H_.
	- Include What You Use
	- Avoid using forward declarations where possible. Instead, include the
 		headers you need.
	- Include headers in the following order:
		Related header to implement or test
		C system headers ( headers in angle brackets with the .h extension)
		C++ standard library headers (without file extension)
		other libraries' headers
		your project's headers.
				CONSTRUCTORS
	- Do not define implicit conversions. Use the explicit keyword for
 		conversion operators and single-argument constructors.
				CLASSES
	- Avoid virtual method calls in constructors, and avoid initialization that
 		can fail if you can't signal an error.
	- A class's public API must make clear whether the class is copyable,
 		move-only, or neither copyable nor movable. Support copying and/or
 		moving if these operations are clear and meaningful for your type.
	- Every class's public interface must make clear which copy and move
 		operations the class supports. This should usually take the form of
 		explicitly declaring and/or deleting the appropriate operations in the
 		public section of the declaration.
	- Make classes' data members private, unless they are constants
 	- The order of sections in a class is:
 		public:
 		protected:
 		private:
	- Omit sections that would be empty.
	- Within each section, prefer grouping similar kinds of declarations
 		together, wit the following order:
    		Types and type aliases (typedef, using, enum, nested structs and
    			classes, and friend types)
    		Static constants
    		Factory functions
    		Constructors and assignment operators
    		Destructor
    		All other functions (static and non-static member functions, and
    			friend functions)
    		Data members (static and non-static)
	- Do not put large method definitions inline in the class definition.
 		Usually, only trivial or performance-critical, and very short, methods
 		may be defined inline
				COMMENTS
 	- Types of things to mention in comments at the function declaration:
		> What the inputs and outputs are. If function argument names are
			provided in `backticks`, then code-indexing tools may be able to
			present the documentation better.
		> For class member functions: whether the object remembers reference or
			pointer arguments beyond the duration of the method call. This is
			quite common for pointer/reference arguments to constructors.
		> For each pointer argument, whether it is allowed to be null and what
			happens if it is.
		> For each output or input/output argument, what happens to any state
			that argument is in. (E.g. is the state appended to or overwritten?).
		> If there are any performance implications of how a function is used.

		Description

	1.Declaring a class
		Declaration of fields (private variables) of a class goes after a
			*private:* keyword
		Declaration of methods (external interface) of a class goes after a
			*public:* keyword
	2.Declaring a class's fields
		*::* are used in C++ as a scope resolution operator. It tells compiler
			where to look for the name specified after it.
		std - is a standard namespace, collection of related names or
			identifiers (functions, class, variables) which helps to separate
			these identifiers from similar identifiers in other
			(::namespace::identifier) or the global namespace(::identifier).
		<Contact, BOOK_MAXSIZE> - is a template. In the std::array declaration
			specified like this:
						template<typename _Tp, std::size_t _Nm>
	3.Class's constructors declaration
		To customize how a class initializes its members, or to invoke functions
			when an object of your class is created, define a constructor.
			A constructor has the same name as the class and no return value.
			You can define as many overloaded constructors as needed to customize
			initialization in various ways. Typically, constructors have
			public accessibility so that code outside the class definition or
			inheritance hierarchy can create objects of the class. But you can
			also declare a constructor as protected or private.
		explicit -  prevents the compiler from using that constructor for
			implicit conversions. Implicit conversions allow an object of one
			type (called the source type) to be used where a different type
			(called the destination type) is expected, such as when passing an
			int argument to a function that takes a double parameter. That can
			hide bugs.
*/

#ifndef EX01_BOOK_H_
#define EX01_BOOK_H_

#include <array>
#include <string>

#include "Contact.h"
#include "UI.h"

#define BOOK_MAXSIZE 8

class Book {
 public:
	Book();
	~Book();

	void 	Start();
 private:
	void 	AddModify();
	void	Search();

	std::array<Contact, BOOK_MAXSIZE> contacts_{};
	int 	size_;
	int		oldest_modified_;
};

#endif  // EX01_BOOK_H_
