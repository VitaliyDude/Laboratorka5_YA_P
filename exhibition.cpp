#include "exhibition.h"
#include "boots.h"
#include "shoes.h"
#include <iostream>

Exhibition::Exhibition() {}

void Exhibition::addItem(std::unique_ptr<Ab> item) {
    items.push_back(std::move(item));
}

void Exhibition::displayAll() const {
    for (const auto& item : items) {
        item->display();
    }
}

void Exhibition::displayBySize(double targetSize) const {
    for (const auto& item : items) {
        // Проверяем тип объекта и выводим только объекты с соответствующим размером
        if (item->getSize() == targetSize) {
            item->display();
        }
    }
}

void Exhibition::displayByPriceRange(double minPrice, double maxPrice) const {
    for (const auto& item : items) {
        if (item->getPrice() >= minPrice && item->getPrice() <= maxPrice) {
            item->display();
        }
    }
}

void Exhibition::displayStatistics() const {
    // Реализация статистики
}
