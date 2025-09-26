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
    list(const list&);
    list(list&&) = default; // TODO: untested
    ~list(); // TODO: remove all the allocated memory
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

// copy constructor
template <typename T>
list<T>::list(const list& other) : head(nullptr), end(nullptr), length(0) {
    for (node* curr = other.head; curr; curr = curr->next) {
        emplace_back(curr->value);
    }
}

template <typename T>
inline list<T>::~list() {
    clear();
}

template <typename T>
inline list<T> &list<T>::operator=(const list &other)
{                                     // untested
    if (this == &other) return *this; // TODO: test without

    if (!empty()) clear();
    
    for (node* curr = other.head; curr; curr = curr->next) {
        emplace_back(curr->value);
    }
    
    return *this;
}

template <typename T>
inline unsigned int list<T>::size() {
    return length;
}

template <typename T>
inline T& list<T>::front() {
    return head->value;
}

template <typename T>
inline T& list<T>::back() {
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
inline T list<T>::erase(unsigned int pos) {
    node* itr = head;

    if (0 > pos || pos > length || empty()) {
        throw std::out_of_range("tried to erase out of range of list");
    }
    
    if (0 == pos) { // erase beginning
        return pop_front();
    } if (pos == length-1) { // erase end
        return pop_back();
    }

    // get to element
    for (size_t i = 0; i < pos; i++) {
        itr = itr->next;
    }
    T val = itr->value;
    
    // deal with pointers
    itr->prev->next = itr->next;
    itr->next->prev = itr->prev;

    delete(itr);
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

template <typename T>
inline void list<T>::unique() {
    if (length < 2) // too short to have duplicates
        return;

    node* itr = head->next;

    while (itr) {
        if (itr->value == itr->prev->value) {
            node* toDelete = itr;

            itr->prev->next = itr->next;

            if (itr->next) {
                itr->next->prev = itr->prev;
            } else {
                end = itr->prev;
            }

            itr = itr->next;
            delete toDelete;
            length--;
        } else {
            itr = itr->next;
        }
    }
}
