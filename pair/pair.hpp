#pragma once

template<typename T1, typename T2>
struct pair{
public:
    T1 first;
    T2 second;

    // constructor declarations
    pair();
    pair(const T1& x, const T2& y);
    pair(const pair<T1, T2>& obj);
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
