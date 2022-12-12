//
// Created by 本間優之介 on 2022/12/12.
//

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) {
	this->_filename = filename;
	this->_s1 = s1;
	this->_s2 = s2;
}

int	Replace::replacing_data() {
	std::ifstream ifs(_filename);
	if (!ifs){
		std::cerr << "Error in ifstream" << std::endl;
		return (1);
	}
	std::ofstream ofs(_filename + ".replace");
	if (!ofs){
		std::cerr << "Error in ofstream" << std::endl;
		return (1);
	}
	std::string	line;
	size_t	find_ret;
	bool	nl_flag = false;
	// read line by line
	while (getline(ifs, line)){
		if (nl_flag)
			ofs << std::endl;
		else
			nl_flag = true;
		while ((find_ret = line.find(_s1)) != std::string::npos){
			line.erase(find_ret, _s1.size());
			line.insert(find_ret, _s2);
		}
		ofs << line;
	}
	return (0);
}