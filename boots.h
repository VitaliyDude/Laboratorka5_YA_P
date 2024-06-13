// � ����� "boots.h"

#ifndef BOOTS_H
#define BOOTS_H

#include "ab.h"
#include <string>
#include <fstream> 

class Boots : public Ab {
public:
    Boots();
    Boots(const std::string& name, double size, double price, const std::string& material);

    virtual std::string myName() const override; // ����������� ����������� �������

    virtual void display() const override;
    std::string material;

    void inputData(); // ����� ��� ����� ������ � ����������
    void readFromFile(const std::string& filename); // ����� ��� ���������� ������ �� �����
    void writeToFile(const std::string& filename) const; // ����� ��� ������ ������ � ����

};

#endif // BOOTS_H
