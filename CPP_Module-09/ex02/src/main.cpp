/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:38:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/04/09 16:44:50 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe	sorter;

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	sorter.sort(argc, argv);
	return 0;
}
