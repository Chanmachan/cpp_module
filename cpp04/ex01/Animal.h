//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX01_ANIMAL_H
#define CPP04EX01_ANIMAL_H

#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	explicit Animal(const std::string& type);
	Animal(const Animal& src);
	// new->deleteを行う場合、デストラクタをvirtualにしなければならない
	// error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor
	virtual ~Animal();

	Animal& operator=(const Animal& src);

	std::string getType() const;
	virtual void makeSound() const;
};

#endif //CPP04EX01_ANIMAL_H
