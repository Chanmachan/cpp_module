#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

#define FIRST_NAME 0
#define LAST_NAME 1
#define NICKNAME 2
#define PHONE_NUMBER 3
#define DARKEST_SECRET 4

class Contact{
private:
	int			_num_i;
	std::string	_info[5];
public:
	Contact();
	void		init_info(int num);
	void		set_data(std::string input, int num);
	int			get_index();
	std::string	get_data(int i);
	std::string	get_data(int i, int len);
	void		get_info_for_search(int i);
	void		increment_index();
	void		reset_index();
};

#endif