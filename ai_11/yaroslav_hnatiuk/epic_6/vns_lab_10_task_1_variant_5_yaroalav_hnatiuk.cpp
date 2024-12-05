#include <iostream>
#include <fstream>
#include <random>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node *head;

        void deleteNode(Node*& current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        void destroyTree() {
            while (head) {
                deleteNode(head);
            }
        }

    public:
        LinkedList() : head(nullptr) {}

        ~LinkedList() {
            destroyTree();
        }

        void addElement(int position, int diapazone) {
            srand(time(nullptr));

            for (int i = 0; i < diapazone; i++) {
                int value = (rand() % 90) + 10;

                Node *newNode = new Node{value, nullptr};

                if (position == 0 || head == nullptr) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    Node* current = head;
                    for (int j = 0; j < position - 1 && current->next != nullptr; ++j) {
                        current = current->next;
                    }
                    newNode->next = current->next;
                    current->next = newNode;
                }
                position++;
            }
        }

        void removeElements(int position, int diapazone) {
            if (!head || diapazone <= 0 || position < 0) {
                cout << "Invalid range or empty list. No elements removed." << endl;
                return;
            }

            Node* current = head;
            Node* prev = nullptr;

            for (int i = 0; i < position && current != nullptr; ++i) {
                prev = current;
                current = current->next;
            }

            for (int i = 0; i < diapazone && current != nullptr; ++i) {
                Node* temp = current;
                current = current->next;
                if (prev) {
                    prev->next = current;
                } else {
                    head = current;
                }
                delete temp;
            }
        }

        void printList() const {
            Node* current = head;
            while (current) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "null" << endl;
        }

        void saveToFile(const string& filename) const {
            ofstream file(filename);
            if (!file.is_open()) {
                cerr << "Unable to open file for writing!" << endl;
                return;
            }

            Node* current = head;
            while (current) {
                file << current->data << " ";
                current = current->next;
            }
            file.close();
        }

        void loadFromFile(const string& filename) {
            destroyTree();

            ifstream file(filename);
            if (!file.is_open()) {
                cerr << "Unable to open file for reading!" << endl;
                return;
            }

            int value;
            while (file >> value) {
                addElement(value, getSize());
            }
            file.close();
        }

        int getSize() const {
            int size = 0;
            Node* current = head;
            while (current) {
                ++size;
                current = current->next;
            }
            return size;
        }
};

int main() {
    LinkedList list;
    string filename = "list_data.txt";

    while (true) {
        cout << "\n1. Add elements to the list" << endl;
        cout << "2. Remove elements from the list" << endl;
        cout << "3. Print the list" << endl;
        cout << "4. Save the list to a file" << endl;
        cout << "5. Load the list from a file" << endl;
        cout << "\nChoose an action: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Exiting program." << endl;
            break;
        }

        switch (choice) {
        case 1: 
            int position, diapazone;
            cout << "Enter the position of the first element: ";
            cin >> position;
            cout << "Enter the number of new items: ";
            cin >> diapazone;

            if (cin.fail() || position < 0 || diapazone <= 0) {
                cout << "Invalid input. Exiting program." << endl;
                return 1;
            }

            list.addElement(position, diapazone);
            cout << "Elements added successfully." << endl;
            break;
        
        case 2: 
            int startPos, count;
            cout << "Enter the starting position: ";
            cin >> startPos;
            cout << "Enter the number of elements to remove: ";
            cin >> count;

            if (cin.fail() || startPos < 0 || count <= 0) {
                cout << "Invalid input. Exiting program." << endl;
                return 1;
            }

            list.removeElements(startPos, count);
            cout << "Elements removed successfully." << endl;
            break;

        case 3:
            cout << "The list is: ";
            list.printList();
            break;

        case 4:
            list.saveToFile(filename);
            cout << "List saved to file successfully." << endl;
            break;

        case 5:
            list.loadFromFile(filename);
            cout << "List loaded from file successfully." << endl;
            break;

        default:
            cout << "Invalid input. Exiting program." << endl;
            return 1;
        }
    }

    return 0;
}

