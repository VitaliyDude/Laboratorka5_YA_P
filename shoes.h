// � ����� "shoes.h"

#ifndef SHOES_H
#define SHOES_H

#include "ab.h"
#include <string>
#include <fstream> 

class Shoes : public Ab {
public:
    Shoes();
    Shoes(const std::string& name, double size, double price, const std::string& style);

    virtual std::string myName() const override; // ����������� ����������� �������

    virtual void display() const override;

    std::string style;

    void inputData(); // ����� ��� ����� ������ � ����������
    void readFromFile(const std::string& filename); // ����� ��� ���������� ������ �� �����
    void writeToFile(const std::string& filename) const; // ����� ��� ������ ������ � ����
};

#endif // SHOES_H
