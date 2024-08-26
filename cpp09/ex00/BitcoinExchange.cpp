//
// Created by chanma on 2023/10/02.
//

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {
	// data.csvを読み込む
	std::ifstream datafile("data.csv");
	if (!datafile) {
		throw std::runtime_error("data.csv: file cannot open");
	}
	// data.csvのvalidateをかける
	std::string line;
	std::getline(datafile, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("data.csv: wrong format");
	}
	while (std::getline(datafile, line)) {
		size_t pos = line.find(',');
		if (pos == std::string::npos) {
			throw std::runtime_error("data.csv: date wrong format");
		}
		// 日付のvalidate
		std::string date = line.substr(0, pos++);
		if (!validateDate(date)) {
			throw std::runtime_error("data.csv: date wrong format");
		}
		std::string rate_str = line.substr(pos, line.size());
		if (!validateRate(rate_str)) {
			throw std::runtime_error("data.csv: date wrong format");
		}
		inputDataIntoMap(date, rate_str);
	}
// 中身の確認
//	for (std::map<std::string, double>::const_iterator it = rate_map_.begin(); it != rate_map_.end(); ++it) {
//		std::cout << it->first << ": " << it->second << std::endl;
//	}
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	rate_map_ = src.rate_map_;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		rate_map_ = rhs.rate_map_;
	}
	return *this;
}

bool BitcoinExchange::validateDate(const std::string& date) {
	if (date.length() != 10) {
		return false;
	}
	int month;
	bool isLeapYear = false;
	typedef bool (*Validator)(const std::string&, int&, bool&);
	Validator validators[3] = {validateYear, validateMonth, validateDay};

	std::istringstream ss(date);
	for (size_t i = 0; i < 3; ++i) {
		std::string token;
		if (!std::getline(ss, token, '-')) {
			return false;
		}
		if (!isDigit(token)) {
			return false;
		}
		if (!validators[i](token, month, isLeapYear)) {
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::validateRate(const std::string& rate_str) {
	std::stringstream ss(rate_str);
	double rate;

	ss >> rate;
	if (ss.fail() || !ss.eof()) {
		return false;
	}
	return true;
}

void BitcoinExchange::processInputFile(const std::string &filename) {
	std::ifstream inputFile(filename);
	if (!inputFile) {
		throw std::runtime_error(filename + ": file cannot open");
	}
	// inputFileのvalidate
	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value") {
		throw std::runtime_error(filename + ": wrong format");
	}
	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		// 日付
		std::string date;
		if (!std::getline(ss, date, ' ') || !validateDate(date)) {
			std::cerr << "Error: " << "bad input => " << date << std::endl;
			continue;
		}
		// " | "のvalidate
		std::string token;
		if (!std::getline(ss, token, ' ') || token != "|") {
			std::cerr << "Error: " << "bad input => " << date << std::endl;
			continue;
		}
		// value && rate
		std::string value_str;
		double value;
		if (!std::getline(ss, value_str) || !validateValue(value_str, value)) {
			continue;
		}
		double rate;
		try {
			rate = getRate(date);
		} catch (std::runtime_error& e) {
			std::cerr << "Error: " << "bad input => " << date << std::endl;
			continue;
		}
		// 出力
		std::cout << date << " => " << value << " = " << rate*value << std::endl;
	}
}

void BitcoinExchange::inputDataIntoMap(const std::string &date, const std::string &rate_str) {
	std::stringstream ss(rate_str);
	double rate;

	ss >> rate;

	rate_map_.insert(std::make_pair(date, rate));
}

bool BitcoinExchange::isDigit(const std::string& data) {
	for (std::string::const_iterator it = data.begin(); it != data.end(); ++it) {
		if (!std::isdigit(*it)) {
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::validateYear(const std::string &data, int &month, bool &isLeapYear) {
	(void)month;
	int year = std::atoi(data.c_str());
	if (year < 2009 || 2999 < year) {
		return false;
	}
	if (year % 4 == 0) {
		if (year % 100 != 0) {
			isLeapYear = true;
		} else if (year % 400 == 0) {
			isLeapYear = true;
		}
	}
	return true;
}

bool BitcoinExchange::validateMonth(const std::string &data, int &month, bool &isLeapYear) {
	int month_tmp = std::atoi(data.c_str());
	if (month_tmp < 1 || 12 < month_tmp) {
		return false;
	}
	if (isLeapYear && month_tmp != 2) {
		isLeapYear = false;
	}
	month = month_tmp;
	return true;
}

bool BitcoinExchange::validateDay(const std::string &data, int &month, bool &isLeapYear) {
	int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear) {
		dayInMonth[1] = 29;
	}
	int day = std::atoi(data.c_str());
	if (day < 1 || dayInMonth[month-1] < day) {
		return false;
	}
	return true;
}

bool BitcoinExchange::validateValue(const std::string &value_str, double& value) {
	std::stringstream ss(value_str);

	if (!(ss >> value)) {
		std::cerr << "Error: Invalid format." << std::endl;
		return false;
	}

	if (value < 0.0) {
		std::cerr << "Error: " << "not a positive number." << std::endl;
		return false;
	} else if (1000.0 < value) {
		std::cerr << "Error: " << "too large a number." << std::endl;
		return false;
	}
	return true;
}

double BitcoinExchange::getRate(const std::string &date) {
	std::map<std::string, double>::iterator it = rate_map_.upper_bound(date);
	if (it != rate_map_.end()) {
		if (it == rate_map_.begin()) {
			throw std::runtime_error("Error: date is out of range");
		}
		--it;
		return it->second;
	} else {
		throw std::runtime_error("Error: date is out of range");
	}
}
