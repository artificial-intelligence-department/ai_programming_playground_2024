#include <iostream>
using namespace std;

template <typename T>
struct Node 
{
    T value;
    Node* next;
    Node* prev;

    Node(T val) : value(val), next(nullptr), prev(nullptr) 
    {
    }
};

template <typename T>
class DoublyLinkedList 
{
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) 
    {
    }

    ~DoublyLinkedList() 
    {
        Node<T>* current_node = head;
        while (current_node) {
            Node<T>* next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }
    }

    void insert(int index, const T arr[], int N) 
    {
        Node<T>* new_nodes_start = nullptr;
        Node<T>* new_nodes_end = nullptr;

        for (int i = 0; i < N; ++i) {
            Node<T>* new_node = new Node<T>(arr[i]);
            if (!new_nodes_start) new_nodes_start = new_node;
            else {
                new_nodes_end->next = new_node;
                new_node->prev = new_nodes_end;
            }
            new_nodes_end = new_node;
        }

        if (index == 0)
        {
            new_nodes_end->next = head;
            if (head) head->prev = new_nodes_end;
            head = new_nodes_start;
            if (!tail) tail = new_nodes_end;
        }
        else {
            Node<T>* current_node = head;
            int curr_index = 0;

            while (current_node && curr_index < index) {
                current_node = current_node->next;
                curr_index++;
            }

            if (current_node) {
                new_nodes_end->next = current_node;
                if (current_node->prev) current_node->prev->next = new_nodes_start;
                new_nodes_start->prev = current_node->prev;
                current_node->prev = new_nodes_end;
            }
        }
        count += N;
    }

    void erase(int index, int n) 
    {
        Node<T>* current_node = head;
        int curr_index = 0;

        while (current_node && curr_index < index) {
            current_node = current_node->next;
            curr_index++;
        }

        if (!current_node) return;

        for (int i = 0; i < n && current_node; ++i) 
        {
            Node<T>* next_node = current_node->next;

            if (current_node == head) head = next_node;
            if (current_node == tail) tail = current_node->prev;

            if (next_node) next_node->prev = current_node->prev;
            if (current_node->prev) current_node->prev->next = next_node;

            delete current_node;
            current_node = next_node;
            count--;
        }
    }

    int size() const { return count; }

    void get(int index) const {
        Node<T>* current_node = head;
        int curr_index = 0;

        while (current_node && curr_index < index) {
            current_node = current_node->next;
            curr_index++;
        }

        if (current_node) cout << current_node->value << endl;
        else cout << "Invalid index" << endl;
    }

    void set(int index, T value) 
    {
        Node<T>* current_node = head;
        int curr_index = 0;

        while (current_node && curr_index < index) {
            current_node = current_node->next;
            curr_index++;
        }

        if (current_node) current_node->value = value;
    }

    void print() const 
    {
        Node<T>* current_node = head;
        while (current_node) {
            cout << current_node->value << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};

int main() 
{
    int Q;
    cin >> Q;

    DoublyLinkedList<int> list;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index;
            cin >> index;
            int N;
            cin >> N;

            int arr[N];
            for (int j = 0; j < N; ++j) {
                cin >> arr[j];
            }
            list.insert(index, arr, N);
        }
        else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        }
        else if (command == "size") {
            cout << list.size() << endl;
        }
        else if (command == "get") {
            int index;
            cin >> index;
            list.get(index);
        }
        else if (command == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        }
        else if (command == "print") {
            list.print();
        }
    }




    return 0;
}







