#include "pair.hpp"
#include <iostream>

int main() {
    pair<int, int> withNumbers(1, 2);

    std::cout << withNumbers.first << ", " << withNumbers.second << std::endl;

    return 0;
}