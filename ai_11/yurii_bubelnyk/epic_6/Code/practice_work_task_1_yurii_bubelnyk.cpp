#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    void reverse_list();
    void printList();
    bool compare(List<T>& List1, List<T>& List2); 
    void add(List<T>& List1, List<T>& List2); 

private:
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }

    };
    int Size;
    Node* head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->pNext;
        delete temp;
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

template <typename T>
void List<T>::reverse_list()
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

template <typename T>
void List<T>::printList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

template <typename T>
bool List<T>::compare(List<T>& List1, List<T>& List2)
{
    Node* temp1 = List1.head;
    Node* temp2 = List2.head;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data != temp2->data)
        {
            return false;  
        }
        temp1 = temp1->pNext;
        temp2 = temp2->pNext;
    }
    return (temp1 == nullptr && temp2 == nullptr);
}

template <typename T>
void List<T>::add(List<T>& List1, List<T>& List2)
{
    // Reverse both lists before adding them to get the correct order for addition
    List1.reverse_list();
    List2.reverse_list();

    Node* temp1 = List1.head;
    Node* temp2 = List2.head;
    int carry = 0;
    List<T> result;

    while (temp1 != nullptr || temp2 != nullptr || carry != 0)
    {
        int sum = carry;

        if (temp1 != nullptr)
        {
            sum += temp1->data;
            temp1 = temp1->pNext;
        }

        if (temp2 != nullptr)
        {
            sum += temp2->data;
            temp2 = temp2->pNext;
        }

        carry = sum / 10;  // Calculate the carry for the next iteration
        result.push_back(sum % 10);  // Add the current digit (sum % 10) to the result list
    }

    // Reverse the result list to print it in the correct order (from most significant to least significant digit)
    result.reverse_list();

    cout << "Sum: ";
    result.printList();
}

int main()
{
    List<int> myList;
    myList.push_back(2);
    myList.push_back(7);
    myList.push_back(3);  
    myList.push_back(6);  

    List<int> myList2;
    myList2.push_back(4);
    myList2.push_back(5);
    myList2.push_back(3); 
    myList2.push_back(1);  

    cout << "List 1: ";
    myList.printList();

    cout << "List 2: ";
    myList2.printList();

    cout << "Original list: ";
    myList.printList();

    myList.reverse_list();
    cout << "Reversed list: ";
    myList.printList();

    if (myList.compare(myList, myList2))
    {
        cout << "The lists are equal." << endl;
    }
    else
    {
        cout << "The lists are not equal." << endl;
    }
    myList.printList();
    myList2.printList();
    myList.add(myList, myList2);  // Add two lists

    return 0;
}
