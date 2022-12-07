#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
//const static n_contact = 8 -> magic number を扱う方法として良い

class PhoneBook{
private:
	int		_num;
	Contact	_contact[8];
	int		_input_depth;
public:
	PhoneBook();
	void	add();
	void	search();
	void	wait_input(std::string type);
	bool	judge_arguments(std::string type, std::string input);
	bool	output_detail(std::string input);
	void	print_detail(int index);
};

#endif