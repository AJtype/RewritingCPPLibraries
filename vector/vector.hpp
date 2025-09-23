#pragma once
#include <iostream>

template<typename T>
class vector { // TODO: add type specific vector for bool to optimize space efficiency
private:
    size_t typeSize;
    size_t arrSize;
    T* arr;

public:
    // Constructors
    // vector(); // default constructor
    explicit vector(const size_t& count);  // count constructor
    // vector(size_t count, const T& value);  // count-value constructor
    // vector(const vector& other) = default; // copy constructor
    // vector(vector&& other) = default; // move constructor
    // template<typename ... Args> vector(Args&& ... args); // uniform constructor

    // Getters & Setters
    T& operator[](const int pos);
};

// template <typename T>
// inline vector<T>::vector() : arr(nullptr), arrSize(0) {}

template <typename T>
inline vector<T>::vector(const size_t &count)
    : arr(new T[count]) {}

// template <typename T>
// inline vector<T>::vector(size_t count, const T &value)
//     : arr(new T[count]), arrSize(count), typeSize(sizeof(T))
// {
//     for (size_t i = 0; i < count; i++)
//     {
//         arr[i] = value;
//     }
// }

// template <typename T>
// template <typename... Args>
// inline vector<T>::vector(Args &&...args) {}

template <typename T>
inline T& vector<T>::operator[](const int pos) {
    return arr[pos];
}

template <typename T>
inline void printVector(vector<T> vec)
{
    std::cout << "vec = {";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << vec[i] << ", ";
    } std::cout << "}" << std::endl;
}
