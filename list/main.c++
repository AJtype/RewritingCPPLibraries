#include "list.hpp"
#include <iostream>

int main() {
    list<int> l;

    std::cout << "empty list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    l.clear();
    std::cout << "cleared list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    std::cout << "list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    std::cout << "list first element = " << l.front() << "\tlast element = " << l.back() << std::endl;

    std::cout << "list's last element " << l.pop_back() << " has been popped, now the new back is " << l.back() << std::endl;

    std::cout << "list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    std::cout << "list's first element " << l.pop_front() << " has been popped, now the new head is " << l.front() << std::endl;

    std::cout << "list = {";
    for (size_t i = 0; i < l.size(); i++) {
        std::cout << l[i] << ", ";
    } std::cout << "}" << std::endl;

    list<int> copiedList = l;
    std::cout << "copiedList = {";
    for (size_t i = 0; i < copiedList.size(); i++) {
        std::cout << copiedList[i] << ", ";
    } std::cout << "}" << std::endl;

    return 0;
}