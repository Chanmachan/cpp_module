#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
//const static n_contact = 8 -> magic number を扱う方法として良い

class PhoneBook{
private:
	const static int	n_contact = 8;
	int		_num;
	Contact	_contact[8];
	int		_input_depth;
	void	wait_input(std::string type);
	bool	judge_arguments(std::string type, std::string input);
	bool	output_detail(std::string input);
	void	print_detail(int index);
public:
	PhoneBook();
	void	add();
	void	search();
};

#endif