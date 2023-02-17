//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX00_DOG_H
#define CPP04EX00_DOG_H

#include "Animal.h"

class Dog: public virtual Animal{
public:
	Dog();
	Dog(const Dog& src);
	~Dog();

	Dog& operator=(const Dog& src);
};


#endif //CPP04EX00_DOG_H
