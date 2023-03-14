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

#ifndef EX01_CONTACT_H_
#define EX01_CONTACT_H_

#include <string>

class Contact {
  private:
	std::string  first_name_,
            last_name_,
            nick_name_,
            phone_number_,
            darkest_secret_;
  public:
	Contact();
	~Contact();
	void SetFirstName(const std::string &first_name);
	void SetLastName(const std::string &last_name);
	void SetNickName(const std::string &nick_name);
	void SetPhoneNumber(const std::string &phone_number);
	void SetDarkestSecret(const std::string &darkest_secret);
	void Display(int index);
	void ShowDetails();
};

#endif // EX01_CONTACT_H