#include "vector.hpp"

int main() {
    vector<int> vec(5);

    for (size_t i = 0; i < 5; i++)
    {
        vec[i] = i;
    }
    
    printVector(vec);

    return 0;
}