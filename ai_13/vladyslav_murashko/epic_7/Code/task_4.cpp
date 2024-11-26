#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Information
{ // Використано структуру для структурізації даних
    char medium[50];
    int volume;
    char title[100];
    char author[50];
};

// Функція запису в файл
void create_file(const std::string &filename, const std::vector<Information> &elements)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cout << "Error: Cannot open file for writing.\n";
        return;
    }
    for (const auto &element : elements)
    {
        file.write(reinterpret_cast<const char *>(&element), sizeof(Information));
    }
    file.close();
}

// Функція зчитання з файлу
void print_file(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cout << "Error: Cannot open file for reading.\n";
        return;
    }
    Information element;
    while (file.read(reinterpret_cast<char *>(&element), sizeof(Information)))
    {
        std::cout << "Medium: " << element.medium << ", Volume: " << element.volume
                  << ", Title: " << element.title << ", Author: " << element.author << "\n";
    }
    file.close();
}

void delete_by_volume(const std::string &filename, int volume)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cout << "Error: Cannot open file for reading.\n";
        return;
    }

    std::vector<Information> elements;
    Information element;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&element), sizeof(Information)))
    {
        if (!found && element.volume == volume)
        {
            found = true;
            continue; // Пропускаємо перший елемент із заданим об’ємом
        }
        elements.push_back(element);
    }
    file.close();

    if (!found)
    {
        std::cout << "Element with volume " << volume << " not found.\n";
        return;
    }

    std::ofstream out_file(filename, std::ios::binary | std::ios::trunc);
    if (!out_file)
    {
        std::cout << "Error: Cannot open file for writing.\n";
        return;
    }
    for (const auto &elem : elements)
    {
        out_file.write(reinterpret_cast<const char *>(&elem), sizeof(Information));
    }
    out_file.close();
}

void insert_before_position(const std::string &filename, const Information &new_element, int position)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cout << "Error: Cannot open file for reading.\n";
        return;
    }

    std::vector<Information> elements;
    Information element;

    while (file.read(reinterpret_cast<char *>(&element), sizeof(Information))) // Цикл While щоб зчитати всі структури
    {
        elements.push_back(element);
    }
    file.close();

    if (position < 1 || position > elements.size() + 1)
    {
        std::cout << "Error: Invalid position.\n";
        return;
    }

    elements.insert(elements.begin() + position - 1, new_element);

    std::ofstream out_file(filename, std::ios::binary | std::ios::trunc);
    if (!out_file)
    {
        std::cout << "Error: Cannot open file for writing.\n";
        return;
    }
    for (const auto &elem : elements)
    {
        out_file.write(reinterpret_cast<const char *>(&elem), sizeof(Information));
    }
    out_file.close();
}

int main()
{
    std::string filename = "information.bin";

    // Приклад елементів для запису у файл
    std::vector<Information> elements = {
        {"CD", 700, "Learning C++", "Bjarne Stroustrup"},
        {"USB", 16000, "C++ Primer", "Stanley Lippman"},
        {"HDD", 500000, "Effective C++", "Scott Meyers"}};

    create_file(filename, elements);
    std::cout << "Initial file contents:\n";
    print_file(filename);

    // Видалення першого елемента із заданим об’ємом
    int volume_to_delete = 700;
    delete_by_volume(filename, volume_to_delete);
    std::cout << "\nFile contents after deletion:\n";
    print_file(filename);

    // Додавання елемента перед елементом із заданим номером
    Information new_element = {"DVD", 4700, "The C++ Standard Library", "Nicolai Josuttis"};
    int position = 2;
    insert_before_position(filename, new_element, position);
    std::cout << "\nFile contents after insertion:\n";
    print_file(filename);

    return 0;
}
