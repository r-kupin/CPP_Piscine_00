/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:47:17 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/11 18:19:21 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
		Description
	1.Creating an object
		There are 2 ways to create an object in cpp (like in C) - on a stack
		or heap. Creating object on the stack - declaring a variable with a
		type of an object. Creating object in the heap - allocating memory with
		a *new* operator and creating a (smart)pointer to this memory area.
			Object on the stack
				PhoneBook book(*args*);
			Object in the heap
				PhoneBook* book = new PhoneBook(*args*);
					*BAD* Pointer to object,C-style
				std::unique_ptr<PhoneBook> book(new PhoneBook(*args*));
					*GOOD* Declare a smart pointer on stack and pass it the raw
						pointer (rvalue) - C++-style
	2.Calling method of created object.
		Just like structures in C - fields and method are accessible through dot
		notation the objects itself
			book.start();
		or throw the arrow notation when dealing with the pointers to objects
			book->Start();
*/
#include "PhoneBook.h"

int main() {
	PhoneBook book;
	book.Start();
	return 0;
}
