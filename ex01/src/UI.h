/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:40:51 by rokupin           #+#    #+#             */
/*   Updated: 2022/11/30 19:40:53 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_UI_H
#define EX01_UI_H

#include <string>

#include "Book.h"

struct UI {
	static const int kCellMaxsize = 10;
//		Prints message to std::cout and reads a line from std::cin
//		@param print - input - message to print
//		@param get - output - line, that we got from std::cin
//		@param err - output - error flag, set if read failed
		static void PrintAndSetLine(const std::string &print, std::string &get,
									bool &err);
//		Prints message to std::cout and reads a int from std::cin
//		@param print - input - message to print
//		@param get - output - int, that we got from std::cin
		static void PrintAndSetInt(const std::string &print, int &get);
//		Print message and wait for ENTER press
//		@param print - input - message to print
		static void PrintAndWaitForEnter(const std::string &print);
		static void ShowFormattedTableCell(int data);
		static void ShowFormattedTableCell(const std::string &data);
		static void	ShowGreeting();
		static void	ShowEmptyTableMessage();
		static void	ShowTableHeader();
		static void	ShowExitMessage();
};

#endif //EX01_UI_H
