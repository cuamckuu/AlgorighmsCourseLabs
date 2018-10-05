#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <iostream>

struct Node {
    int value = 0;
    Node *prev = nullptr;
    Node *next = nullptr;
};

struct List {
    Node *head = nullptr;
    Node *tail = nullptr;

    ~List();

    void push_back(int);
    void push_front(int);

    void pop_back();
    void pop_front();

    void insert_before(size_t, int);
    int at(size_t);

    void remove(size_t);
    size_t size();
    void display();
    void clear();
    void set(size_t, int);
    bool isEmpty();

    bool contains(int);
    bool contains(List &rhs);
};


#endif //LIST_H
