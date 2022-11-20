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

//		Google C++ Style Guide
//				CLASSES
//	- Avoid virtual method calls in constructors, and avoid initialization that can fail if you can't signal an error.
//	- A class's public API must make clear whether the class is copyable, move-only, or neither copyable nor movable.
//		Support copying and/or moving if these operations are clear and meaningful for your type.
//	- Every class's public interface must make clear which copy and move operations the class supports.
//		This should usually take the form of explicitly declaring and/or deleting the appropriate operations
//		in the public section of the declaration.
#include "Contact.h"

#include <utility>

Contact::Contact() = default;

Contact::~Contact() = default;

void Contact::set_contact(std::string first_name_v,
						  std::string last_name_v,
						  std::string nick_name_v,
						  std::string phone_number_v,
						  std::string darkest_secret_v) {
	//	A copyable type is one that can be initialized or assigned from any other object of the same type
	//	(so is also movable by definition), with the stipulation that the value of the source does not change.
	//
	//	std::unique_ptr<int> is an example of a movable but not copyable type
	//	(since the value of the source std::unique_ptr<int> must be modified during assignment to the destination).
	//
	//	int and std::string are examples of movable types that are also copyable.
	//	(For int, the move and copy operations are the same; for std::string,
	//	there exists a move operation that is less expensive than a copy.)
	this->first_name = std::move(first_name_v);
	this->last_name = std::move(last_name_v);
	this->nick_name = std::move(nick_name_v);
	this->phone_number = std::move(phone_number_v);
	this->darkest_secret = std::move(darkest_secret_v);
};
