#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    void insert_before(int index, int listSize, int values[]);
    void insert_after(int index, int listSize, int values[]);
    void erase(int index, int count);
    int get(int index);
    void set(int index, int value);
    int getSize();
    void print();
    void saveToFile(const string& filename);
    void destroy();
    void restoreFromFile(const string& filename);

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
        return os;
    }

private:
    Node* head;
    int size;
};

// Реалізація методів
void LinkedList::insert_before(int index, int listSize, int values[]) {
    if (index < 0 || index > size || listSize <= 0) {
        return;
    }

    if (index == 0) { 
        for (int i = listSize - 1; i >= 0; i--) {
            Node* newNode = new Node(values[i]);
            newNode->next = head;
            head = newNode;
            size++;
        }
    } else {
        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        for (int i = 0; i < listSize; i++) {
            Node* newNode = new Node(values[i]);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode;
            size++;
        }
    }
}


void LinkedList::insert_after(int index, int listSize, int values[]) {
    if (index < 0 || index > size || listSize <= 0) {
        return;
    }
    
    if (index == 0) {
        for (int i = listSize - 1; i >= 0; i--) {
            Node* newNode = new Node(values[i]);
            newNode->next = head;
            head = newNode;
            size++;
        }
        return;
    }

    Node* current = head;

    for (int i = 0; i < index - 1; i++) {
            current = current->next;
    }

    for (int i = 0; i < listSize; i++) {
            Node* newNode = new Node(values[i]);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode;
            size++;
    }
    
}

void LinkedList::erase(int index, int count) {
    if (index < 0 || index >= size || count <= 0) return;

    if (index == 0) {
        for (int i = 0; i < count && head != nullptr; i++) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
            size--;
        }
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) current = current->next;
        for (int i = 0; i < count && current->next != nullptr; i++) {
            Node* nextNode = current->next;
            current->next = nextNode->next;
            delete nextNode;
            size--;
        }
    }
}

int LinkedList::get(int index) {
    if (index < 0 || index >= size) return -1;

    Node* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    return current->data;
}

void LinkedList::set(int index, int value) {
    if (index < 0 || index >= size) return;

    Node* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    current->data = value;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::print() {
    Node* current = head;
    if (!current) {
        cout << "List empty" << endl;
        return;
    }   

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
   cout << endl;
}

void LinkedList::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Node* current = head;
    while (current) {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
    cout << "List succesfully inputed in file: \"" << filename << "\"." << endl;
}

void LinkedList::destroy() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
    cout << "List destroyed." << endl;
}

void LinkedList::restoreFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    destroy();

    int value;
    while (file >> value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    file.close();
    cout << "List succesfully restored from: \"" << filename << "\"." << endl;
}




int main() {
    LinkedList list;
    int values[] = {1, 2, 3, 4, 5};
    
    list.insert_after(0, 5, values);
    list.print();
    
    int values2[] = {1};
    list.insert_before(3, 1, values2);
    list.print();
    list.erase(5, 1);
    list.print();
    list.saveToFile("List.txt");
    list.destroy();
    list.print();
    list.restoreFromFile("List.txt");
    list.print();
    list.destroy();
    
    return 0;
}