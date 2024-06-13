// В файле "boots.h"

#ifndef BOOTS_H
#define BOOTS_H

#include "ab.h"
#include <string>
#include <fstream> 

class Boots : public Ab {
public:
    Boots();
    Boots(const std::string& name, double size, double price, const std::string& material);

    virtual std::string myName() const override; // Определение виртуальной функции

    virtual void display() const override;
    std::string material;

    void inputData(); // Метод для ввода данных с клавиатуры
    void readFromFile(const std::string& filename); // Метод для считывания данных из файла
    void writeToFile(const std::string& filename) const; // Метод для записи данных в файл

};

#endif // BOOTS_H
