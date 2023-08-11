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
/*
		Description

		This program uses the C++ standard library to print output to the console.
 	The std::cout object is used to output text to the console. It is part of
 	the iostream library, which is included at the beginning of the program with
 	the #include <iostream> statement.
		In the if statement, the program outputs the message:
	"* LOUD AND UNBEARABLE FEEDBACK NOISE *" to the console using std::cout.
 	The << operator is used to add the message to the output stream.
 	The std::endl function is used to add a newline character to the end of the
 	output.
		In the else block, a nested loop is used to iterate over each command
	line argument passed to the program. The inner loop iterates over each
 	character in the current argument. If the character is a lowercase letter,
 	it is converted to uppercase by subtracting the difference between 'a' and
 	'A' from its ASCII value. Each character is then printed to the console
 	using std::cout.
		Finally, the std::endl function is used again to add a newline character
	to the end of the output.
*/

#include <iostream>

typedef std::string::iterator StrIt;

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }  else {
      for (int i = 1; i != argc; i++) {
          std::string s(argv[i]);
          for (size_t j = 0; j < s.size(); ++j) {
              s[j] = std::toupper(s[j]);
          }
          std::cout << s;
      }
      std::cout << std::endl;
  }
  return 0;
};
