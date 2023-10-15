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
		std::cerr << "file cannot open" << std::endl;
	}
	// data.csvのvalidateをかける
	std::string line;
	std::getline(datafile, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("data.csv: date wrong format");
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
	}
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	rate_map_ = src.rate_map_;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	rate_map_ = rhs.rate_map_;
	return *this;
}

bool BitcoinExchange::validateDate(const std::string& date) {
	if (date.length() != 10) {
		return false;
	}
	std::istringstream ss(date);
	std::string token;
	std::vector<std::string> tokens;
	while (std::getline(ss, token, '-')) {
		tokens.push_back(token);
	}
	if (tokens.size() != 3) {
		return false;
	}

	typedef bool (*Validator)(const std::string&);
	Validator validators[3] = {validateYear, validateMonth, validateDay};

	for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it){
		if (!isDigit(*it)) {
			return false;
		}
		if (!validators[it - tokens.begin()](*it)) {
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::isDigit(const std::string& data) {
	for (std::string::const_iterator it = data.begin(); it != data.end(); ++it) {
		if (!std::isdigit(*it)) {
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::validateYear(const std::string &data) {
	int year = std::atoi(data.c_str());
	if (year < 2009 || 2999 < year) {
		return false;
	}
	return true;
}

bool BitcoinExchange::validateMonth(const std::string &data) {
	int month = std::atoi(data.c_str());
	if (month < 1 || 12 < month) {
		return false;
	}
	return true;
}

bool BitcoinExchange::validateDay(const std::string &data) {
	int day = std::atoi(data.c_str());
	if (day < 1 || 31 < day) {
		return false;
	}
	return true;
}
