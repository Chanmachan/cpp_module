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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete i;
	delete j;//should not create a leak delete i;
	//...
	return 0; }