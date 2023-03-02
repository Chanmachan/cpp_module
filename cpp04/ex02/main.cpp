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
		Cat a;
		Cat b;
		a = b;
		a = b;
	}
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete i;
		delete j;//should not create a leak delete i;
	}

	std::cout << std::endl << std::endl;;

	/* ADDITIONAL TEST */
	{
		Dog a;
		a.setBrain();
		std::cout << a.getBrain(5) << std::endl;
	}

	/* CAN COMPILE */
//	{
//		WrongAnimal *a = new WrongCat();
//		(void )a;
//		delete a;
//	}

	/* CANNOT COMPILE */
//	{
//		Animal *a = new Animal();
//	}

	return 0;
}