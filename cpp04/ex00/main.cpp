//
// Created by 本間優之介 on 2023/02/17.
//

#include "Dog.h"
#include "Cat.h"

/*std::ostream& operator<<(std::ostream& ostream, Dog& dog){
	return ostream << dog.get_type();
}

std::ostream& operator<<(std::ostream& ostream, Cat& cat){
	return ostream << cat.get_type();
}

int main(){
	{
		Dog dog;
		Dog dog2(dog);

		std::cout << std::endl;

		std::cout << dog << " is appeared"  << std::endl;

		dog.makeSound();

		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		Cat cat;
		Cat cat2(cat);

		std::cout << std::endl;

		std::cout << cat << " is appeared" << std::endl;

		cat.makeSound();

		std::cout << std::endl;
	}
}*/

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//...
	delete j;
	delete i;
	return 0;
}
