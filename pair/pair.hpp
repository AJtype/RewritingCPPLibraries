#pragma once
#include <utility>

template<typename T1, typename T2>
struct pair{
public:
    T1 first;
    T2 second;

    // constructor declarations
    pair();
    explicit pair(const T1& x, const T2& y);
    pair(const pair&) = default;
    pair(pair&&) = default;
    pair<T1, T2>& operator=(const pair& other);

    // funcs
    void swap(pair& other) noexcept;
private:
};

// funcs
// Default constructor
template <typename T1, typename T2>
inline pair<T1, T2>::pair() : first(T1()), second(T2()) {}

// Two-argument constructor
template<typename T1, typename T2>
pair<T1, T2>::pair(const T1& x, const T2& y)
    : first(x), second(y) {}

template <typename T1, typename T2>
inline pair<T1, T2>& pair<T1, T2>::operator=(const pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }

    return *this;
}

template <typename T1, typename T2>
inline void pair<T1, T2>::swap(pair& other) noexcept
{
    std::swap(first, other.first); // TODO: replace with my swap
    std::swap(second, other.second);
}
