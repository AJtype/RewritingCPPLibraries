#include "list.hpp"
#include <iostream>

int main() {
    list<int> l;

    l.emplace_back(2);

    std::cout << "list = {";
    for (size_t i = 0; i < 1; i++)
    {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    return 0;
}