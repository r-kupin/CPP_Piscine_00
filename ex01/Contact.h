/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:27:21 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/08 23:35:55 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		Google C++ Style Guide
//				VARIABLES
//	- Place a function's variables in the narrowest scope possible,
//	- Variables needed for if, while and for statements should normally be declared within those statements,
//			so that such variables are confined to those scopes. E.g.:
//
//					while (const char* p = strchr(str, '/')) str = p + 1;

#ifndef EX01_CONTACT_H_
#define EX01_CONTACT_H_

#include <string>

class Contact {
  private:
	std::string  first_name,
            last_name,
            nick_name,
            phone_number,
            darkest_secret;
  public:
	Contact();
	~Contact();
	Contact(const Contact&) = delete;
	void set_contact(
			std::string first_name_v,
			std::string last_name_v,
			std::string nick_name_v,
			std::string phone_number_v,
			std::string darkest_secret_v);
};

#endif // EX01_CONTACT_H_