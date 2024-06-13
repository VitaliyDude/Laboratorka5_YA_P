// В файле "shoes.cpp"

#include "shoes.h"
#include <iostream>
#include <fstream> 

Shoes::Shoes() : Ab(), style(""){}

Shoes::Shoes(const std::string& name, double size, double price, const std::string& style)
    : Ab(name, size, price), style(style) {}

std::string Shoes::myName() const { // Определение виртуальной функции
    return "Туфли";
}

void Shoes::display() const {
    Ab::display();
    std::cout << "Стиль: " << style << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Shoes& shoes) {
    os << "Тип: " << shoes.myName() << ", Размер: " << shoes.getSize() << ", Цена: $" << shoes.getPrice() << ", Стиль: " << shoes.style;
    return os;
}


void Shoes::inputData() {
    std::cout << "Введите данные для туфлей:\n";
    std::cout << "Название: ";
    std::cin >> name;
    std::cout << "Размер: ";
    std::cin >> size;
    std::cout << "Цена: ";
    std::cin >> price;
    std::cout << "Стиль: ";
    std::cin >> style;
}

void Shoes::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> name >> size >> price >> style;
        file.close();
    }
    else {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
    }
}

void Shoes::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << name << " " << size << " " << price << " " << style << std::endl;
        file.close();
    }
    else {
        std::cerr << "Ошибка открытия файла " << filename << " для записи" << std::endl;
    }
}