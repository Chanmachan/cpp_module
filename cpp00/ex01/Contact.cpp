#include "Contact.hpp"

Contact::Contact() {

}

void	Contact::init_info(int num) {
	_num_i = num;
//	printf("[%d]\n", _num_i);
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

void	Contact::increment_index() {
	_num_i++;
}

void	Contact::reset_index() {
	_num_i = 0;
}