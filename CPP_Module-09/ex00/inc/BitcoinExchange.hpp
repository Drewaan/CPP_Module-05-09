#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadDatabase(const std::string &filename);
		void	processInput(const std::string &filename);

	public:
		std::map<std::string, double> database;

		void	parseDatabaseLine(const std::string &line);
		void	parseInputLine(const std::string &line);
		
		bool	validateDate(const std::string &date) const;

		std::string trim(const std::string &str);
};

#endif
