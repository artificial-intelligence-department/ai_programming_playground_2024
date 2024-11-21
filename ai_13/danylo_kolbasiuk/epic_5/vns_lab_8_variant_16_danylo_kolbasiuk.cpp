#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

struct Car_Owner
{
    char full_name[50];
    long long int car_num;
    long long int phone_num;
    long long int techpass_num;
};

void add_car_owner(const std::string &name)
{
    Car_Owner car_owner;
    std::cin.ignore();
    std::cout << "Enter the car owner's full name: ";
    std::cin.getline(car_owner.full_name, 50);
    std::cout << "Enter the car number: ";
    std::cin >> car_owner.car_num;
    std::cout << "Enter the phone number of the owner: ";
    std::cin >> car_owner.phone_num;
    std::cout << "Enter the tech passport number of the owner: ";
    std::cin >> car_owner.techpass_num;
    std::fstream file(name, std::ios::binary | std::ios::out | std::ios::app);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&car_owner), sizeof(Car_Owner));
        file.close();
        std::cout << "Car owner added successfully!\n";
    } else {
        std::cerr << "Error opening file for writing!\n";
    }
}

void print_file(const std::string &name)
{
    Car_Owner car_owner;
    std::ifstream file(name, std::ios::binary);
    if(file.is_open())
    {
        file.seekg(0, std::ios::beg);
        while (file.read(reinterpret_cast<char*>(&car_owner), sizeof(Car_Owner))) 
        {
            std::cout << "Full name: " << car_owner.full_name << "\nCar number: " << car_owner.car_num << "\nPhone Number: " << car_owner.phone_num << "\nTech passport number: " << car_owner.techpass_num << "\n\n";
        }
    }
    file.close();
}

void remove_element(const std::string &name, const int &element_car_num)
{
    std::ifstream file(name, std::ios::binary);
    if (!file) {
        std::cout << "Failed to open the file to read it." << std::endl;
        return;
    }
    Car_Owner car_owner;
    std::vector<Car_Owner> owners;
    while (file.read(reinterpret_cast<char*>(&car_owner), sizeof(Car_Owner))) {
        if (element_car_num != car_owner.car_num) {
            owners.push_back(car_owner);
        }
    }
    file.close();

    std::ofstream file2(name, std::ios::binary | std::ios::trunc);
    if (!file2) {
        std::cout << "Failed to open the file to write to it." << std::endl;
        return;
    }
    for (const auto &owner : owners) {
        file2.write(reinterpret_cast<const char*>(&owner), sizeof(Car_Owner));
    }
    file2.close();
}

void insert_before_surname(const std::string &name, const Car_Owner new_owner, const std::string &surname1)
{
    std::ifstream file(name, std::ios::binary);
    if (!file) {
        std::cout << "Failed to open the file for reading." << std::endl;
        return;
    }
    Car_Owner car_owner;
    std::vector<Car_Owner> owners;
    while (file.read(reinterpret_cast<char*>(&car_owner), sizeof(Car_Owner))) {
        owners.push_back(car_owner);
    }
    file.close();

    int position = 0;
    for (const auto &car_owner : owners) {
        std::string name, surname, middle_name;
        std::stringstream stream(car_owner.full_name);
        stream >> name >> surname >> middle_name;
        if (surname == surname1) {
            break;
        }
        position++;
    }

    if (position >= owners.size()) {
        std::cout << "Invalid position. Surname not found.\n";
        return;
    }

    owners.insert(owners.begin() + position, new_owner);

    std::ofstream file2(name, std::ios::binary | std::ios::trunc);
    if (!file2) {
        std::cout << "Failed to open the file for writing." << std::endl;
        return;
    }
    for (const auto &owner : owners) {
        file2.write(reinterpret_cast<const char*>(&owner), sizeof(Car_Owner));
    }
}

int main()
{
    std::string filename = "car_owners.bin";
    add_car_owner(filename);
    add_car_owner(filename);
    long long int delete_car_num = 3246124;
    remove_element(filename, delete_car_num);
    std::string surname = "Kolbasiuk";
    Car_Owner new_owner;
    strncpy(new_owner.full_name, "Aaaaa Bbbbbb Cccccc", sizeof(new_owner.full_name) - 1);
    new_owner.full_name[sizeof(new_owner.full_name) - 1] = '\0';
    new_owner.car_num=1341256;
    new_owner.phone_num=75523412;
    new_owner.techpass_num=245156;
    insert_before_surname(filename, new_owner, surname);
    print_file(filename);
    return 0;
}