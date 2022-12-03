#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
private:
	int		_num;
	Contact	_contact[8];
public:
	PhoneBook();
	void	add();
	void	search();
};

#endif