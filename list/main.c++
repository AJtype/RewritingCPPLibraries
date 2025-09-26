#include "list.hpp"
#include <iostream>

void print_list(list<int>l); // TODO: make const
void check_copyConstructor();
void check_clear();
void check_unique();
void check_erase();

int main() {
    // list<int> l;

    // std::cout << "empty list = {";
    // for (size_t i = 0; i < l.size(); i++) {
    //     std::cout << l[i] << ", ";
    // } std::cout << "}" << std::endl;

    // l.emplace_front(2);
    // l.emplace_back(1);
    // l.emplace_front(4);
    // l.emplace_back(3);

    // std::cout << "list = {";
    // for (size_t i = 0; i < l.size(); i++) {
    //     std::cout << l[i] << ", ";
    // } std::cout << "}" << std::endl;

    // std::cout << "list first element = " << l.front() << "\tlast element = " << l.back() << std::endl;

    // std::cout << "list's last element " << l.pop_back() << " has been popped, now the new back is " << l.back() << std::endl;

    // std::cout << "list = {";
    // for (size_t i = 0; i < l.size(); i++) {
    //     std::cout << l[i] << ", ";
    // } std::cout << "}" << std::endl;

    // std::cout << "list's first element " << l.pop_front() << " has been popped, now the new head is " << l.front() << std::endl;

    // std::cout << "list = {";
    // for (size_t i = 0; i < l.size(); i++) {
    //     std::cout << l[i] << ", ";
    // } std::cout << "}" << std::endl;

    // check_copyConstructor();

    // check_clear();

    // check_unique();
    
    check_erase();

    return 0;
}

void print_list(list<int> l) {
    std::cout << "{";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;
}

void check_copyConstructor() { // TODO: bug
    list<int> l;

    std::cout << "\n---testing = func---" << std::endl;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    list<int> copiedList = l;
    std::cout << "copiedList before deleting the original list = ";
    print_list(copiedList);

    l.clear();
    // copiedList = copiedList; // TODO: test
    std::cout << "copiedList after deleting the original list = ";
    print_list(copiedList);

    std::cout << "---end of = test---\n" << std::endl;
}

void check_clear() {
    list<int> l;
    
    std::cout << "\n---testing clear func---" << std::endl;

    std::cout << "empty list = ";
    print_list(l);

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = ";
    print_list(l);

    l.clear();
    std::cout << "cleared list = ";
    print_list(l);

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = ";
    print_list(l);

    std::cout << "---end of clear test---\n" << std::endl;
}

void check_unique() {
    list<int> l;
    
    std::cout << "\n---testing unique func---" << std::endl;

    l.emplace_back(1);
    l.emplace_back(1);
    l.emplace_back(2);
    l.emplace_back(2);
    l.emplace_back(2);
    l.emplace_back(3);
    l.emplace_back(2);
    l.emplace_back(1);
    l.emplace_back(1);
    l.emplace_back(2);
    l.emplace_back(2);

    std::cout << "pre-unique list = ";
    print_list(l);

    l.unique();
    std::cout << "post-unique list = ";
    print_list(l);

    std::cout << "---end of unique test---\n" << std::endl;
}

void check_erase() {
    list<int> l;
    
    std::cout << "\n---testing erase func---" << std::endl;

    l.emplace_back(1);
    l.emplace_back(2);
    l.emplace_back(3);
    l.emplace_back(4);
    l.emplace_back(5);
    l.emplace_back(6);
    l.emplace_back(7);
    l.emplace_back(8);
    l.emplace_back(9);
    l.emplace_back(10);
    l.emplace_back(11);

    std::cout << "len = " << l.size() << "\t";
    std::cout << "pre-erase list = ";
    print_list(l);
    
    std::cout << "len = " << l.size() << "\t";
    std::cout << "post-erase front list = ";
    l.erase(0);
    print_list(l);

    std::cout << "len = " << l.size() << "\t";
    std::cout << "post-erase front again list = ";
    l.erase(0);
    print_list(l);

    
    std::cout << "len = " << l.size() << "\t";
    std::cout << "post-erase second list = ";
    l.erase(1);
    print_list(l);

    std::cout << "len = " << l.size() << "\t";
    std::cout << "post-erase before last list = ";
    l.erase(6);
    print_list(l);

    std::cout << "len = " << l.size() << "\t";
    std::cout << "post-erase last list = ";
    l.erase(6); // problem here
    print_list(l);

    std::cout << "---end of erase test---\n" << std::endl;
}
