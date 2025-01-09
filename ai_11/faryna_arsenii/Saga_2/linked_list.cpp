/*
- створення однонаправленого з списку структур
- додавання нового вузла списку в кінець списку
- додавання нового вузла списку на початок списку
- додавання нового вузла списку в середині списку
- виведення значень з структури у списку 
- сортування однонаправленого списку методом бульбашки
- подивитись як ще можна сортувати однонаправлений список
*/

#include <iostream>
#include <string>

using namespace std;

// Структура студент
struct Student
{
    string name;
    int age;
    double grade;

    Student* next;
};

// Функція для створення нового вузла
Student* createNode(const string& name, int age, double grade)
{

    Student* newNode = new Student;
    newNode->name = name;
    newNode->age = age;
    newNode->grade = grade;
    newNode->next = nullptr;

    return newNode;

}

// Функція для додавання в кінець списку
void addToTheEnd(Student*& head, const string& name, int age, double grade)
{

    Student* newNode = createNode(name, age, grade);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Student* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

// Функція для додавання на початок списку
void addToTheBegining(Student*& head, const string& name, int age, double grade)
{
    Student* newNode = createNode(name, age, grade);
    newNode->next = head; 
    head = newNode;

}

// Функція для сортування бульбашкою за оцінками 
void bubble_sort(Student*& head)
{

    if (!head)
    {
        return;
    }
    bool swapped;
    do 
    {
        swapped = false;
        Student* current = head;
        Student* prev = nullptr;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->grade > current->next->grade)
            {
                swapped = true;
                if (prev == nullptr)
                {
                    Student* temp = current->next;
                    current->next = temp->next;
                    temp->next = current;
                    head = temp;
                }
                else 
                {
                    Student* temp = current->next;
                    current->next = temp->next;
                    temp->next = current;
                    prev->next = temp;
                }
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);

}

// Сортування вставками і вставляння нового студента
void insertion_sort(Student*& head)
{
    if (!head || !head->next)
    {
        return;
    }

    Student* sorted = nullptr;
    Student* current = head;

    while (current != nullptr)
    {
        Student* next = current->next;

        // Вставка елемента в початок відсортованого списку
        if (sorted == nullptr || sorted->grade >= current->grade)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            // Знайти місце для вставки
            Student* temp = sorted;
            while (temp->next != nullptr && temp->next->grade < current->grade)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

// Фунцкія для друку списку
void print_list(Student* head)
{
    
    Student* temp = head;
    while (temp != nullptr)
    {
        cout << "Name: " << temp->name << " Age: " << temp->age << " Grade: " << temp->grade << endl;
        temp = temp->next;
    }

}

// Функція для звільнення пам'яті
void delete_list(Student*& head)
{
    Student* temp = head;
    while (temp != nullptr)
    {
        Student* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = nullptr;
    
}

int main()
{

    Student* head = nullptr;
    addToTheEnd(head, "Svyatoslav Syluk", 20, 85.5);
    addToTheEnd(head, "Iryna Balabanska", 17, 100);
    addToTheEnd(head, "Arsenii Faryna", 17, 99.5);

    cout << "Initial list: " << endl;
    print_list(head);

    addToTheBegining(head, "Sofia Masur", 17, 100);
    cout << "List after adding in the begining: " << endl;
    print_list(head);

    bubble_sort(head);
    cout << "\nList after bubble sort: " << endl;
    print_list(head);

    addToTheEnd(head, "Yakimets Iryna", 17, 80.0);
    insertion_sort(head);
    cout << "\nList after insertion sort: " << endl;
    print_list(head);

    delete_list(head);

    return 0;
}