#include "pair.hpp"
#include <iostream>

int main() {
    pair<int, int> withNumbers(1, 2);
    pair<int, char> withoutVars;

    withoutVars.first = 3;
    withoutVars.second = 'c';

    std::cout << withNumbers.first << ", " << withNumbers.second << std::endl;
    std::cout << withoutVars.first << ", " << withoutVars.second << std::endl;

    return 0;
}