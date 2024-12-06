#include <iostream>
#include <cstring> // ��� ������� strcpy_s, strlen
#include <fstream> // ��� ������ � �������

struct Node { // ��������� ��� ������������� �������� ������
    char* data;
    Node* next;
    Node* prev;

    // �����������
    Node(const char* str) {
		data = new char[strlen(str) + 1]; // strlen ������� ������� ����� str
		strcpy_s(data, strlen(str) + 1, str); // strcpy_s ����� ����� str � data
		next = prev = nullptr;  // nullptr - �� ���������, ��� ����� �� ����-��������
    }

    // ����������
    ~Node() {
        delete[] data;
    }
};

class DoublyLinkedList { // ���� ��� ������������� ��������������� ������
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void add(const char* data) { // ��������� �������� � ����� ������
		Node* newNode = new Node(data); // ��������� ������ ��������
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(const char* key) { // ��������� �������� � ������
		Node* current = head; // �������� � ������ ������
        while (current) { 
			if (strcmp(current->data, key) == 0) {  // strcmp ������� ��� �����
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                if (current == head)
                    head = current->next;
                if (current == tail)
                    tail = current->prev;
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
            else {
                current = current->next;
            }
        }
    }

    void addAfter(const char* key, const char* data) { // ��������� �������� ���� �������� �����
        Node* current = head; 
        while (current) { 
			if (strcmp(current->data, key) == 0) {  // ����� �����
                Node* newNode = new Node(data);
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next)
                    current->next->prev = newNode;
                current->next = newNode;
                if (current == tail)
                    tail = newNode;
                break;
            }
            current = current->next;
        }
    }

    void print() const { // ���� ������
        if (!head) {
            std::cout << "List is empty\n";
            return;
        }
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    void saveToFile(const char* filename) const { // ����� ������ � ����
		std::ofstream outFile(filename); // �������� ����� ��� ������
        Node* current = head; 
        while (current) {
            outFile << current->data << "\n";
            current = current->next;
        }
        outFile.close();
    }

    void loadFromFile(const char* filename) { // ³��������� ������ � �����
        clear();
        std::ifstream inFile(filename);
		char buffer[256]; // ����� ��� ���������� ����� � ����� (����� - �� ����� �������)
        while (inFile.getline(buffer, 256)) {
            add(buffer);
        }
        inFile.close();
    }

    void clear() { // �������� ������
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = tail = nullptr;
    }
};

int main() {
	DoublyLinkedList list;  // double linked list - ��������������� ��� ��������� ������ ��������

    // ��������� �������� � ������
    list.add("apple");
    list.add("banana");
    list.add("cherry");

    // ���� ������
    std::cout << "List after adding items: ";
    list.print();

    // ��������� �������� ���� �������� �����
    list.addAfter("banana", "blueberry");

    std::cout << "List after adding 'blueberry' after 'banana': ";
    list.print();

    // ��������� �������� � ������
    list.remove("banana");

    std::cout << "List after 'banana' removal: ";
    list.print();

    // ����� ������ � ����
    list.saveToFile("list.txt");

    // �������� ������
    list.clear();
    std::cout << "List after destruction: ";
    list.print();

    // ³��������� ������ � �����
    list.loadFromFile("list.txt");

    std::cout << "List after recovery from file: ";
    list.print();

    // �������� ������
    list.clear();
    std::cout << "List after destruction: ";
    list.print();

    return 0;
}
