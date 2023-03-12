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

int main() {
	std::cout << std::endl << CYAN << "[DEFAULT TEST]" << RESET << std::endl;
	{
		std::cout << "use any kind of leaks checker" << std::endl;
		{
			Array<float> test1(30);
			Array<float> test2(15);
			test1 = test2;
//			test1 = test1; //cannot compile because of -Werror
		}
		{
			Array<Array<int> > test1(10);
		}
	}

	std::cout << CYAN << "[INT TEST]" << RESET << std::endl;
	{
		Array<int> int_array;
		try {
			int_array[0] = 10;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		size_t N = 0;
		try {
			std::cout << "operator["<< N << "]: " << int_array[N] << std::endl;
		} catch (std::exception& e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "size(): " << int_array.size() << std::endl;
	}

	std::cout << std::endl << CYAN << "[STRING TEST]" << RESET << std::endl;
	{
		Array<std::string> string_array(750);
		try {
			std::stringstream ss;
			for (size_t i = 0; i < string_array.size(); i++) {
				ss.clear();
				ss << i;
				ss >> string_array[i];
			}
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		try {
			std::cout << string_array[749] << std::endl;
			std::cout << string_array[750] << std::endl;
			std::cout << string_array[751] << std::endl;
		} catch (std::exception& e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "size(): " << string_array.size() << std::endl;
	}

	std::cout << std::endl << CYAN << "[ARRAY IN ARRAY TEST]" << RESET << std::endl;
	{
		Array<Array<int> > test(2);
		std::cout << test.size() << std::endl;
	}
}