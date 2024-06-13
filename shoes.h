// В файле "shoes.h"

#ifndef SHOES_H
#define SHOES_H

#include "ab.h"
#include <string>
#include <fstream> 

class Shoes : public Ab {
public:
    Shoes();
    Shoes(const std::string& name, double size, double price, const std::string& style);

    virtual std::string myName() const override; // Определение виртуальной функции

    virtual void display() const override;

    std::string style;

    void inputData(); // Метод для ввода данных с клавиатуры
    void readFromFile(const std::string& filename); // Метод для считывания данных из файла
    void writeToFile(const std::string& filename) const; // Метод для записи данных в файл
};

#endif // SHOES_H
