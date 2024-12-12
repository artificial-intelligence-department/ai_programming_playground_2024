#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
    string city;

    Person* next;
    Person* prev;

    Person(string Name, int Age, string City)
    {
        name = Name;
        age = Age;
        city = City;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList
{
    Person* head;
    Person* tail;
    LinkedList() : head(NULL), tail(NULL) {}

    void AddToList(string Name, int Age, string City) {
        Person* newPerson = new Person(Name, Age, City);

        if (head == NULL) {
            head = newPerson;
            tail = newPerson;
            return;
        }
        else {
            tail->next = newPerson;
            newPerson->prev = tail;
            tail = newPerson;
        }
    }
    
    void printList(Person* head) {
        while (head != NULL) {
            cout << "Name: " << head->name
                << ", Age: " << head->age
                << ", City: " << head->city << endl;
            head = head->next;
        }
    }
};

int main() {

    LinkedList resident;
    resident.AddToList("John Doe", 30, "New York");
    resident.AddToList("Jane Smith", 25, "Los Angeles");
    resident.AddToList("Alice Brown", 35, "Chicago");

    cout << "Residents:\n";
    resident.printList(resident.head);

    ofstream file;
    file.open("resident.csv");

    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }

    Person* current = resident.head;
    file << "Name,Age,City\n";//Заголовок

    while (current != NULL) {
        file << current->name << ","
            << current->age << ","
            << current->city << endl;
        current = current->next;
    }

    file.close();

    if (file.bad()) {
        cout << "Error: Unable to write data into file." << endl;
        return 1;
    }
    else {
        cout << "Data was successfully writen into file." << endl;
    }

    return 0;
}