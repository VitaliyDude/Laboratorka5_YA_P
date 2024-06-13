// В классе "ab.h"

#ifndef AB_H
#define AB_H

#include <string>

class Ab {
public:
    Ab() = default; // Добавляем конструктор по умолчанию
    Ab(const std::string& name, double size, double price);
    virtual ~Ab();

    virtual std::string myName() const = 0;
    virtual void display() const;

    double getSize() const;
    double getPrice() const;

protected:
    std::string name;
    double size;
    double price;
};

#endif // AB_H
