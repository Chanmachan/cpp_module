//
// Created by 本間優之介 on 2023/02/19.
//

#ifndef CPP04EX01_BRAIN_H
#define CPP04EX01_BRAIN_H

#include <iostream>
#include <string>
#include <sstream>

class Brain {
private:
	const static std::size_t N = 100;
	std::string ideas[N];
public:
	Brain();
	Brain(const Brain& src);
	~Brain();

	Brain& operator=(const Brain& src);

	void setBrain();
	std::string getBrain(std::size_t i) const;
};

#endif //CPP04EX01_BRAIN_H
