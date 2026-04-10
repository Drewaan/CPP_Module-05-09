/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:38:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/04/10 19:13:23 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static void	validateInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];

		if(arg.empty())
			throw std::runtime_error("Error: empty argument.");

		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(static_cast<unsigned char>(arg[j])))
				throw std::runtime_error("Error: invalid character.");
		}

		long	value = std::strtol(arg.c_str(), NULL, 10);

		if (value < 0)
			throw std::runtime_error("Error: negative numbers are not allowed.");

		if (value > INT_MAX)
			throw std::runtime_error("Error: number out of range.");
	}	
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "./PmergeMe <positive integers>" << std::endl;
		return 1;
	}

	try
	{
		validateInput(argc, argv);

		PmergeMe sorter(argc, argv);
		sorter.runSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

/*====================== CONSTRUCTORS ======================*/

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int value = std::atoi(argv[i]);
        _dataVec.push_back(value);
        _dataDeq.push_back(value);
    }
}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _dataVec(other._dataVec), _dataDeq(other._dataDeq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _dataVec = other._dataVec;
        _dataDeq = other._dataDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

/*====================== UTILITIES ======================*/

bool PmergeMe::alreadySorted() const
{
    for (size_t i = 1; i < _dataVec.size(); ++i)
    {
        if (_dataVec[i - 1] > _dataVec[i])
            return false;
    }
    return true;
}

template <typename T>
void displayContainer(const T &container)
{
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

/*====================== JACOBSTHAL ORDER ======================*/

template <typename T>
void buildInsertionOrder(size_t size, T &sequence)
{
    if (size == 0)
        return;

    sequence.push_back(0);
    if (size == 1)
        return;

    size_t prev = 0;
    size_t curr = 1;

    while (true)
    {
        size_t next = curr + 2 * prev;
        if (next >= size)
            break;

        sequence.push_back(next);
        prev = curr;
        curr = next;
    }

    // add missing indices
    for (size_t i = 0; i < size; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
            sequence.push_back(i);
    }
}

/*====================== FORD-JOHNSON CORE ======================*/

template <typename Container>
void mergeInsertAlgorithm(Container &input)
{
    if (input.size() <= 1)
        return;

    Container largerGroup;
    Container smallerGroup;

    bool hasOdd = (input.size() % 2 != 0);
    typename Container::value_type oddElement;

    if (hasOdd)
        oddElement = input.back();

    // Pair elements
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            largerGroup.push_back(input[i]);
            smallerGroup.push_back(input[i + 1]);
        }
        else
        {
            largerGroup.push_back(input[i + 1]);
            smallerGroup.push_back(input[i]);
        }
    }

    // Recursive sort of larger elements
    mergeInsertAlgorithm(largerGroup);

    // Determine insertion order
    Container insertionOrder;
    buildInsertionOrder(smallerGroup.size(), insertionOrder);

    // Insert smaller elements
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t idx = insertionOrder[i];
        typename Container::iterator pos =
            std::lower_bound(largerGroup.begin(), largerGroup.end(), smallerGroup[idx]);
        largerGroup.insert(pos, smallerGroup[idx]);
    }

    // Insert leftover element
    if (hasOdd)
    {
        typename Container::iterator pos =
            std::lower_bound(largerGroup.begin(), largerGroup.end(), oddElement);
        largerGroup.insert(pos, oddElement);
    }

    input = largerGroup;
}

/*====================== PUBLIC EXECUTION ======================*/

void PmergeMe::runSort()
{
    if (alreadySorted())
        throw std::runtime_error("Sequence already sorted.");

    std::cout << "Before: ";
    displayContainer(_dataVec);

    std::clock_t startVec = std::clock();
    mergeInsertAlgorithm(_dataVec);
    std::clock_t endVec = std::clock();

    std::clock_t startDeq = std::clock();
    mergeInsertAlgorithm(_dataDeq);
    std::clock_t endDeq = std::clock();

    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000;
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000;

    std::cout << "After:  ";
    displayContainer(_dataVec);

    std::cout << "Vector time: " << timeVec << " ms" << std::endl;
    std::cout << "Deque  time: " << timeDeq << " ms" << std::endl;
}