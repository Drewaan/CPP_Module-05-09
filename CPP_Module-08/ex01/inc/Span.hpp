/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:53:02 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/03/05 19:42:39 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);
		long long shortestSpan() const;
		long long longestSpan() const;

		template <typename T>
		void addRange(T begin, T end)
		{
			if (_numbers.size() + std::distance(begin, end) > _N)
				throw std::runtime_error("Not enough space");
		
			for (T it = begin; it != end; ++it)
				_numbers.push_back(*it);
		}
};

#endif