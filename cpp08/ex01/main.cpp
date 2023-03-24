//
// Created by chanma on 2023/03/15.
//

#include "Span.hpp"
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void test_subject();
void test_exeception();
void test_general(unsigned int n);
void test_rand(unsigned int n);
void printInput(Span span);
void test_addNumber(unsigned int N);

#define EXEC_TEST(proc) {\
	std::string ps(#proc);\
	const size_t n = 50 >= ps.size() ? 50 - ps.size() : 0;\
	std::cout << "== " << #proc << " " << std::string(n, '=') << std::endl;\
	proc;\
}

int main() {
	std::srand((unsigned int) time(NULL));
	EXEC_TEST(test_subject())
	EXEC_TEST(test_exeception())
	EXEC_TEST(test_general(10000))
	EXEC_TEST(test_general(10))
	EXEC_TEST(test_rand(10))
	EXEC_TEST(test_rand(20))
	EXEC_TEST(test_rand(30))
	EXEC_TEST(test_addNumber(10))
	EXEC_TEST(test_addNumber(7))
}

void test_subject() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
//	return 0;
}

void test_exeception() {
	Span e(5);
	/* shortest span */
	try {
		e.shortestSpan();
	} catch (const std::exception& e) {
		std::cout << "shortest_span: " << RED << e.what() << RESET << std::endl;
	}
	/* longest span */
	try {
		e.longestSpan();
	} catch (const std::exception& e) {
		std::cout << "longest_span:  " << RED << e.what() << RESET << std::endl;
	}
	Span zero(0);
	try {
		zero.addNumber(1);
	} catch (const std::exception& e) {
		std::cout << "zero: " << RED << e.what() << RESET << std::endl;
	}
}

void test_general(unsigned int n) {
	Span test(n);
	try {
		for (unsigned int i = 0; i < n + 1; ++i) {
			test.addNumber(i * 4);
		}
	} catch (const std::exception& e) {
		std::cout << "addNumber: " << RED << e.what() << RESET << std::endl;
	}
	if (n < 50) {
		printInput(test);
	}
	try {
		unsigned int rtn = test.longestSpan();
		std::cout << "[longest]  " << rtn << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		unsigned int rtn = test.shortestSpan();
		std::cout << "[shortest] " << rtn << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void test_rand(unsigned int n) {
	Span test(n);
	int min = -10;
	int max = 99;
	try {
		for (unsigned int i = 0; i < n; ++i) {
			int tmp = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
			test.addNumber(tmp);
		}
	} catch (const std::exception& e) {
		std::cout << "addNumber: " << RED << e.what() << RESET << std::endl;
	}
	printInput(test);
	try {
		unsigned int rtn = test.longestSpan();
		std::cout << "[longest]  " << rtn << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		unsigned int rtn = test.shortestSpan();
		std::cout << "[shortest] " << rtn << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void test_addNumber(unsigned int N) {
	std::multiset<int> src;
	for (unsigned int i = 0; i < 10; ++i) {
		src.insert(i);
	}
	std::multiset<int>::const_iterator iBegin = src.begin();
	std::cout << "[original(10)]" << std::endl;
	for (; iBegin != src.end();) {

		std::cout << std::setw(3) << *iBegin++ << ", ";
	}
	std::cout << std::endl;
	Span test(N);
	try {
		test.addNumber(src.begin(), src.end());
	} catch (const std::exception& e) {
		std::cout << "addNumber: " << RED << e.what() << RESET << std::endl;
	}
	printInput(test);
}

void printInput(Span span) {
	std::multiset<int>::const_iterator iBegin = span.getBeginIterator();
	std::cout << "[input]" << std::endl;
	for (unsigned int i = 0; i < 10 && iBegin != span.getEndIterator(); ++i) {
		if (i % 10 == 0 && i != 0) {
			std::cout << std::endl;
		}
		std::cout << std::setw(3) << *iBegin++ << ", ";
	}
	std::cout << std::endl;
}