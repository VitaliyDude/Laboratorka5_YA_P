// В классе "ab.cpp"

#include "ab.h"
#include <iostream>

Ab::Ab(const std::string& name, double size, double price)
    : name(name), size(size), price(price) {}

Ab::~Ab() {}

void Ab::display() const {
    std::cout << "Тип: " << myName() << ", Размер: " << size << ", Цена: $" << price << std::endl;
}

double Ab::getSize() const {
    return size;
}

double Ab::getPrice() const {
    return price;
}
