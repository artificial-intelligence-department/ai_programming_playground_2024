#include<iostream>
#include<string>
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
    Node* next;
};

class linked_list
{
private:
    Node* head;
    int size = 0;
public:
    linked_list(): head(nullptr){};

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

    //Додати елемент ззаду
    void push_back(string first_name, string last_name, int age)
    {
        size++;
        Node* new_node = new Node;
        new_node->data.first_name = first_name;
        new_node->data.last_name = last_name;
        new_node->data.age = age;
        new_node->next = nullptr;
        
        if (head == nullptr)
        {
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        
        current->next = new_node;
    }

    //Виведення списку
    void print_list()
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
            head->next = nullptr;
            return;
        }

        new_node->next = head;
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
                new_node->next = current->next;
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
};
int main()
{
    linked_list students;


    students.push_back("Dima", "Tymchuk", 18);
    students.push_back("Stepan", "Bandera", 34);
    students.push_back("Markiyan", "Makovich", 18);
    students.push_back("Dmytro", "Dontsov", 45);
    students.push_back("Ivan", "Franko", 23);
    
    students.print_list();

    students.sort_list();
    cout<<"\nSorted list: \n"<<endl;
    students.print_list();

    

    return 0;
}