//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX02_WRONGCAT_H
#define CPP04EX02_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat: public virtual WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat& src);
	~WrongCat();

	WrongCat& operator=(const WrongCat& src);

	void makeSound() const;
};


#endif //CPP04EX02_WRONGCAT_H
