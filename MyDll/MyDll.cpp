#include <iostream>
#include "MyDll.h"

HelloDll::HelloDll()
{

}

HelloDll::~HelloDll()
{

}

void HelloDll::hello()
{
	std::cout << "hello, this is my dll ^_^" << std::endl;
}