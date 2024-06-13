#ifndef EXHIBITION_H
#define EXHIBITION_H

#include <vector>
#include <memory>
#include "ab.h"

class Exhibition {
private:
    std::vector<std::unique_ptr<Ab>> items;
public:
    Exhibition();
    void addItem(std::unique_ptr<Ab> item);
    void displayAll() const;
    void displayBySize(double targetSize) const;
    void displayByPriceRange(double minPrice, double maxPrice) const;
    void displayStatistics() const;

};

#endif
