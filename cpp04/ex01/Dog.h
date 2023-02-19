//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX00_DOG_H
#define CPP04EX00_DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog: public virtual Animal{
private:
	Brain* brains_;
public:
	Dog();
	Dog(const Dog& src);
	~Dog();

	Dog& operator=(const Dog& src);
	void makeSound() const;
};


#endif //CPP04EX00_DOG_H
