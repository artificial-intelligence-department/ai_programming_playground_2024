#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

struct Node
{
    char* data;
    Node* prev;
    Node* next;
};

class double_linked_list
{
private:

    Node* head;
    Node* tail;

public:
    double_linked_list ()
    {
       head = nullptr;
       tail = nullptr;
    }

    ~double_linked_list()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
    }

    //Додавання нового елемента в кінець
    void push_back (const char* element)
    {
        Node* new_node = new Node();
        new_node->data = new char [strlen(element) + 1];
        strcpy(new_node->data, element);

        new_node->prev = tail;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    //Виведення списку
    void print_list()
    {
        if (head == nullptr) cout<<"List is epty";
        else
        {
            Node* current = head;
            while (current != nullptr)
            {
               cout<<current->data<<" ";
               current = current->next; 
            }
        }

        cout<<endl;
    }

    //Видалення однакових елементів
    void delete_identical_elements()
    {
        Node* i = head;

        while (i != nullptr)
        {
            Node* current = i->next;
            while (current != nullptr)
            {
                if (!strcmp(i->data, current->data))
                {
                    if (current == tail)
                    {
                        Node* temp = current;
                        tail = tail->prev;
                        tail->next = nullptr;
                        current = current->next;
                        delete temp;
                    }
                    else
                    {
                        Node* temp = current;

                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                        current = current->next;
                        delete temp;
                    }
                }
                else current = current->next;
            }
            i = i->next;
        }
    }

    //Додавання елемента після заданого
    void add_element (const char* index_element, const char* add_element)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (!strcmp(current->data, index_element))
            {
                Node* new_node = new Node();
                new_node->data = new char [strlen(add_element) + 1];
                strcpy(new_node->data, add_element);

                if (current == tail)
                {
                    new_node->prev = current;
                    new_node->next = nullptr;

                    current->next = new_node;
                    tail = new_node;

                    return;
                }
                else
                {
                    new_node->prev = current;
                    new_node->next = current->next;

                    current->next = new_node;
                    new_node->next->prev = new_node;

                    return;
                }
            }

            current = current->next;
        }  
    }

    //Копіювання списку в файл
    void add_list_to_file(const char* file_name)
    {
       ofstream fout;
       fout.open(file_name);

       Node* current = head;

       while (current != nullptr)
       {
            fout<<current->data<<endl;
            current = current->next;
       } 

       fout.close(); 
    }

    //Знищення списку
    void delete_list()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }

    //Копіювання списку з файлу
    void copy_list_from_file(const char* file_name)
    {
        ifstream fin;
        fin.open(file_name);


        char new_element[256];
        while (fin>>new_element)
        {
            push_back(new_element);
        }
        
        fin.close();
    }
};




int main()
{
    const char file_name[] = "List.txt";
    double_linked_list list;
    list.print_list();

    list.push_back("Dima");//Додавання елемента в кінець
    list.push_back("Mark");
    list.push_back("Dima");
    list.push_back("Sonia");
    list.push_back("Sonia");

    cout<<"Initial list: ";
    list.print_list();

    list.delete_identical_elements();//Видалення однакових елементів
    cout<<"List after deleting: ";
    list.print_list();

    list.add_element("Mark", "Nazar");//додавання елемента після заданого
    list.add_element("Sonia", "Taras");//додавання елемента після заданого
    cout<<"List after adding: ";
    list.print_list();

    list.add_list_to_file(file_name);  //запис у файл

    list.delete_list();//Знищення списку

    list.print_list();

    list.copy_list_from_file(file_name);//Відновлення списку з файлу
    cout<<"Restored list: ";
    list.print_list();
    
    list.delete_list();//Знищення списку
    return 0;
}
