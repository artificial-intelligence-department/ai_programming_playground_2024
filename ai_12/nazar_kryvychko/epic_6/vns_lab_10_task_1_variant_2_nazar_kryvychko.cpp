#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>




template <class T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;

        Node(T value, Node* next = nullptr, Node* prev = nullptr)
            : value(value), next(next), prev(prev) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    std::size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void print() const {
        if (!head) {
            std::cout << "Empty List!" << std::endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\b";
        std::cout << std::endl;
    }

    void save_to_file(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) { 
            throw std::ios_base::failure("Failed to create or open the file: " + filename);
        }

        Node* temp = head;
        while (temp) {
            file << temp->value << " ";
            temp = temp->next;
        }
        file.close();
    }

    void load_from_file(const std::string& filename) {
        clear();
        std::ifstream file(filename);
        if (!file) { // Check if the file was opened successfully
            throw std::ios_base::failure("Failed to create or open the file: " + filename);
        }
        T value;
        while (file >> value) {
            push_back(value);
        }
        file.close();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    void insert(int index, T el) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");
        }

        Node* newNode = new Node(el);

        if (index == 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (size == 0) {
                tail = newNode;
            }
        }
        else if (index == size) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        size++;
    }

    void insert(int index, int elCount, T* els) {
        if (elCount <= 0) {
            return;
        }

        Node* newHead = new Node(els[0]);
        Node* current = newHead;

        for (int i = 1; i < elCount; ++i) {
            current->next = new Node(els[i], nullptr, current);
            current = current->next;
        }

        if (index == 0) {
            if (head) {
                current->next = head;
                head->prev = current;
            }
            head = newHead;
            if (size == 0) {
                tail = current;
            }
        }
        else {
            Node* prev = head;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            current->next = prev->next;
            if (prev->next) {
                prev->next->prev = current;
            }
            prev->next = newHead;
            newHead->prev = prev;

            if (index == size) {
                tail = current;
            }
        }

        size += elCount;
    }

    void erase(int index, int count) {
        if (index == 0) {
            Node* temp = head;
            for (int i = 0; i < count; ++i) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            head = temp;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else {
            Node* prev = head;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }

            Node* current = prev->next;
            for (int i = 0; i < count; ++i) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            prev->next = current;
            if (current) {
                current->prev = prev;
            }
            else {
                tail = prev;
            }
        }

        size -= count;
    }


    std::size_t get_size()
    {
        return this->size;
    }
};

int main() {
    LinkedList<int> list;

    std::cout << "Test Case 1: Inserting elements 1, 2, 3, 4, 5" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
    }
    list.print();

    std::cout << "Test Case 2: Inserting element 10 at index 2" << std::endl;
    list.insert(2, 10);
    list.print();

    std::cout << "Test Case 3: Erasing 2 elements starting from index 2" << std::endl;
    list.erase(2, 2);
    list.print();

    std::cout << "Test Case 4: Checking size of the list" << std::endl;
    std::cout << "Size: " << list.get_size() << std::endl;

    std::cout << "Test Case 5: Saving list to file 'list.txt'" << std::endl;
    list.save_to_file("D:\\nulp\\OP\\AllEpics\\Sixth\\list.txt"); // Explicit path ( Vs code g++ specific )

    std::cout << "Test Case 6: Clearing the list" << std::endl;
    list.clear();
    list.print(); 

    std::cout << "Test Case 7: Loading list from file 'list.txt'" << std::endl;
    list.load_from_file("D:\\nulp\\OP\\AllEpics\\Sixth\\list.txt"); // Explicit path ( Vs code g++ specific )
    list.print(); 

    std::cout << "Test Case 8: Erasing element at index 1" << std::endl;
    list.erase(1, 1);
    list.print(); 

    std::cout << "Test Case 9: Inserting element 6 at the end" << std::endl;
    list.push_back(6);
    list.print(); 

    std::cout << "Test Case 10: Final size of the list" << std::endl;
    std::cout << "Size: " << list.get_size() << std::endl;

    return 0;
}
