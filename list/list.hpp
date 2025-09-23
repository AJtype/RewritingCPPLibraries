#pragma once
#include <utility>

template<typename T>
struct list{ // doubly linked list
public:
    // constructor declarations
    list();
    list(const list&) = default;
    list(list&&) = default;
    list<T>& operator=(const list& other);

    // funcs
    void swap(list& other) noexcept;
private:
};

// funcs