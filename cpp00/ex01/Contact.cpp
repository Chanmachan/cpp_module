#include "Contact.hpp"

Contact::Contact() {

}

void	Contact::init_info(int num) {
	_num_i = num;
	for (int i = 0; i < 5; i++){
		_info[i] = "empty";
	}
}

void	Contact::set_data(std::string input, int num){
	_info[num] = input;
}

int		Contact::get_index() {
	return (_num_i);
}

std::string	Contact::get_data(int i) {
	return (_info[i]);
}

std::string	Contact::get_data(int i, int len) {
	if (_info[i].size() <= 10)
		return (_info[i].substr(0, len));
	else
	{
		return (_info[i].substr(0, 9) + ".");
	}
}

void	Contact::get_info_for_search(int i) {
	std::cout << '|';
	std::cout << std::setw(10) << i + 1;
	std::cout << '|';
	std::cout << std::setw(10) << get_data(FIRST_NAME, 10);
	std::cout << '|';
	std::cout << std::setw(10) << get_data(LAST_NAME, 10);
	std::cout << '|';
	std::cout << std::setw(10) << get_data(NICKNAME, 10);
	std::cout << '|' << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void	Contact::increment_index() {
	_num_i++;
}

void	Contact::reset_index() {
	_num_i = 0;
}