//
// Created by 本間優之介 on 2023/03/14.
//

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <set>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define GRAY "\x1b[37m"
#define RESET "\x1b[0m"

template<typename T>
void f1(T& t, int target);
// forward_list
template<typename T>
void f2(T& t, int target);
// set
template<typename T>
void f3(T& t, int target);

int main() {
	{
		const int target = 9;
		std::cout << "target is " << target << std::endl;
		{
			std::cout << CYAN << "[VECTOR TEST]" << RESET << std::endl;
			std::vector<int> test1;
			f1(test1, target);

			std::cout << CYAN << "[LIST TEST]" << RESET << std::endl;
			std::list<int> test2;
			f1(test2, target);

			std::cout << CYAN << "[DEQUE TEST]" << RESET << std::endl;
			std::deque<int> test3;
			f1(test3, target);

			// forward_list(単方向リスト) 単方向なのでpush_backはない
			std::cout << CYAN << "[FORWARD_LIST TEST]" << RESET << std::endl;
			std::forward_list<int> test4;
			f2(test4, target);

			// set(順序付集合) insertはソートされた位置に値を入れる
			std::cout << CYAN << "[SET TEST]" << RESET << std::endl;
			std::set<int> test5;
			f3(test5, target);
		}
	}
	std::cout << "--------------------------------" << std::endl;
	{
		const int target = 10;
		std::cout << "target is " << target << std::endl;
		{
			std::cout << CYAN << "[VECTOR TEST]" << RESET << std::endl;
			std::vector<int> test1;
			f1(test1, target);

			std::cout << CYAN << "[LIST TEST]" << RESET << std::endl;
			std::list<int> test2;
			f1(test2, target);

			std::cout << CYAN << "[DEQUE TEST]" << RESET << std::endl;
			std::deque<int> test3;
			f1(test3, target);

			std::cout << CYAN << "[FORWARD_LIST TEST]" << RESET << std::endl;
			std::forward_list<int> test4;
			f2(test4, target);

			std::cout << CYAN << "[SET TEST]" << RESET << std::endl;
			std::set<int> test5;
			f3(test5, target);
		}
	}
}

template<typename T>
void f1(T& t, int target) {
	for (size_t i = 0; i < 10; ++i) {
		t.push_back((int)i);
	}
	try {
		typename T::iterator itr = easyfind(t, target);
		std::cout << GREEN << "Found" << RESET << std::endl;
#ifdef DEBUG
		std::cout << "target: " << target << " = " << *itr << std::endl;
#endif
		(void) itr;
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

// forward_list
template<typename T>
void f2(T& t, int target) {
	for (size_t i = 0; i < 10; ++i) {
		t.push_front((int)9 - i);
	}
	try {
		typename T::iterator itr = easyfind(t, target);
		std::cout << GREEN << "Found" << RESET << std::endl;
#ifdef DEBUG
		std::cout << "target: " << target << " = " << *itr << std::endl;
#endif
		(void) itr;
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

// set
template<typename T>
void f3(T& t, int target) {
	for (size_t i = 0; i < 10; ++i) {
		t.insert((int)i);
	}
	try {
		typename T::iterator itr = easyfind(t, target);
		std::cout << GREEN << "Found" << RESET << std::endl;
#ifdef DEBUG
		std::cout << "target: " << target << " = " << *itr << std::endl;
#endif
		(void) itr;
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}