#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* previous;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void empty_list() {
        head = tail = nullptr;
    }

    void print_list() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

   void delete_by_index(unsigned int index)
    {
        Node* current = head;
        while(current)
        {
            if(index-1 == 0)
            {
               Node* curr_next = current->next;
               current->next = curr_next->next;
               curr_next->next->previous = current;
               delete curr_next;     
            }
            index--;
            current = current->next;
        }
    }

    void add(const int& value) {
        if (!head) {
            head = new Node{value, nullptr, nullptr};
            tail = head;
        } else {
            tail->next = new Node{value, nullptr, tail};
            tail = tail->next;
        }
    }

    void delete_element(Node* node_to_delete) {
        if (!node_to_delete) return;

        if (node_to_delete == head) {
            head = node_to_delete->next;
            if (head != nullptr) {
                head->previous = nullptr;
            }
        } else {
            if (node_to_delete->previous != nullptr) {
                node_to_delete->previous->next = node_to_delete->next;
            }
            if (node_to_delete->next != nullptr) {
                node_to_delete->next->previous = node_to_delete->previous;
            }
        }

        delete node_to_delete;
    }

    void push_front(const int& value) {
        if (head == nullptr) {
            head = new Node{value, nullptr, nullptr};
            tail = head;
        } else {
            Node* newNode = new Node{value, head, nullptr};
            head->previous = newNode;
            head = newNode;
        }
    }

    void save_to_file(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "The file does not exist!" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            file << current->data << " ";
            current = current->next;
        }
        file.close();
        cout << "The list was saved to a file \"" << filename << "\"." << endl;
    }

    void clear_list() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "The list was destroyed." << endl;
    }

    void list_restore(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: opening file for reading!" << endl;
            return;
        }
        clear_list();
        int key;
        while (file >> key) {
            push_front(key);
        }
        file.close();
        cout << "The list was restored from file '" << filename << "'." << endl;
    }

    ~DoubleLinkedList() {
        clear_list();
    }
};

int main() {
    DoubleLinkedList list;

    for (int value = 0; value < 10; value++) {
        list.add(value);
    }
    cout << "The list:" << endl;
    list.print_list();

    list.push_front(2);
    cout << "The list after changes:" << endl;
    list.print_list();

    list.delete_by_index(2);
    list.print_list();
    
    list.save_to_file("list.txt");

    list.clear_list();
    cout << "The cleared list:" << endl;
    list.print_list();

    list.list_restore("list.txt");
    cout << "List after recovery from file:" << endl;
    list.print_list();

    list.clear_list();
    cout << "List after final destruction:" << endl;
    list.print_list();

    return 0;
}