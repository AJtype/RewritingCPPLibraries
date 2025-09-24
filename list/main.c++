#include "list.hpp"
#include <iostream>

int main() {
    list<int> l;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    return 0;
}