#include "pair.hpp"
#include <iostream>

int main() {
    pair<int, int> withNumbers(1, 2);
    pair<int, char> withoutVars;

    withoutVars.first = 3;
    withoutVars.second = 'c';
    pair<int, char> copy(withoutVars);

    std::cout << "withNumbers = " << withNumbers.first << ", " << withNumbers.second << std::endl;
    std::cout << "withoutVars = " << withoutVars.first << ", " << withoutVars.second << std::endl;
    std::cout << "copy = " << copy.first << ", " << copy.second << std::endl;

    return 0;
}