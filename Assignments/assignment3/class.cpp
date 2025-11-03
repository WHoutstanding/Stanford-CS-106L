#include "class.h"

MyClass::MyClass()
{
    std::cout << "This is default constructor of MyClass" << std::endl;
}

MyClass::MyClass(std::string name)
{
    std::cout << "Hello, " << name << std::endl;
}

std::string MyClass::getID() const
{
    return ID;
}

void MyClass::addAge()
{
    age += 1;
}

void MyClass::setAge(int value)
{
    age = value;
}