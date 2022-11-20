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

#include "Book.h"

#include <utility>
#include <iostream>

#include "Contact.h"

// Move constructor
Book::Book(  const std::string &&name)
	: size(0), name(name) {}

void Book::add() {

}

//Contact Book::search() {
//	return nullptr;
//}

void Book::exit() {

}

int Book::oldest() {
	return 0;
}

void Book::start() {
	std::cout << name << std::endl;
};