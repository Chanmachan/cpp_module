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
	void processInputFile(const std::string& filename);
private:
	std::map<std::string, double> rate_map_;
	bool validateDate(const std::string& date);
	static bool validateRate(const std::string& rate_str);
	void inputDataIntoMap(const std::string& date, const std::string& rate_str);
	static bool isDigit(const std::string& data);
	static bool validateYear(const std::string& data, int &month, bool &isLeapYear);
	static bool validateMonth(const std::string& data, int &month, bool &isLeapYear);
	static bool validateDay(const std::string& data, int &month, bool &isLeapYear);
	bool validateValue(const std::string& value_str, double& value);
	double getRate(const std::string& date);
};


#endif //CPP09_BITCOINEXCHANGE_HPP
