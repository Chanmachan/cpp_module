//
// Created by 本間優之介 on 2023/02/17.
//

#include "Dog.h"
#include "Cat.h"
#include "WrongCat.h"

//__attribute__((destructor))
//static void destructor() {
//	system("leaks -q exe");
//}

int main() {
	/* CHECK MEMORY LEAKS */
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete i;
		delete j;//should not create a leak delete i;
	}

	std::cout << std::endl << std::endl;;

	/* ADDITIONAL TEST */
	{
		const Dog *dog = new Dog();
		std::cout << "here" << std::endl;
		dog->Dog::setBrain();
		dog->Dog::getBrain(3);
		delete dog;
	}
	return 0;
}