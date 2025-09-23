#pragma once

template<typename T>
class vector { // TODO: add type specific vector for bool to optimize space efficiency
private:
    unsigned int typeSize;
    unsigned int arrSize;
    T* arr;

public:
    explicit vector(const unsigned int& count); // TODO
    vector(const unsigned int& count, const T& value);
    vector(const vector& other) = default;
    vector(vector&& other) = default;
    template<typename ... Args>
    vector(Args&& ... args);
};
