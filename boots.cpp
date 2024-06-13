// В файле "boots.cpp"

#include "boots.h"
#include <iostream>
#include <fstream> 
#include "exhibition.h"
Exhibition expo;

Boots::Boots() : Ab(), material(""){}

Boots::Boots(const std::string& name, double size, double price, const std::string& material )
    : Ab(name, size, price), material(material) {}

std::string Boots::myName() const { // Определение виртуальной функции
    return "Сапоги";
}

void Boots::display() const {
    Ab::display();
    std::cout << "Материал: " << material << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Boots& boots) {
    os << "Тип: " << boots.myName() << ", Размер: " << boots.getSize() << ", Цена: $" << boots.getPrice() << ", Материал: " << boots.material;
    return os;
}

void Boots::inputData() {
    std::cout << "Введите данные для сапогов:\n";
    std::cout << "Название: ";
    std::cin >> name;
    std::cout << "Размер: ";
    std::cin >> size;
    std::cout << "Цена: ";
    std::cin >> price;
    std::cout << "Материал: ";
    std::cin >> material;

}

void Boots::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> name >> size >> price >> material;
        file.close();
    } else {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
    }
}

void Boots::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << name << " " << size << " " << price << " " << material << std::endl;
        file.close();
    } else {
        std::cerr << "Ошибка открытия файла " << filename << " для записи" << std::endl;
    }
}