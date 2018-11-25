#ifndef DRAWER_H
#define DRWAER_H

#include <iostream>

class Drawer {
public:
    void print_at(const size_t x, const size_t y, const int val);
    void display() const;

    Drawer(const size_t width, const size_t height);
    ~Drawer();

private:
    char **screen = nullptr;
    const size_t width, height;
};

#endif //DRAWER_H
