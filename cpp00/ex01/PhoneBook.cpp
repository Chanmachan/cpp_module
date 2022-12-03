#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _num(0){
	for (int i = 0; i < 8; i++){
		_contact[i].init_info(i);
	}
}

void	PhoneBook::add() {
	std::string	input;

//	for (int i = 0; i < 5; i++){
	while (42){
		std::cout << "first name: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(EXIT_FAILURE);
		else if (!input.empty())
			break ;
		else
			std::cout << "Wrong info" << std::endl;
	}
	_contact[0].set_data(input, 0);
//	}
}


void	PhoneBook::search() {
	printf("num %d\n", _num);
}