#include <iostream>

int main(){
	std::string	tmp = "HI THIS IS BRAIN";
	std::string	*stringPTR = &tmp;
	std::string	&stringREF = tmp;

	std::cout << std::hex << &tmp << std::endl;
	std::cout << std::hex << &stringPTR << std::endl;
	std::cout << std::hex << &stringREF << std::endl;

	std::cout << tmp << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
