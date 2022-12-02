#include "PhoneBook.hpp"

int main()
{
	std::string	line;
//	PhoneBook	phonebook;

	while (42)
	{
		std::getline(std::cin, line);
		if (line == "ADD"){
			printf("ADD\n");
		} else if (line == "SEARCH"){
			printf("SEARCH\n");
		} else if (line == "EXIT"){
			break ;
		}
		std::cout << line << std::endl;
	}
	return (0);
}
