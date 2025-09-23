#include <iostream>
#include "vector.hpp"

int main() {
    vector<int> vec(5, 2);

    std::cout << "vec = {";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << vec.arr[i] << ", ";
    } std::cout << "}" << std::endl;
    

    return 0;
}