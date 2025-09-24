#pragma once
#include <utility>

template<typename T>
class list{ // doubly linked list
private:
    struct node
    {
        T value;
        T* next;
        T* prev;
    };
    
    node* head;
    node* end;
    unsigned int size;

public:
    // constructor declarations
    list();
    list(const list&) = default;
    list(list&&) = default;
    list<T>& operator=(const list& other);

    // funcs
    void swap(list& other) noexcept;
};

// funcs