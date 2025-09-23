#include "vector.hpp"

int main() {
    // empty vec
    vector<int> emptyVec(5);

    for (size_t i = 0; i < 5; i++)
    {
        emptyVec[i] = i;
    }
    
    printVector(emptyVec);
    
    // calloced vector
    vector<int> all2Vec(5, 2);
    
    printVector(all2Vec);

    return 0;
}