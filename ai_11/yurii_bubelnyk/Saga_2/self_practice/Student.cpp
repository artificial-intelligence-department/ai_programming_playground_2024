#include <iostream>
#include <string>

using namespace std;
const int COUNT = 2;
struct Student
{
    string name;
    string surname;
    int studentID;
    double average;

    Student(string name = "", string surname = "", int studentID = 1, double average = 0) 
        : name(name), surname(surname), studentID(studentID), average(average)
    {
    } 
};

void show(const Student student[], int count);

int main()
{
    Student student[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        cout << "Enter student name:\t" << endl;
        getline(cin, student[i].name);
        cout << "Enter student surname:\t" << endl;
        getline(cin, student[i].surname);
        cout << "Enter student ID:\t" << endl;
        cin >> student[i].studentID;
        cout << "Enter student average:\t" << endl; 
        cin >> student[i].average;
        cin.ignore(100, '\n');
    }

    show(student, COUNT);
    
    return 0;
}

void show(const Student student[], int count)
{
    cout << "Students";
    for (int i = 0; i < count; i++)
    {
        cout << "\nStudent name:\t" << student[i].name;
        cout << "\nStudent surname:\t" << student[i].surname;
        cout << "\nStudent student ID:\t" << student[i].studentID;
        cout << "\nStudent average:\t" << student[i].average;
    }
    
}


