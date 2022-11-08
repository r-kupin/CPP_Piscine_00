/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:47:17 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/08 18:47:19 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }  else {
    for (int i = 1; i != argc; i++) {
      for (char *ptr = argv[i]; *ptr ; ptr++) {
        if (*ptr >= 'a' && *ptr <= 'z') {
          *ptr -= 'a' - 'A';
        }
        std::cout << *ptr;
      }
    }
    std::cout << std::endl;
  }
  return 0;
};
