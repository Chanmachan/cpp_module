//
// Created by 本間優之介 on 2023/02/19.
//

#include "Brain.h"

Brain::Brain() {
	std::cout << "Here is Brain !" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain "  << "is duplicated"<< std::endl;
	for (size_t i = 0; i < Brain::N; i++) {
		this->ideas[i] = src.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Bye Brain" << std::endl;
}

Brain& Brain::operator=(const Brain &src) {
	std::cout << "Brain operator= called" << std::endl;
	for (size_t i = 0; i < Brain::N; i++) {
		this->ideas[i] = src.ideas[i];
	}
	return *this;
}