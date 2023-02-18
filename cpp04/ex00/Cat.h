//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX00_CAT_H
#define CPP04EX00_CAT_H

#include "Animal.h"

class Cat: public virtual Animal{
public:
	Cat();
	Cat(const Cat& src);
	~Cat();

	Cat& operator=(const Cat& src);

	void makeSound() const;
};


#endif //CPP04EX00_CAT_H
