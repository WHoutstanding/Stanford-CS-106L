#include <iostream>

class MyClass {
public:
    int number;
    MyClass();
    MyClass(std::string name);
    std::string getID() const;
    void setAge(int value);

private:
    int age;
    std::string ID;
    void addAge();
};