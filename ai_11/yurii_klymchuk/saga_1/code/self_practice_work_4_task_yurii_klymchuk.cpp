#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//використав цілочисельну змінну, строку, ввід/вивід,
//switch case, цикл while, структуру, запис у файл,
//зчитування з файлу

struct Volunteer{
   string name;
   string surname;
   int age;
   string specification; 
};

void ListVolunteers(){
    string line;
    ifstream File("list_of_members.txt");
    while (getline (File, line)) {
        cout << line << endl;
    }
    File.close();
};
void NewMember(){
    Volunteer new_member;
    int type_of_work;

    cout << "Name: ";
    cin >> new_member.name;

    cout << "Surname: ";
    cin >> new_member.surname;

    cout << "Age :";
    cin >> new_member.age;

    cout << "Chose the field you would like to work in:\n1.Animal shelter\n" << 
    "2.Environmental protection\n" << 
    "3.Community service\n" << 
    "4.Hospitals\n";
    cin >> type_of_work;
    switch (type_of_work){
        case 1:
            new_member.specification = "Animal shelter";
            break;
        case 2:
            new_member.specification = "Environmental protection";
            break;
        case 3:
            new_member.specification = "Community service";
            break;
        case 4:
            new_member.specification = "Hospitals";
            break;
        default:
            cout << "Wrong option";
            return;
    };

    ofstream File("list_of_members.txt", ios::app);

    File << "Name: " << new_member.name;
    File << "\nSurname: " << new_member.surname;
    File << "\nAge: " << new_member.age;
    File << "\nSpecification: " << new_member.specification << endl;
    File << "----------------------------------------------\n";
    File.close();

    cout << "Thank you for joining us!";
}
int main () {
    int choice;
    cout << "Welcome to volunteer team.\n";
    cout << "How can i help you?\n";
    cout << "1.List all volunteers\n2.I want to take a part\n";
    cin >> choice;
    switch (choice) {
        case 1: 
            ListVolunteers();
            break;
        case 2:
            NewMember();
            break;
        default:
            cout << "Wrong option";
    }
    return 0;
}