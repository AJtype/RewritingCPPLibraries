#pragma once
#include <iostream>

template<typename T>
class list{ // doubly linked list
private:
    struct node
    {
        T value;
        node* next;
        node* prev;
    };
    
    node* head;
    node* end;
    unsigned int length;

public:
    // constructor declarations
    list();
    list(const list&) = default; // TODO: untested
    list(list&&) = default; // TODO: untested
    ~list() = default; // TODO: remove all the allocated memory
    list<T>& operator=(const list& other);

    // getter setters
    unsigned int size();
    void emplace_front(const T& value); // TODO: replace with Args&&... args
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
    head(nullptr), end(nullptr), length(0) {}

template <typename T>
inline list<T> &list<T>::operator=(const list &other) { // TODO
    for (unsigned int i = 0; i < other.size(); i++)
    {
        /* code */
    }
    
    return this;
}

template <typename T>
inline unsigned int list<T>::size()
{
    return length;
}

template <typename T>
inline void list<T>::emplace_front(const T &value)
{    
    node* temp = head;

    head = new node();
    head->value = value;
    head->next = temp;
    head->prev = nullptr;

    if (empty())
        end = head;
    length++;
}

template <typename T>
inline void list<T>::emplace_back(const T &value)
{
    if (empty()) {
        head = new node();
        head->value = value;
        head->next = nullptr;
        head->prev = nullptr;
        end = head;
    } else {
        node* temp = new node();
        temp->value = value;
        temp->next = end;
        temp->prev = nullptr;
        end->next = temp;
        end = end->next;
    } length++;
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
    return length == 0;
}
