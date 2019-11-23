#pragma once
#include <iostream>

class Animal
{
public:
	virtual ~Animal()
	{
		std::cout << "Animal dtor\n";
	}
	virtual void Pet()
	{
		std::cout << name << " says fart\n";
	}
	std::string name;
protected:
	Animal(std::string name)
		:
		name(name)
	{
		std::cout << "Animal ctor\n";
	}
};
class Dog : public Animal
{
public:
	~Dog() override
	{
		std::cout << "Dog dtor\n";
	}
	Dog(std::string name)
		:
		Animal(name)
	{
		std::cout << "Dog ctor\n";
	}
	void Pet() override
	{
		std::cout << name << " says Woof!\n";
	}
};
class Cat : public Animal
{
public:
	~Cat() override
	{
		std::cout << "Cat dtor\n";
	}
	Cat(std::string name)
		:
		Animal(name)
	{
		std::cout << "Cat ctor\n";
	}
	void Pet() override
	{
		std::cout << name << " says Miauw!\n";
	}
};