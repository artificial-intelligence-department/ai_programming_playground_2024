#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Student
{
    string first_name;
    string last_name;
    int age;

    Student(): first_name(" "), last_name(" "), age (0) {};
};

struct Node
{
    Student data;
    Node* prev;
    Node* next;

    Node(): prev(nullptr), next(nullptr){};
};

class linked_list
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    linked_list(): head(nullptr), tail(nullptr), size(0){};

    ~linked_list()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    //Виведення списку з початку
    void print_list_from_head()
    {
        if (head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            cout<<"Student #"<<i<<endl;
            cout<<"First name: "<<current->data.first_name<<endl;
            cout<<"Last name: "<<current->data.last_name<<endl;
            cout<<"Age: "<<current->data.age<<endl;

            current = current->next;
            i++;
            cout<<endl;
        }
    }

    //Виведення списку з кінця
    void print_list_from_tail()
    {
        if (head == nullptr)
        {
            cout<<"List is empty"<<endl;
        }

        Node* current = tail;
        int i = 1;
        while (current != nullptr)
        {
            cout<<"Student #"<<i<<endl;
            cout<<"First name: "<<current->data.first_name<<endl;
            cout<<"Last name: "<<current->data.last_name<<endl;
            cout<<"Age: "<<current->data.age<<endl;

            i++;
            current = current->prev;
            cout<<endl;
        }
    }

    //Додати елемент ззаду
    void push_back(string first_name, string last_name, int age)
    {
        size++;
        Node* new_node = new Node;
        new_node->data.first_name = first_name;
        new_node->data.last_name = last_name;
        new_node->data.age = age;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    //Додати елемент спереду
    void push_front(string first_name, string last_name, int age)
    {
        size++;
        Node* new_node = new Node;
        new_node->data.first_name = first_name;
        new_node->data.last_name = last_name;
        new_node->data.age = age;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    //Додавання елемента в середину списку
    void push_element(string first_name, string last_name, int age, int index)
    {
        Node* new_node = new Node;
        new_node->data.first_name = first_name;
        new_node->data.last_name = last_name;
        new_node->data.age = age;

        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (i == index) 
            {
                new_node->prev = current;
                new_node->next = current->next;

                if (current->next != nullptr) current->next->prev = new_node;
                else tail = new_node;

                current->next = new_node;


                size++;
                return;
            }

            current = current->next;
            i++;
        }

        cout<<"You entered wrong index"<<endl;
    }

    //сортування списку за віком студентів
    void sort_list()
    {
        Node* current_i = head;
        while (current_i->next != nullptr)
        {
            Node* current_j = head;
            while (current_j->next != nullptr)
            {
                if (current_j->data.age > current_j->next->data.age)
                {
                    string name; int age;

                    //міняємо місцями імена
                    name = current_j->data.first_name;
                    current_j->data.first_name = current_j->next->data.first_name;
                    current_j->next->data.first_name = name;

                    //міняємо місцями прізвища
                    name = current_j->data.last_name;
                    current_j->data.last_name = current_j->next->data.last_name;
                    current_j->next->data.last_name = name;

                    //міняємо місцями вік
                    age = current_j->data.age;
                    current_j->data.age = current_j->next->data.age;
                    current_j->next->data.age = age;
                }

                current_j = current_j->next;
            }

            current_i = current_i->next;
        }
    }

    //Запис даних у файл
    void write_list_in_file(string filename)
    {
        ofstream out(filename);

        if (!out.is_open())
        {
            cout<<"File isn`t opened"<<endl;
            return;
        }

        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            out<<"Student #"<<i<<endl;
            out<<"First name: "<<current->data.first_name<<endl;
            out<<"Last name: "<<current->data.last_name<<endl;
            out<<"Age: "<<current->data.age<<endl;

            current = current->next;
            i++;
            out<<endl;
        }

        out.close();
    }
};
int main()
{
    linked_list students;
    string filename = "Students.txt";

    students.push_back("Name 1", "LastName 1", 18);
    students.push_element("Name 2", "LastName 2", 34, 1);
    students.push_front("Name 3", "LastName 3", 18);
    students.push_back("Name 4", "LastName 4", 45);
    students.push_element("Name 5", "LastName 5", 23, 3);

    students.print_list_from_head();

    students.sort_list();

    students.write_list_in_file(filename);





    return 0;
}