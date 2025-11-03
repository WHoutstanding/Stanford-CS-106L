#include "intvector.h"
#include "MyVector.h"
#include <iostream>

// int checkIntVector(IntVector& vec)

int main() {
    IntVector vec1 vec2;
    
    vec1.push_back(1);
    vec1.push_back(2);

    vec2.push_back(3);
    vec2.push_back(4);

    IntVector vec3 = vec1 + vec2;

    // std::cout << vec1.size() << " " << vec3.size() << std::endl;
    std::cout << vec3 << std::endl;
    // test harness
    return 0;
}
