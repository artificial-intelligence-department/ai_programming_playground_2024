#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    int id;
    float grade;
};

void AddStudents(Student *&st, int &size);
void ShowStudents(Student *st, int size);
float ShowAverageGrade(Student *st, int size);
int main()
{
    int size = 0;
    Student *students = nullptr;

    int ch;
    while (true)
    {
        cout << "1 - Add a new student\n2 - Display the list of students\n3 - Show the average grade of all students\n4 - Exit the program.";
        cin >> ch;
        if (ch == 1)
        {
            AddStudents(students, size);
        }
        else if (ch == 2)
        {
            ShowStudents(students, size);
        }
        else if (ch == 3)
        {
            cout << "Average grade of all students: " << ShowAverageGrade(students, size) << endl;
        }
        else if (ch == 4)
        {
            break;
        }
    }
    delete[] students;
}

void AddStudents(Student *&st, int &size)
{
    size += 1;
    Student *arr = new Student[size];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = st[i];
    }
    cout << "Enter student's name: ";
    cin >> arr[size - 1].name;
    cout << "Enter student's age: ";
    cin >> arr[size - 1].age;
    cout << "Enter student's grade: ";
    cin >> arr[size - 1].grade;
    cout << "Enter student's id: ";
    cin >> arr[size - 1].id;
    delete[] st;
    st = arr;
}

void ShowStudents(Student *st, int size)
{
    if (size == 0)
    {
        cout << "We don't have any student!" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << st[i].name << endl;
        cout << "Age: " << st[i].age << endl;
        cout << "Grade: " << st[i].grade << endl;
        cout << "ID: " << st[i].id << endl;
    }
}

float ShowAverageGrade(Student *st, int size)
{
    float sum = 0;
    if (size == 0)
    {
        return 0.0;
    }
    for (int i = 0; i < size; i++)
    {
        sum += st[i].grade;
    }

    return sum / size;
}