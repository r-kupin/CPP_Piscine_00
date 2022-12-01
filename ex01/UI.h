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

#define CELL_MAXSIZE 10

class UI {
	public:
		UI() = delete;
		~UI() = delete;
		static void PrintAndSet(const std::string &print, std::string &get);
		static void PrintAndSet(const std::string &print, int &get);
		static void PrintAndWaitForEnter(const std::string &print);
		static void	ShowGreeting();
		static void	ShowEmptyTableMessage();
		static void	ShowTableHeader();
		static void	ShowExitMessage();
		static void ShowFormattedTableCell(int data);
		static void ShowFormattedTableCell(const std::string &data);
};

#endif //EX01_UI_H
