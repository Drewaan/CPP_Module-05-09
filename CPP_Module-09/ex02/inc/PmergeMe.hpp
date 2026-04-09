/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:38:30 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/04/09 16:39:01 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <string>
#include <sys/time.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	sort(int argc, char **argv);

	private:
		size_t	comparisonCountVector;
		size_t	comparisonCountDeque;

		bool	compareVector(int a, int b);
		bool	compareDeque(int a, int b);
		std::vector<int> sortWithVector(std::vector<int> &input);
		std::vector<int> sortWithDeque(std::deque<int> &input);

		std::vector<std::pair<int, size_t> >
		sortWithIndex(std::vector<std::pair<int, size_t> > &input);

		std::deque<std::pair<int, size_t> >
		sortWithIndexDeque(std::deque<std::pair<int, size_t> > &input);

		std::vector<std::pair<int, size_t> >
		insertPendingWithIndex(std::vector<std::pair<int, size_t> > &mainChain, std::vector<std::pair<int, size_t> > &pending);
		
		std::deque<std::pair<int, size_t> >
		insertPendingWithIndexDeque(std::deque<std::pair<int, size_t> > &mainChain, std::deque<std::pair<int, size_t> > &pending);

		size_t	binarySearchWithIndex(const std::vector<std::pair<int, size_t> > &arr, int value, size_t end, size_t pairPos);
		
		size_t	binarySearchWithIndexDeque(const std::deque<std::pair<int, size_t> > &arr, int value, size_t end, size_t pairPos);

		std::vector<size_t>	generateJacobsthal(size_t n);
		std::vector<size_t>	buildInsertionOrder(size_t pendingSize);

		std::vector<int>	parseInput(int argc, char **argv);
		void	displaySequence(const std::vector<int> &sequence);
		void	validateInput(const std::string &str);
		double	elapsedUs(struct timespec start, struct timespec end);
		void	printTime(size_t size, const std::string &container, double time);
		double	timeSort(std::vector<int> &input, std::vector<int> &output);
		double	timeSortDeque(std::deque<int> &input, std::deque<int> &output);
};

#endif