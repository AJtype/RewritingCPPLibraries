#include "pair.hpp"
#include <iostream>

int main() {
    pair<int, int> withNumbers(1, 2);
    pair<int, int> withoutVars;

    withoutVars.first = 3;
    withoutVars.second = 4;
    pair<int, int> copy(withoutVars);

    std::cout << "withNumbers = " << withNumbers.first << ", " << withNumbers.second << std::endl;
    std::cout << "withoutVars = " << withoutVars.first << ", " << withoutVars.second << std::endl;
    std::cout << "copy = " << copy.first << ", " << copy.second << std::endl;

    withoutVars = withNumbers;
    std::cout << "withoutVars = withNumbers = " << withoutVars.first << ", " << withoutVars.second << std::endl;

    return 0;
}