#include "pair.hpp"
#include <iostream>
#include <string>

int main() {
    pair<int, int> withNumbers(1, 2);
    pair<int, int> withoutVars;

    withoutVars.first = 3;
    withoutVars.second = 4;
    pair<int, int> copy(withoutVars);

    std::cout << "withNumbers = " << withNumbers.first << ", " << withNumbers.second << std::endl;
    std::cout << "withoutVars = " << withoutVars.first << ", " << withoutVars.second << std::endl;
    std::cout << "copy of withoutVars = " << copy.first << ", " << copy.second << std::endl;

    withoutVars = withNumbers;
    std::cout << "\nwithoutVars = withNumbers = " << withoutVars.first << ", " << withoutVars.second << std::endl;
    
    withoutVars.swap(copy);
    std::cout << "\nswapped withoutVars and copy" << std::endl;
    std::cout << "copy = " << copy.first << ", " << copy.second << std::endl;
    std::cout << "withoutVars = " << withoutVars.first << ", " << withoutVars.second << std::endl;

    pair<int, std::string> original(1, "Hello");
    pair<int, std::string> movedPair(std::move(original));
    std::cout << "\nmovedPair = " << movedPair.first << ", " << movedPair.second << std::endl;
    std::cout << "original after move = " << original.first << ", " << original.second << std::endl;

    return 0;
}