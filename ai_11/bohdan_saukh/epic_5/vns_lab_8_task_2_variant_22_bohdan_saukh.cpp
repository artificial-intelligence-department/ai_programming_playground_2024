#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

struct Owner{
    char second_name[50];
    char name[50];
    char fathers_name[50];
    char car_number[50];
    char tech_passport[50];
    char dai[50];
};

void create_binary_file(const char* filename, const vector<Owner>& owners){
    ofstream file(filename, ios::binary);
    for (const auto& owner : owners) {
        file.write(reinterpret_cast<const char*>(&owner), sizeof(Owner));
    }
    file.close();
}

void print_binary_file(const char* filename){
    ifstream file(filename, ios::binary);
    Owner owner;
    while (file.read(reinterpret_cast<char*>(&owner), sizeof(Owner))){
        cout << owner.second_name << " " << owner.name << " " << owner.fathers_name << endl;
        cout << owner.car_number << ", " << owner.tech_passport << ", " << owner.dai << endl << endl;
    }
    file.close();
}

void delete_by_car_number(const char* filename, const char* car_number){
    ifstream file(filename, ios::binary);
    vector<Owner> owners;
    Owner owner;

    while (file.read(reinterpret_cast<char*>(&owner), sizeof(Owner))){
        if (strcmp(owner.car_number, car_number) != 0) {
            owners.push_back(owner);
        }
    }
    file.close();

    ofstream outfile(filename, ios::binary | ios::trunc);
    for (const auto& o : owners){
        outfile.write(reinterpret_cast<const char*>(&o), sizeof(Owner));
    }
    outfile.close();
}

void add_before_second_name(const char* filename, const char* target_second_name, const vector<Owner>& new_owners){
    ifstream file(filename, ios::binary);
    vector<Owner> owners;
    Owner owner;

    while (file.read(reinterpret_cast<char*>(&owner), sizeof(Owner))){
        if (strcmp(owner.second_name, target_second_name) == 0){
            owners.insert(owners.end(), new_owners.begin(), new_owners.end());
        }
        owners.push_back(owner);
    }
    file.close();

    ofstream outfile(filename, ios::binary | ios::trunc);
    for (const auto& o : owners){
        outfile.write(reinterpret_cast<const char*>(&o), sizeof(Owner));
    }
    outfile.close();
}

int main() {
    const char* filename = "owners.dat";

    vector<Owner> owners = {
        {"Smith", "John", "James", "AA1234BB", "TP001", "New York"},
        {"Johnson", "Michael", "Edward", "BB5678CC", "TP002", "Los Angeles"},
        {"Brown", "Christopher", "Daniel", "CC9012DD", "TP003", "Chicago"}
    };

    create_binary_file(filename, owners);
    cout << "Вміст файлу після створення:" << endl;
    print_binary_file(filename);

    delete_by_car_number(filename, "BB5678CC");
    cout << "Вміст файлу після видалення елемента:" << endl;
    print_binary_file(filename);

    vector<Owner> new_owners = {
        {"Taylor", "David", "Alexander", "DD3456EE", "TP004", "Houston"},
        {"Wilson", "James", "Robert", "EE7890FF", "TP005", "Phoenix"}
    };
    add_before_second_name(filename, "Brown", new_owners);
    cout << "Вміст файлу після додавання елементів:" << endl;
    print_binary_file(filename);

    return 0;
}
