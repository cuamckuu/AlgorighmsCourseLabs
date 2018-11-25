#include "include/drawer.h"

void Drawer::print_at(const size_t x, const size_t y, const int val) {
    std::string num = std::to_string(val);

    if (x + num.size() >= width) {
        throw std::out_of_range("Screen size is too smal");
    }

    for (int i = 0; i < num.size(); i++) {
        screen[y][x+i] = num[i];
    }
}

void Drawer::display() const{
    std::cout << "\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << screen[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

Drawer::Drawer(const size_t width, const size_t height)
    :width(width)
    ,height(height)
{
    screen = new char*[height];
    for (size_t i = 0; i < height; i++) {
        screen[i] = new char[width];
        for (size_t j = 0; j < width; j++) {
            screen[i][j] = ' ';
        }
    }
}

Drawer::~Drawer() {
    for (size_t i = 0; i < height; i++) {
        delete[] screen[i];
    }
    delete[] screen;
}
