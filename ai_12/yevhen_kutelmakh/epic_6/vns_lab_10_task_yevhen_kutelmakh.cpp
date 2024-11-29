#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
Записи в лінійному списку містять ключове поле типу int. Сформувати
двонаправлений список. Знищити з нього елемент із заданим номером,
додати елемент у початок списку.
*/

struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    int size;

    int makenum(string word) {
        return stoi(word);
    }
public:
    DoublyLinkedList() {
        size = 0;
        head = nullptr;
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr)
            head = newNode;
        else {
            Node* curr = head;
            while(curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
        size++;
    }

    void pushBack(int value, int n) {
        Node* newNode = new Node(value);
        if(size==0) head = newNode; 
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
    }

    void print() {
        if(head == nullptr)
            cout << "The list is empty";
        else {
            Node* curr = head;
            while(curr != nullptr) {
                cout << curr->value << " ";
                curr = curr->next;
            }
        } 
        cout << endl;
    }

    void remove(int index) {
        Node *current = head;
        int count = 0;
        while(count != index) {
            current = current->next;
            count++;
        }

        if (current->prev != nullptr)  
            current->prev->next = current->next; 
        else 
            head = current->next;

        if (current->next != nullptr) 
            current->next->prev = current->prev;

        delete current;
        size--;
    }

    void write(string name) {
        ofstream file(name);
        Node *cur = head;
        for(int i = 0; i < size; i++) {
            file << cur->value << "\n";
            cur = cur->next;
        }
        file.close();
    }

    void del() {
        Node *cur = head;
        while(cur != nullptr) {
            Node *nextN = cur->next;
            delete cur;
            cur = nextN;
        }
        head = nullptr;
        size = 0;
    }

    void recreate(string name) {
        ifstream file(name);
        string buffer;
        while(getline(file, buffer)) {
            int n = makenum(buffer);
            pushBack(n);
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    DoublyLinkedList list;
    int len = rand()%6 + 1;
    for(int i = 0; i < len; i++)
        list.pushBack(rand()%15);
    cout << "We have created our list, it contains: \n";
    list.print();
    cout << "Which element you want to delete?(enumaration starts from 0): ";
    int index;
    cin >> index;
    list.remove(index);
    cout << "Our list after deleting #" << index << " element:\n";
    list.print();
    list.pushBack(rand()%15, 0);
    cout << "Our list after adding a new element at the front:\n";
    list.print();
    cin.ignore();
    string name;
    cout << "Enter a name for the file: ";
    getline(cin, name);
    list.write(name);
    cout << "After writing to file, we delete our list:\n";
    list.del();
    list.print();
    cout << "Now we recreating our list from your file:\n";
    list.recreate(name);
    list.print();
    list.del();
    return 0;
}