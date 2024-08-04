#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define GRAY "\033[90m"

Base *generate(void)
{
	std::srand(std::time(0));
	int randNum = std::rand() % 3;

	switch (randNum)
	{
	case 0:
		std::cout << "instance of class A is created" << std::endl;
		return new A();
	case 1:
		std::cout << "instance of class B is created" << std::endl;
		return new B();
	case 2:
		std::cout << "instance of class C is created" << std::endl;
		return new C();
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "pointer is identified as an instance of class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "pointer is identified as an instance of class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "pointer is identified as an instance of class C" << std::endl;
	else
		std::cout << "pointer was not identified" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "refernced pointer is identified as an instance of class A" << std::endl;
	}
	catch (std::exception &)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "refernced pointer is identified as an instance of class B" << std::endl;
		}
		catch (std::exception &)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "refernced pointer is identified as an instance of class C" << std::endl;
			}
			catch (std::exception &)
			{
				std::cout << "refernced pointer was not identified" << std::endl;
			}
		}
	}
}

int main(void)
{
	std::cout << GRAY << "\n-- test 1 --" << RESET << std::endl;
	Base *obj = generate();
	identify(obj);
	identify(*obj);

	std::cout << GRAY << "\n-- test 2 --" << RESET << std::endl;
	D *dObj = new D();
	std::cout << "instance of class D is created" << std::endl;
	identify(dObj);
	identify(*dObj);

	return delete obj, delete dObj, EXIT_SUCCESS;
}
