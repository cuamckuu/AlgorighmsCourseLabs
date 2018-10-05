#include <iostream>
#include "include/unit.h"
#include "include/list.h"

int main() {
    test_all();

    List list;
    std::cout << "Create empty list: \n";
    std::cout << "Is Empty: " << list.isEmpty() << std::endl;
    std::cout << std::endl;

    std::cout << "Push back 6: \n";
    list.push_back(6);
    std::cout << "Is Empty: " << list.isEmpty() << std::endl;
    std::cout << std::endl;

    std::cout << "Remove element with index 0: \n";
    list.remove(0);
    std::cout << "Is Empty: " << list.isEmpty() << std::endl;
    std::cout << std::endl;

    std::cout << "Push front 7, Push back 8 and 9: \n";
    list.push_front(7);
    list.push_back(8);
    list.push_back(9);
    list.display();
    std::cout << std::endl;

    std::cout << "Pop front and pop back: \n";
    list.pop_front();
    list.pop_back();
    list.display();
    std::cout << std::endl;

    std::cout << "Push front 7, push back 9: \n";
    list.push_front(7);
    list.push_back(9);
    list.display();
    std::cout << std::endl;

    std::cout << "Display array using size() and at() methods: \n";
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Set element with index 0 to 100: \n";
    list.set((size_t)0, 100);
    list.display();
    std::cout << std::endl;

    std::cout << "Insert 200 before last element: \n";
    list.insert_before(list.size()-1, 200);
    list.display();
    std::cout << std::endl;

    std::cout << "Remove element with index 3: \n";
    list.remove(3);
    list.display();
    std::cout << std::endl;

    std::cout << "Create list A {1, 2, 3}: \n";
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    std::cout << "A: ";
    a.display();
    std::cout << std::endl;

    std::cout << "Create list B {1, 2}: \n";
    List b;
    b.push_back(1);
    b.push_back(2);
    std::cout << "B: ";
    b.display();
    std::cout << std::endl;

    std::cout << "A contains B: ";
    std::cout << a.contains(b) << std::endl;

    std::cout << "B contains A: ";
    std::cout << b.contains(a) << std::endl;

    return 0;
}
