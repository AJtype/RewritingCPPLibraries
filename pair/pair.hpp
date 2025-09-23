#pragma once
#include <utility>

template<typename T1, typename T2>
struct pair{
public:
    T1 first;
    T2 second;

    // constructor declarations
    pair();
    pair(const T1& x, const T2& y);
    pair(const pair<T1, T2>& obj);
    pair<T1, T2> operator=(const pair<T1, T2>& other);

    // funcs
    void swap(pair<T1, T2>& other);
private:
};

// funcs
// Default constructor
template <typename T1, typename T2>
inline pair<T1, T2>::pair() : first(T1()), second(T1()) {}

// Two-argument constructor
template<typename T1, typename T2> // TODO: move to c++ file
pair<T1, T2>::pair(const T1& x, const T2& y)
    : first(x), second(y) {}

// Copy constructor
template <typename T1, typename T2>
inline pair<T1, T2>::pair(const pair<T1, T2>& obj)
     : first(obj.first), second(obj.second) {}

template <typename T1, typename T2>
inline pair<T1, T2> pair<T1, T2>::operator=(const pair<T1, T2>& other) {
    first = other.first;
    second = other.second;

    return *this;
}

template <typename T1, typename T2>
inline void pair<T1, T2>::swap(pair<T1, T2>& other)
{
    std::swap(first, other.first); // TODO: replace with my swap
    std::swap(second, other.second);
}
