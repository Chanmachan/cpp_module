//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX01_CAT_H
#define CPP04EX01_CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat: public virtual Animal{
private:
	Brain* brains_;
public:
	Cat();
	Cat(const Cat& src);
	~Cat();

	Cat& operator=(const Cat& src);

	void makeSound() const;
};

#endif //CPP04EX01_CAT_H
