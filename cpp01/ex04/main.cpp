//
// Created by 本間優之介 on 2022/12/12.
//

#include "Replace.hpp"

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Wrong arguments" << std::endl;
		return (1);
	}
	Replace	replace(argv[1], argv[2], argv[3]);
	if (replace.replacing_data()){
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}