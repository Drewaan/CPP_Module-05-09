/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:01:20 by aamaya-g          #+#    #+#             */
/*   Updated: 2026/03/16 19:12:26 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN
{
	private:
		bool	isOperator(const std::string &token) const;
		int		applyOperation(int a, int b, const std::string &op) const;

	public:
		RPN();
		RPN(const RPN &other);
		RPN operator=(const RPN &other);
		~RPN();

		int	evaluate(const std::string &expr) const;
};


#endif