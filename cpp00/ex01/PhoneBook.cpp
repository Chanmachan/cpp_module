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
	printf("here: [%d]\n", _num);
	std::string tmp;
	for (int i = 0; i < 8; i++) {
		printf("------------------------------------\n");
		for (int j = 0; j < 5; j++) {
			tmp = _contact[i].get_data(j);
			printf("[%d]: ", j);
			std::cout << tmp << std::endl;
		}
	}
}


void	PhoneBook::search() {
	printf("num %d\n", _num);
}