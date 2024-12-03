#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person
{
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char address[100];
    int medicalRecord;
    int insuranceNumber;
};

void saveToFile(const string &fileName, const vector<Person> &people)
{
    ofstream file(fileName, ios::binary);

    if (!file)
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto &person : people)
    {
        file.write(reinterpret_cast<const char *>(&person), sizeof(Person));
    }
    file.close();
}

void displayFileContent(const string &fileName)
{
    ifstream file(fileName, ios::binary);
    if (!file)
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Person person;
    while (file.read(reinterpret_cast<char *>(&person), sizeof(Person)))
    {
        cout << "Name: " << person.lastName << " " << person.firstName << " " << person.middleName << ", ";
        cout << "Address: " << person.address << ", ";
        cout << "Medical Record: " << person.medicalRecord << ", ";
        cout << "Insurance Number: " << person.insuranceNumber << endl;
    }
    file.close();
}

void deletePatientByCardNumber(const string &fileName, int cardNumber)
{
    ifstream file(fileName, ios::binary);
    if (!file)
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    vector<Person> people;
    Person person;
    bool found = false;

    while (file.read(reinterpret_cast<char *>(&person), sizeof(Person)))
    {
        if (person.medicalRecord != cardNumber)
        {
            people.push_back(person);
        }
        else
        {
            found = true;
        }
    }
    file.close();

    if (!found)
    {
        cerr << "Patient with medical record number " << cardNumber << " not found!" << endl;
        return;
    }

    ofstream outFile(fileName, ios::binary | ios::trunc);
    if (!outFile)
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto &p : people)
    {
        outFile.write(reinterpret_cast<const char *>(&p), sizeof(Person));
    }
    outFile.close();
}

void prependPeopleToFile(const string &fileName, const vector<Person> &newPeople)
{
    ifstream file(fileName, ios::binary);
    if (!file)
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    vector<Person> allPeople(newPeople);
    Person person;
    while (file.read(reinterpret_cast<char *>(&person), sizeof(Person)))
    {
        allPeople.push_back(person);
    }
    file.close();

    ofstream outFile(fileName, ios::binary | ios::trunc);
    if (!outFile)
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto &p : allPeople)
    {
        outFile.write(reinterpret_cast<const char *>(&p), sizeof(Person));
    }
    outFile.close();
}

int main()
{
    string fileName = "people.bin";

    vector<Person> initialPeople = {
        {"Shevchenko", "Taras", "Hryhorovych", "Kyiv, Shevchenka 10", 12345, 67890},
        {"Ivanov", "Petro", "Ivanovych", "Kharkiv, Pushkina 12", 12346, 67891}};

    saveToFile(fileName, initialPeople);
    cout << "Initial content of the file:" << endl;
    displayFileContent(fileName);

    int cardNumberToDelete = 12345;
    deletePatientByCardNumber(fileName, cardNumberToDelete);
    cout << "File content after deleting a patient with a medical record number " << cardNumberToDelete << ":" << endl;
    displayFileContent(fileName);

    vector<Person> newPerson = {
        {"Kovalenko", "Maria", "Ivanivna", "Odessa, Derybasivska 7", 12347, 67892}};
    
    prependPeopleToFile(fileName, newPerson);
    cout << "File content after adding a new person:" << endl;
    displayFileContent(fileName);

    return 0;
}
