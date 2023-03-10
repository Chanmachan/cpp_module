//
// Created by 本間優之介 on 2023/03/10.
//

#include <iostream>
#include "Data.h"
#include "color.h"

// docker -> unsigned long
uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t&>(ptr);
}

Data*  deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	std::cout << CYAN << "[TEST1]" << RESET << std::endl;
	{
		Data *bf = new Data;
		std::cout << "original ptr:\t" << bf << std::endl;
		uintptr_t af = serialize(bf);
		std::cout << "serialize:\t" << af << std::endl;
		Data *rtn = deserialize(af);
		std::cout << "deserialize:\t" << rtn << std::endl;
		delete bf;
	}
	std::cout << CYAN << "[TEST2]" << RESET << std::endl;
	{
		Data *bf = NULL;
		std::cout << "original ptr:\t" << bf << std::endl;
		uintptr_t af = serialize(bf);
		std::cout << "serialize:\t" << af << std::endl;
		Data *rtn = deserialize(af);
		std::cout << "deserialize:\t" << rtn << std::endl;
		delete bf;
	}
}