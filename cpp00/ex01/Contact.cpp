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
//	std::cout << _info[num] << std::endl;
}