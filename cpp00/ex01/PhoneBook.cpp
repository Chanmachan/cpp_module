#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _num(0), _input_depth(0){
	for (int i = 0; i < 8; i++){
		_contact[i].init_info(i);
	}
}

bool	PhoneBook::judge_arguments(std::string type, std::string input) {
	size_t	i = 0;

	if (type == "phone number"){
		if (input[0] == '+' || isdigit(input[0])){
			while (input[++i] != '\0'){
				if (!isdigit(input[i++]))
					return (false);
			}
		} else
			return (false);
	}
	return (true);
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
		else if (!input.empty() && judge_arguments(type, input))
			break ;
		else
			std::cout << "Wrong information!" << std::endl;
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
	if (_input_depth < 8)
		_input_depth++;
	std::cout << "٩( ᐛ )و" << std::endl;
}


void	PhoneBook::search() {
	if (_input_depth == 0){
		std::cout << "phonebook is empty" << std::endl;
		return ;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   index  |first name|last name |nick name |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	/*for (int i = 0; i < _input_depth; i++){

	}*/

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