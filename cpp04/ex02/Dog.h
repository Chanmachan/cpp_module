//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX02_DOG_H
#define CPP04EX02_DOG_H

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

	void setBrain();
	std::string getBrain(std::size_t i) const;
};


#endif //CPP04EX02_DOG_H
