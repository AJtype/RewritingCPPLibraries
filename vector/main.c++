#include <iostream>
#include "vector.hpp"

int main() {
    vector<int> vec(5);

    for (size_t i = 0; i < 5; i++)
    {
        vec[i] = i;
    }

    std::cout << "vec = {";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << vec[i] << ", ";
    } std::cout << "}" << std::endl;
    

    return 0;
}