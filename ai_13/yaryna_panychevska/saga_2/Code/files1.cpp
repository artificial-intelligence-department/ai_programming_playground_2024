#include <iostream>
#include <fstream>
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

    //Рекурсивний обхід списку
    void printList(Person* head) {

        if (head == NULL) {
            return;
        }
        else {
            cout << "Name: " << head->name
                << ", Age: " << head->age
                << ", City: " << head->city << endl;
        }
        printList((head->next));
    }

    //Ітеративний обхід списку
    void printList(Person* head, bool n) {
        while (head != NULL) {
            cout << "Name: " << head->name
                << ", Age: " << head->age
                << ", City: " << head->city << endl;
            head = head->next;
        }
    }

    //Рекурсивний запис у файл
    void writeIntoFile(Person* head, ofstream& file) {
        if (head == NULL) {
            return;
        }
        else {
            file << "Name,Age,City\n";//Заголовок
            file << head->name << ","
                << head->age << ","
                << head->city << endl;
            writeIntoFile((head->next), file);
        }

    }
    
    //Ітеративний запис у файл
    void writeIntoFile2(Person* head, ofstream& file) {

        file << "Name,Age,City\n";//Заголовок

        while (head != NULL) {
            file << head->name << ","
                << head->age << ","
                << head->city << endl;
            head = head->next;
        }

    }
};

    int main() {

        LinkedList resident;
        resident.AddToList("John Doe", 30, "New York");
        resident.AddToList("Jane Smith", 25, "Los Angeles");
        resident.AddToList("Alice Brown", 35, "Chicago");

        cout << "Printing list of residents recursively:\n";
        resident.printList(resident.head);

        cout << "\nPrinting list of residents iteratively:\n";
        resident.printList(resident.head, true);


        cout << "\nWriting data into file recursively:\n";

        ofstream file("file1.csv");
        if (file.is_open()) {

            resident.writeIntoFile(resident.head, file);
            file.close();
            cout << "Data was successfully written into file!" << endl;
        }
        else {
            cerr << "Error: Unable to write data into file." << endl;
        }


        cout << "\nWriting data into file iteratively:\n";

        ofstream file1("file2.csv");
        if (file1.is_open()) {

            resident.writeIntoFile2(resident.head, file1);
            file1.close();
            cout << "Data was ssuccessfully written into file!" << endl;
        }
        else {
            cerr << "Error: Unable to write data into file." << endl;
        }

        return 0;
    }