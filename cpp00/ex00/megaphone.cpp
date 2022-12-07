#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (size_t i = 1; argv[i] != NULL; i++) {
		for (size_t j = 0; argv[i][j] != '\0'; j++) {
			argv[i][j] = std::toupper(argv[i][j]);
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}
