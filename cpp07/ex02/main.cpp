//
// Created by 本間優之介 on 2023/03/11.
//

#include "Array.hpp"
#include <sstream>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define GRAY "\x1b[37m"
#define RESET "\x1b[0m"

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::cout << std::endl << CYAN << "[DEFAULT TEST]" << RESET << std::endl;
	{
		std::cout << "use any kind of leaks checker" << std::endl;
		{
			std::cout << YELLOW << "<1>" << RESET << std::endl;
			// sizeが代入される側のほうが大きい
			Array<float> test1(30);
			Array<float> test2(15);
			test1 = test2;
//			test1 = test1; //cannot compile because of -Werror
			std::cout << "size(): " << test1.size() << std::endl;
			std::cout << "max_size: " << test1.getMaxSize() << std::endl;
		}
		{
			std::cout << YELLOW << "<2>" << RESET << std::endl;
			// sizeが代入される側のほうが小さい
			Array<double> test1(15);
			Array<double> test2(30);
			test1 = test2;
			std::cout << "size(): " << test1.size() << std::endl;
			std::cout << "max_size: " << test1.getMaxSize() << std::endl;
		}
		{
			std::cout << YELLOW << "<3>" << RESET << std::endl;
			Array<int> test_equal(10);
			{
				Array<int> copy(20);
				std::cout << YELLOW << "Before \"=\"" << RESET << std::endl;
				std::cout << "size(): " << copy.size() << std::endl;
				std::cout << "max_size: " << copy.getMaxSize() << std::endl;
				copy = test_equal;
				std::cout << YELLOW << "After \"=\"" << RESET << std::endl;
				std::cout << "size(): " << copy.size() << std::endl;
				std::cout << "max_size: " << copy.getMaxSize() << std::endl;
				Array<int> test(copy);
				std::cout << YELLOW << "Copy Constructor" << RESET << std::endl;
				std::cout << "size(): " << test.size() << std::endl;
				std::cout << "max_size: " << test.getMaxSize() << std::endl;
			}
		}
	}

	std::cout << std::endl << CYAN << "[INT TEST]" << RESET << std::endl;
	{
		Array<int> int_array;
		try {
			int_array[0] = 10;
			int_array[1] = 10;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
//		size_t N = 0;
		try {
			// １大きいサイズ文for文が回ってしまうのでout_of_range
			for (size_t i = 0; i < int_array.getMaxSize() + 1; i++) {
				std::cout << "operator["<< i << "]: " << int_array[i] << std::endl;
			}
//			std::cout << "operator["<< N << "]: " << int_array[N] << std::endl;
		} catch (std::exception& e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "size(): " << int_array.size() << std::endl;
	}

	std::cout << std::endl << CYAN << "[STRING TEST]" << RESET << std::endl;
	{
		Array<std::string> string_array(20);
		try {
			std::stringstream ss;
			// １大きいサイズ文for文が回ってしまうのでout_of_range
			for (size_t i = 0; i < string_array.size() + 1; i++) {
				ss.clear();
				ss << i;
				ss >> string_array[i];
			}
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		try {
			// １大きいサイズ文for文が回ってしまうのでout_of_range
			for (size_t i = 0; i < string_array.getMaxSize() + 1; i++) {
				std::cout << string_array[i] << ", ";
			}
		} catch (std::exception& e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "size(): " << string_array.size() << std::endl;
	}

	std::cout << std::endl << CYAN << "[ARRAY IN ARRAY TEST]" << RESET << std::endl;
	{
		Array<Array<int> > test(2);
		std::cout << test.size() << std::endl;
		Array<Array<int> > tmp(test);
	}
}