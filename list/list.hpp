#pragma once
#include <utility>

template<typename T>
class list{ // doubly linked list
public:
    struct node
    {
        T value;
        node* next;
        node* prev;
    };
    
    node* head;
    node* end;
    unsigned int size;

public:
    // constructor declarations
    list();
    list(const list&) = default; // TODO: untested
    list(list&&) = default; // TODO: untested
    ~list() = default; // TODO: remove all the allocated memory
    list<T>& operator=(const list& other);

    // getter setters
    void emplace_back(const T& value); // TODO: replace with Args&&... args
    T& operator[](const int& pos); // TODO: untested

    // funcs
    bool empty(); // TODO: unfinished
    void swap(list& other) noexcept;
};

// constructors
// default constructor
template <typename T>
inline list<T>::list() :
    head(nullptr), end(nullptr), size(0) {}

template <typename T>
inline void list<T>::emplace_back(const T &value)
{
    if (empty()) {
        // std::cout << "emplace back empty" << std::endl;
        head = new node();
        head->value = value;
        head->next = nullptr;
        head->prev = nullptr;
        end = head;
    } else {
        // std::cout << "emplace back not empty" << std::endl;
        end->next = new node();
        head->value = value;
        head->next = end;
        head->prev = nullptr;
        end = end->next;
    } size++;
}

template <typename T>
inline T &list<T>::operator[](const int &pos)
{
    node* curr = head;
    
    for (unsigned int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    
    return curr->value;
}

template <typename T>
inline bool list<T>::empty()
{
    return true;
}
