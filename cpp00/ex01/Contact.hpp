#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact{
private:
	int			_num_i;
	std::string	_info[5];
public:
	Contact();
	void	init_info(int num);
	void	set_data(std::string input, int num);
};

#endif