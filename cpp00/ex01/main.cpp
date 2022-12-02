#include "PhoneBook.hpp"
#define RED "\x1b[31m"
#define CLEAR "\x1b[39m"

void	print_usage()
{
	std::cout << RED << "Usage" << CLEAR << ": type ";
	std::cout << "\"ADD\" / \"SEARCH\" / \"EXIT\"" << std::endl;

}

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
		} else
			print_usage();
	}
	return (0);
}
