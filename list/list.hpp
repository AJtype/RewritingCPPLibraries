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
    list<T>& operator=(const list& other); // TODO: bug, if you change the original list the copied list fucks up

    // getter
    unsigned int size();
    T& front();
    T& back();
    T pop_back();
    T pop_front();
    T erase(unsigned int pos); // TODO: return iterator

    // setters
    void emplace_front(const T& value); // TODO: replace with Args&&... args
    void emplace_back(const T& value); // TODO: replace with Args&&... args
    // void insert() // TODO
    T& operator[](const int& pos);

    // funcs
    bool empty();
    void swap(list& other) noexcept;
    void clear();
    void merge();
    void reverse();
    void unique();
    void sort();
};

// constructors
// default constructor
template <typename T>
inline list<T>::list() :
    head(nullptr), end(nullptr), length(0) {}

template <typename T>
inline list<T> &list<T>::operator=(const list &other) {
    if (!empty())
    {
        clear();
    }
    
    for (unsigned int i = 0; i < other.size(); i++) {
        emplace_back(other[i]);
    }
    
    return this;
}

template <typename T>
inline unsigned int list<T>::size()
{
    return length;
}

template <typename T>
inline T& list<T>::front()
{
    return head->value;
}

template <typename T>
inline T& list<T>::back()
{
    return end->value;
}

template <typename T>
inline T list<T>::pop_back() {
    node* popped = end;
    T val = popped->value;

    end = popped->prev;
    if (end) {
        end->next = nullptr;
    } else { // empty list
        head = nullptr;
    }

    delete popped;
    length--;

    return val;
}

template <typename T>
inline T list<T>::pop_front() {
    if (empty())
        throw std::out_of_range("pop_front() called on an empty list");
    
    node* popped = head;
    T val = popped->value;

    head = popped->next;
    if (head) {
        head->prev = nullptr;
    } else { // empty list
        end = nullptr;
    }

    delete popped;
    length--;

    return val;
}

template <typename T>
inline void list<T>::emplace_front(const T &value) {
    node* prevHead = head;

    // add a new node at the beginning of the list
    head = new node();
    head->value = value;
    head->next = prevHead; // point to the previous start
    head->prev = nullptr;

    if (empty())
        end = head;
    else
        prevHead->prev = head;
    length++;
}

template <typename T>
inline void list<T>::emplace_back(const T& value) {
    if (empty()) {
        head = new node();
        head->value = value;
        head->next = nullptr;
        head->prev = nullptr;
        end = head;
    } else {
        node* temp = new node();
        temp->value = value;
        temp->next = nullptr;
        temp->prev = end;
        end->next = temp;
        end = end->next;
    } length++;
}

template <typename T>
inline T& list<T>::operator[](const int &pos) {
    node* curr = head;
    
    for (unsigned int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    
    return curr->value;
}

template <typename T>
inline bool list<T>::empty() {
    return length == 0;
}

template <typename T>
inline void list<T>::clear() {    
    while (length != 0) {
        pop_front();
    }
}
