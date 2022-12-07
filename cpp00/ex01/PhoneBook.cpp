#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _num(0), _input_depth(0){
	for (int i = 0; i < 8; i++){
		_contact[i].init_info(i);
	}
}

bool	PhoneBook::judge_arguments(std::string type, std::string input) {
	size_t	i = 1;

	if (type == "phone number"){
		if ((input[0] == '+' && isdigit(input[1])) || isdigit(input[0])){
			while (i < input.size()){
				if (!isdigit(input[i++]))
					return (false);
			}
			return (true);
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
			std::exit(EXIT_SUCCESS);
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

void	PhoneBook::print_detail(int index) {
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		if (i == 0)
			std::cout << "first name:     ";
		else if (i == 1)
			std::cout << "last name:      ";
		else if (i == 2)
			std::cout << "nickname:       ";
		else if (i == 3)
			std::cout << "phone number:   ";
		else if (i == 4)
			std::cout << "darkest secret: ";
		std::cout << _contact[index].get_data(i) << std::endl;
	}
	std::cout << std::endl;
}

bool	PhoneBook::output_detail(std::string input) {
	const char	*str = input.c_str();
	int			index = std::atoi(str);

	if (input.size() > 2)
		return (false);
	if (1 <= index && index <= 8 && index - 1 < _input_depth){
		print_detail(index - 1);
		return (true);
	}
	return (false);
}

void	PhoneBook::search() {
	if (_input_depth == 0){
		std::cout << "phonebook is empty" << std::endl;
		return ;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   index  |first name|last name |nick name |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < _input_depth; i++){
		_contact[i].get_info_for_search(i);
	}
	std::string	input;
	while (42){
		std::cout << "type index to see detail > ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(EXIT_SUCCESS);
		else if (!input.empty() && output_detail(input))
			break ;
		else
			std::cout << "index out of range!" << std::endl;
	}
}
