#include <iostream>

class LinkedList
{
private:
    struct Node 
    {
        int data;
        Node* next;

        Node(): data(0), next(nullptr) {}
        Node(int val, Node* node = nullptr) : data(val), next(node) {}
    };
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void PushBack(int data);
    void ShowList();
    void ReverseList();
    bool CompareTwoLists(LinkedList& list2);
    void AddElementsOfTwoLists(LinkedList& list2);
};

LinkedList::LinkedList(): head(nullptr), size(0) {}
LinkedList::~LinkedList()
{
    while(head != nullptr)
    {
        Node* current = head;
        head = head->next;
        delete current;
    }
}
void LinkedList::ShowList()
{
    Node* current = head;
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void LinkedList::PushBack(int data)
{
    Node* newNode = new Node(data);
    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != nullptr)
        current = current->next;
    current->next = newNode;

    size++;
}
void LinkedList::ReverseList()
{
    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode;

    while(current != nullptr)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    head = previous;
}
bool LinkedList::CompareTwoLists(LinkedList& list2)
{
    Node* current1 = head;
    Node* current2 = list2.head;

    while(current1 != nullptr && current2 != nullptr)
    {
        if(current1->data > current2->data)
            return 0;
        if(current2->data > current1->data)
            return 0;
        current1 = current1->next;
        current2 = current2->next;
    }
    if((!current1) && (!current2))
        return 1;
    else
        return 0;
}
void LinkedList::AddElementsOfTwoLists(LinkedList& list2)
{
    this->ReverseList();
    list2.ReverseList();
    Node* current1 = head;
    Node* current2 = list2.head;
    long sum = 0;
    int r = 0;

    LinkedList res;
    while (current1 != nullptr || current2 != nullptr || r != 0)
    {
        sum = r;
        if(current1 != nullptr)
        {
            sum += current1->data;
            current1 = current1->next;
        } 
        if(current2 != nullptr)
        {
            sum += current2->data;
            current2 = current2->next;
        } 
        res.PushBack(sum % 10);
        r = sum / 10;    
    }
    res.ReverseList();
    res.ShowList();
    this->ReverseList();
    list2.ReverseList();
}
int main()
{
    LinkedList list1;
    list1.PushBack(8);
    list1.PushBack(9);
    list1.PushBack(7);
    list1.PushBack(1);

    std::cout << "A list before rersing: "; list1.ShowList();
    list1.ReverseList();
    std::cout << "A list after rersing: "; list1.ShowList(); std::cout << std::endl;
    list1.ReverseList();

    LinkedList list2;
    list2.PushBack(8);
    list2.PushBack(9);
    list2.PushBack(7);

    std::cout << "Two lists to compare and add: " << std::endl;
    list1.ShowList(); list2.ShowList();
    std::cout << "Are these lists equal: ";
    std::cout << (list1.CompareTwoLists(list2)? "Yes" : "No") << std::endl << std::endl;
    std::cout << "Sum of two lists: ";
    list1.AddElementsOfTwoLists(list2);

    return 0;
}
