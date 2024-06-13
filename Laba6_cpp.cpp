//#include <iostream>
//#include <fstream>
//#include <string>
//#include "ab.h"
//#include "boots.h"
//#include "shoes.h"
//#include "exhibition.h"
//#include <windows.h>
//
//void displayMenu(Boots& boots, Shoes& shoes, Exhibition& ex) {
//    int choice;
//
//    do {
//
//        std::cout << "Меню работы с обувью:\n";
//        std::cout << "1. Заполнить данные о сапогах с клавиатуры\n";
//        std::cout << "2. Заполнить данные о туфлях с клавиатуры\n";
//        std::cout << "3. Заполнить данные о сапогах из файла\n";
//        std::cout << "4. Заполнить данные о туфлях из файла\n";
//        std::cout << "5. Показать данные о сапогах\n";
//        std::cout << "6. Показать данные о  туфлях\n";
//        std::cout << "7. Записать данные о сапогах в файл\n";
//        std::cout << "8. Записать данные о туфлях в файл\n";
//        std::cout << "9. Показать данные об обуви с ценой в заданном диапазоне\n";
//        std::cout << "10. Показать статистическую сводку\n";
//        std::cout << "0. Выход\n";
//
//        std::cout << "Выберите действие: ";
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1:
//            std::cout << "Заполнить данные о сапогах с клавиатуры:\n"; // сапоги с клавы
//            boots.inputData();
//            break;
//        case 2:
//            std::cout << "Заполнить данные о туфлях с клавиатуры:\n"; // туфли с клавы
//            shoes.inputData();
//            break;
//        case 3:
//            std::cout << "Заполнить данные о сапогах из файла" << std::endl; // сапоги из файла
//            boots.writeToFile("boots.txt");
//            break;
//        case 4:
//            std::cout << "Заполнить данные о туфлях из файла" << std::endl; // туфли из фала
//            shoes.writeToFile("shoes.txt");
//            break;
//        case 5:
//            boots.display(); // показать сапоги
//            break;
//        case 6:
//            shoes.display(); // показать туфли
//            break;
//        case 7:
//            std::cout << "Записать данные о сапогах в файл" << std::endl;
//            boots.readFromFile("boots.txt");
//            break;
//        case 8:
//            std::cout << "Записать данные о туфлях в файл" << std::endl;
//            shoes.readFromFile("shoes.txt");
//            break;
//        case 9:
//            std::cout << "Обувь в ценовом диапазоне:\n";
//            double minPrice, maxPrice;
//            std::cout << "\nВведите минимальную цену: ";
//            std::cin >> minPrice;
//            std::cout << "Введите максимальную цену: ";
//            std::cin >> maxPrice;
//            std::cout << "\nОбувь с ценой от $" << minPrice << " до $" << maxPrice << ":" << std::endl;
//            ex.displayByPriceRange(minPrice, maxPrice);
//            break;
//        case 10:
//            ex.displayStatistics();
//            break;
//        case 0:
//            std::cout << "Выход из программы\n";
//            break;
//        default:
//            std::cout << "Неверный выбор, попробуйте еще раз\n";
//            break;
//        }
//    } while (choice != 0);
//}
//
//int main() 
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251); //Русификация консоли
//    Boots boots;
//    Shoes shoes;
//    Exhibition ex;
//    ex.addItem(make_unique<Boots>("Туристические сапоги", 9.5, 99.99, "Кожа"));
//    ex.addItem(make_unique<Shoes>("Женские туфли", 10.0, 49.99, "Сетка"));
//    displayMenu(boots, shoes, ex);
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
#include "ab.h"
#include "boots.h"
#include "shoes.h"
#include "exhibition.h"
#include <windows.h>

using namespace std;

void displayMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Введите данные об обуви" << endl;
    cout << "2. Вывести все товары на экспозиции" << endl;
    cout << "3. Вывести обувь с заданным размером" << endl;
    cout << "4. Вывести обувь в заданном ценовом диапазоне" << endl;
   // cout << "5. Вывести статистику" << endl;
    cout << "0. Закончить работу с программой" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //Русификация консоли

    Exhibition expo;
   
    std::string type = "";
    std::string  name = "";
    double  sizze = 0;
    double  price = 0;
    std::string material = "";
    std::string style = "";

    int choice;
    do {
        displayMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n Введите данные об обуви." << endl;
            cout << "Укажите тип обуви (Туфли, Ботинки): ";
            cin >> type;
            if (type == "Туфли" || type == "туфли")
            {
                cout << "Укажите название обуви: ";
                cin >> name;
                cout << "Укажите размер обуви:";
                cin >> sizze;
                cout << "Укажите цену обуви:";
                cin >> price;
                cout << "Укажите стиль обуви: ";
                cin >> style;
                expo.addItem(make_unique<Shoes>(name, sizze, price, style));
            }
            else if (type == "Ботинки" || type == "ботинки")
            {
                cout << "Укажите название обуви: ";
                cin >> name;
                cout << "Укажите размер обуви:";
                cin >> sizze;
                cout << "Укажите цену обуви:";
                cin >> price;
                cout << "Укажите материал обуви: ";
                cin >> material;
                expo.addItem(make_unique<Boots>(name, sizze, price, material));
            }
            else
            {
                cout << "\n Неверно указан тип обуви, проверте, правильность ввода данных!";
            }
            break;
        case 2:
            cout << "\nПоказать обувь:" << endl;
            expo.displayAll();
            break;
        case 3:
            double size;
            cout << "\nВведите размер: ";
            cin >> size;
            cout << "Обувь размером " << size << ":" << endl;
            expo.displayBySize(size);
            break;
        case 4:
            double minPrice, maxPrice;
            cout << "\nВведите минимальную цену: ";
            cin >> minPrice;
            cout << "Введите максимальную цену: ";
            cin >> maxPrice;
            cout << "Обувь с ценой от $" << minPrice << " до $" << maxPrice << ":" << endl;
            expo.displayByPriceRange(minPrice, maxPrice);
            break;
       /* case 5:
            cout << "\nСтатистика:" << endl;

            expo.displayStatistics();
            break;*/
        case 0:
            cout << "\nЗавершение работы с программой." << endl;
            break;
        default:
            cout << "\nНеверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
