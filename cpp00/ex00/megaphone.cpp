#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "wrong arguments" << std::endl;
		return (1);
	}
	for (size_t i = 1; argv[i] != NULL; i++) {
		for (size_t j = 0; argv[i][j] != '\0'; j++) {
			std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
