#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{
private:
	enum {
		FIRST_NAME = 0,
		LAST_NAME = 1,
		NICKNAME = 2,
		PHONE_NUMBER = 3,
		DARKEST_SECRET = 4,
	};
	const static size_t	n_info = 5;
	int			_num_i;
	std::string	_info[n_info];
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