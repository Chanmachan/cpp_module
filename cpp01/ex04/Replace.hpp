//
// Created by 本間優之介 on 2022/12/12.
//

#ifndef CPP_MODULE_REPLACE_HPP
#define CPP_MODULE_REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace {
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;
public:
	Replace(std::string filename, std::string s1, std::string s2);
	int	replacing_data();
};

#endif //CPP_MODULE_REPLACE_HPP
