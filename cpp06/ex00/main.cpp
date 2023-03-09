//
// Created by 本間優之介 on 2023/03/04.
//

#include <iostream>
#include "Convert.h"

void print(const std::string& output, t_type type) {
	switch (type) {
		case E_CHAR:
			std::cout << "char: " << output << std::endl;
			break;
		case E_INT:
			std::cout << "int: " << output << std::endl;
			break;
		case E_FLOAT:
			std::cout << "float: " << output << std::endl;
			break;
		case E_DOUBLE:
			std::cout << "double: " << output << std::endl;
			break;
	}
}

void printConvertType(Convert& a) {
	a.inputConvertedType(E_CHAR);
	print(a.getOutput(), E_CHAR);
	a.inputConvertedType(E_INT);
	print(a.getOutput(), E_INT);
	a.inputConvertedType(E_FLOAT);
	print(a.getOutput(), E_FLOAT);
	a.inputConvertedType(E_DOUBLE);
	print(a.getOutput(), E_DOUBLE);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Invalid arguments" << std::endl;
		return 1;
	}
	Convert a(av[1]);
	printConvertType(a);
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
 */