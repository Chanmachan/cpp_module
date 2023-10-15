//
// Created by chanma on 2023/10/02.
//

#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	// BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
private:
	std::map<std::string, double> rate_map_;
	bool validateDate(const std::string& date);
	bool isDigit(const std::string& data);
	static bool validateYear(const std::string& data);
	static bool validateMonth(const std::string& data);
	static bool validateDay(const std::string& data);
};


#endif //CPP09_BITCOINEXCHANGE_HPP
