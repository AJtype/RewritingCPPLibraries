#pragma once

template<typename T>
class vector { // TODO: add type specific vector for bool to optimize space efficiency
private:
    unsigned int typeSize;
    unsigned int arrSize;
    T* arr;

public:
    explicit vector(const unsigned int& count); // TODO
    vector(size_t count, const T& value);
    vector(const vector& other) = default;
    vector(vector&& other) = default;
    template<typename ... Args>
    vector(Args&& ... args);
};

template <typename T>
inline vector<T>::vector(size_t count, const T& value) : arr(new T[count]), arrSize(count), typeSize(sizeof(T))
{
    for (size_t i = 0; i < count; i++)
    {
        arr[i] = value;
    }
}