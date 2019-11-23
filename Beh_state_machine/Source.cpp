#pragma once
#include <iostream>
#include <vector>
#include "Animal.h"
#include "Entity.h"

int main()
{
	{
		Entity ent(100);
		ent.Show();
		ent.Show();
	}
	std::cout << std::endl;
	{
		Dog dog("rambo");
		Cat cat("pussycat");
		dog.Pet();
		cat.Pet();
		//Animal a = Animal(cat);
		Animal  a = static_cast<Animal&>(cat);
		a.Pet();
	}

	std::cin.get();
	return 0;
}