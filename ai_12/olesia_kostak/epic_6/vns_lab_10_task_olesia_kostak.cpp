#include <iostream>
#include <fstream>

struct Node
{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr) {}
};

void Show(Node* head);
void AddElement(Node*& head, int value, int pos);
void DeleteElement(Node*& head, int pos);
void SaveToFile(Node*& head, const char* filename);
void DeleteList(Node*& head);
void RestoreList(Node*& head, const char* filename);


int main()
{
    Node* head = nullptr;
    const char* filename = "linkedList.txt";

    int userOption;
    do
    {
        std::cout << "Chose an option:" << std::endl <<
        "1. Add elements" << std::endl <<
        "2. Delete elements" << std::endl <<
        "3. Show elements" << std::endl <<
        "4. Write to file" << std::endl <<
        "5. Delete list" << std::endl <<
        "6. Restor list" << std::endl <<
        "7. Exit" << std::endl;
        std::cin >> userOption;
        
        switch (userOption)
        {
            case 1:
            {
                std::cout << "Enter the position where you want to add elements. " <<
                "Enter how many elements you want to add: " << std::endl;
                int pos, amount, value;
                std::cin >> pos >> amount;
                for(int i = 0; i != amount; i++)
                {
                    std::cout << "Enter the value of " << i + 1 << " element" << std::endl;
                    std::cin >> value;
                    AddElement(head, value, pos++);
                }
            }   break;
            case 2:
            {
                std::cout << "Enter the position where you want to delete elements. " <<
                "Enter how many elements you want to delete: " << std::endl;
                int pos, amount;
                std::cin >> pos >> amount;
                for(int i = 0; i != amount; i++)
                    DeleteElement(head, pos);
            }   break;
            case 3:
                Show(head);
                break;
            case 4:
                SaveToFile(head, filename);
                break;
            case 5:
                DeleteList(head);
                break;
            case 6:
                RestoreList(head, filename);
                break;                           
            default:
                break;
        }
    } 
    while (userOption != 7);
    
    return 0;
}

void Show(Node* head)
{
    if (head == nullptr)
        std::cout << "List is empty";
    else
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data  << " ";
            current = current->next;
        } 
    }
    std::cout << std::endl;
}

void AddElement(Node*& head, int value, int pos)
{
    if (pos < 0)
    {
        std::cout << "Position is not correct" << std::endl;
        return;
    }

    Node* newNode = new Node(value);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;   
        return;
    }

    Node* current = head;
    for(int i = 0; i < pos - 1 && current != nullptr; i++) 
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

void DeleteElement(Node*& head, int pos)
{
    if (pos < 0)
    {
        std::cout << "Position is not correct" << std::endl;
        return;
    }
    if (head == nullptr)
        return;
    if (pos == 0)
    {
        Node* temp = head;
        head = temp->next;
        delete temp;
        return;
    }
    Node* previous = head;
    Node* temp = head;
    for(int j = 0; j < pos; j++)
    {
        previous = temp;
        temp = temp->next;
        if (temp == nullptr)
        {
            std::cout << "Position out of range" << std::endl;
            return;
        }
    }
    previous->next = temp->next;
    delete temp;
}

void SaveToFile(Node*& head, const char* filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        perror("Error opening file");
        exit(1);
    }

    Node* current = head;
    while(current != nullptr)
    {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
}

void DeleteList(Node*& head)
{
    while (head != nullptr)
    {
        Node* current = head;
        head = head->next;
        delete current;
    }
}

void RestoreList(Node*& head, const char* filename)
{
    std::ifstream file(filename);
    if(!filename)
    {
        perror("Error opening file");
        exit(1);
    }
    int data;
    int pos = 0;
    while(file >> data)
    {
        AddElement(head, data, pos);
        pos++;
    }
    file.close();
}