//
// Created by 本間優之介 on 2023/02/18.
//

#ifndef CPP04EX00_WRONGANIMAL_H
#define CPP04EX00_WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	explicit WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& src);
	// new->deleteを行う場合、デストラクタをvirtualにしなければならない
	// error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& src);

	std::string getType() const;
	void makeSound() const;
};


#endif //CPP04EX00_WRONGANIMAL_H
