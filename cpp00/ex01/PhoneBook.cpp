#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _num(0){
	for (int i = 0; i < 8; i++){
		_contact[i].init_info(i);
	}
}

void	PhoneBook::wait_input(std::string type) {
	std::string	input;

	if (type == "first name")
		_contact[_num].reset_index();
	while (42){
		std::cout << type << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(EXIT_FAILURE);
		else if (!input.empty())
			break ;
		else
			std::cout << "Wrong info" << std::endl;
	}
	_contact[_num].set_data(input, _contact[_num].get_index());
	_contact[_num].increment_index();
}

void	PhoneBook::add() {
	wait_input("first name");
	wait_input("last name");
	wait_input("nickname");
	wait_input("phone number");
	wait_input("darkest secret");
	_num = (_num + 1) % 8;
//	_contact[_num].
	std::string tmp;
	for (int i = 0; i < 5; i++){
		tmp = _contact[0].get_data(i);
		printf("[%d]: ", _contact[0].get_index());
		std::cout << tmp << std::endl;
	}
	for (int i = 0; i < 5; i++){
		tmp = _contact[1].get_data(i);
		printf("[%d]: ", _contact[1].get_index());
		std::cout << tmp << std::endl;
	}
}


void	PhoneBook::search() {
	printf("num %d\n", _num);
}