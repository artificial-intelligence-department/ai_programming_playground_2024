#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList 
{
private:
    struct Node 
    {
        T value;
        Node* next;
        Node* prev;
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() { clear(); }

    void insert(int index, int n, T* values) 
    {
        if (index < 0 || index > size) return;

        Node* current = head;
        Node* prevNode = nullptr;

        for (int i = 0; i < index; i++) 
        {
            prevNode = current;
            current = current->next;
        }

        for (int i = 0; i < n; i++) 
        {
            Node* newNode = new Node(values[i]);

            if (!head) 
            {
                head = tail = newNode;
            } 
            else if (!prevNode) 
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } 
            else 
            {
                newNode->next = current;
                newNode->prev = prevNode;
                if (prevNode) prevNode->next = newNode;
                if (current) current->prev = newNode;
            }

            prevNode = newNode;
            if (!current) tail = newNode;
        }

        size += n;
    }

    void erase(int index, int n) 
    {
        if (index < 0 || index >= size || n <= 0) return;

        Node* current = head;

        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        for (int i = 0; i < n && current; i++) 
        {
            Node* toDelete = current;
            if (toDelete->prev) toDelete->prev->next = toDelete->next;
            if (toDelete->next) toDelete->next->prev = toDelete->prev;

            if (toDelete == head) head = toDelete->next;
            if (toDelete == tail) tail = toDelete->prev;

            current = current->next;
            delete toDelete;
            size--;
        }
    }

    int getSize() const 
    {
        return size;
    }

    T get(int index) const 
    {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");

        Node* current = head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        return current->value;
    }
    
    void set(int index, T value) 
    {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");

        Node* current = head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        current->value = value;
    }

    void print() const 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void clear() 
    {
        Node* current = head;
        while (current) 
        {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }

        head = tail = nullptr;
        size = 0;
    }
    
    friend ostream& operator<<(ostream& os, const DoublyLinkedList<T>& list) 
    {
        Node* current = list.head;
        while (current) 
        {
            os << current->value << " ";
            current = current->next;
        }
        return os;
    }
};

int main() 
{
    DoublyLinkedList<int> list;
    int Q;
    cin >> Q;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") 
        {
            int index, n;
            cin >> index >> n;

            int* values = new int[n];
            for (int i = 0; i < n; i++) 
            {
                cin >> values[i];
            }

            list.insert(index, n, values);
            delete[] values;
        } 
        else if (command == "erase") 
        {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } 
        else if (command == "size") 
        {
            cout << list.getSize() << "\n";
        } 
        else if (command == "get") 
        {
            int index;
            cin >> index;
            try 
            {
                cout << list.get(index) << "\n";
            } 
            catch (const out_of_range& e) 
            {
                cout << "Error: " << e.what() << "\n";
            }
        } 
        else if (command == "set") 
        {
            int index, value;
            cin >> index >> value;
            try 
            {
                list.set(index, value);
            } catch (const out_of_range& e) 
            {
                cout << "Error: " << e.what() << "\n";
            }
        } 
        else if (command == "print") 
        {
            cout << list << "\n";
        }
    }

    return 0;
}
