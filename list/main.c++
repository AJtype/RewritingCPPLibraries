#include "list.hpp"
#include <iostream>

void check_operatorEqual();

void check_clear();

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

    // check_operatorEqual();

    check_clear();

    return 0;
}

void check_operatorEqual() {
    list<int> l;

    l.emplace_front(2);
    l.emplace_back(1);
    l.emplace_front(4);
    l.emplace_back(3);

    list<int> copiedList = l;
    std::cout << "copiedList before deleting the original list = {";
    for (size_t i = 0; i < copiedList.size(); i++) {
        std::cout << copiedList[i] << ", ";
    } std::cout << "}" << std::endl;

    l.clear();
    std::cout << "copiedList after deleting the original list = {";
    for (size_t i = 0; i < copiedList.size(); i++) {
        std::cout << copiedList[i] << ", ";
    } std::cout << "}" << std::endl;
}

void check_clear() {
    list<int> l;
    
    std::cout << "\n---testing clear func---" << std::endl;

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

    std::cout << "---end of clear test---\n" << std::endl;
}
