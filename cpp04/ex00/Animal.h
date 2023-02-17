//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX00_ANIMAL_H
#define CPP04EX00_ANIMAL_H

#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& src);
	~Animal();

	Animal& operator=(const Animal& src);
};

#endif //CPP04EX00_ANIMAL_H
