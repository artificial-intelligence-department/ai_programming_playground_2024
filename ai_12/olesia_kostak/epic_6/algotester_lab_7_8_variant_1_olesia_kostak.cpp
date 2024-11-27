#include <iostream>
#include <vector>

template <typename T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
        Node(T value, Node* prev = nullptr, Node* nxt = nullptr): data(value), previous(prev), next(nxt) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void Insert(int index, const std::vector<T>& lst);
    void Erase(int index, int amount);
    int Size();
    T Get(int index);
    void Set(int index, T value);
    void Print();  
    
    friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list)
        {
            Node* current = list.head;
            while (current != nullptr)
            {
                os << current->data << " ";
                current = current->next;
            }
            return os;
        }  
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while(head != nullptr)
    {
        Node* current = head;
        head = head->next;
        delete current;
    }
    tail = nullptr;
    size = 0;
}

template <typename T>
void DoubleLinkedList<T>::Insert(int index, const std::vector<T>& lst)
{
    if (index < 0 || index > size)
        return;
    
    for(int i = 0; i < lst.size(); i++)
    {
        Node* newNode = new Node(lst[i]);

        if (index == 0)
        {
            newNode->next = head;
            if(head != nullptr)
                head->previous = newNode;
            head = newNode;
            if (tail == nullptr)
                tail = newNode;
        }
        else if (index == size)
        {
            newNode->previous = tail;
            if (tail != nullptr)
                tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node* current = head;
            for(int i = 0; i < index - 1; i++)
                current = current->next;
            newNode->next = current->next;
            newNode->previous = current;
            if (current->next != nullptr)
                current->next->previous = newNode;            
            current->next = newNode;
        }
        index++;
        size++;
    }
    
}

template <typename T>
void DoubleLinkedList<T>::Print()
{
    std::cout << *this << std::endl;
}

template <typename T> 
void DoubleLinkedList<T>::Erase(int index, int amount)
{
    if (index < 0 || index > size || amount <= 0 || index + amount > size)
        return;

    Node* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;

    for(int i = 0; i < amount; i++)
    {
        Node* nodeToDelete = current;
        current = current->next;

        if (nodeToDelete->previous != nullptr)
            nodeToDelete->previous->next = nodeToDelete->next;
        else
            head = nodeToDelete->next;
        if (nodeToDelete->next != nullptr)
            nodeToDelete->next->previous = nodeToDelete->previous;
        else
            tail = nodeToDelete->previous;

        delete nodeToDelete;
        size--;        
    }
}

template <typename T>
int DoubleLinkedList<T>::Size()
{
    return size;
}

template <typename T>
T DoubleLinkedList<T>::Get(int index)
{
    Node* current = head;
    for(int i = 0; i < index; i++)
        current = current->next;
    
    return current->data;
}

template <typename T>
void DoubleLinkedList<T>::Set(int index, T value)
{
    if (index < 0 || index > size)
        return;

    Node* current = head;
    for(int i = 0; i < index; i++)
        current = current->next;
    current->data = value;
}

int main()
{
    DoubleLinkedList<int> myList;
    int Q;
    std::cin >> Q;
    std::string question;

    for(int i = 0; i < Q; i++)
    {
        std::cin >> question;

        if(question == "insert")
        {
            int index, N;
            std::cin >> index >> N;
            std::vector<int> lst(N);
            for(int i = 0; i < N; i++)
                std::cin >> lst[i];
            myList.Insert(index, lst);
        }
        if(question == "erase")
        {
            int index, N;
            std::cin >> index >> N;
            myList.Erase(index, N);

        }
        if(question == "size")
        {
            std::cout << myList.Size() << std::endl;
        }
        if(question == "get")
        {
            int index;
            std::cin >> index;
            std::cout << myList.Get(index) << std::endl; 
        }
        if(question == "set")
        {
            int index, value;
            std::cin >> index >> value;
            myList.Set(index, value);
        }
        if(question == "print")
        {
            myList.Print();
        }
        
    }
    return 0;
}