#include <iostream>

using namespace std;


struct Node {
    int value;
    Node *next;
};


class linkedList {
    private:
        Node* head;

        void deleteNode(Node*& current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        void destroyTree() {
            while (head != nullptr) {
                deleteNode(head);
            }
        }

    public:
        linkedList() : head(nullptr) {}

        ~linkedList() {
            destroyTree();
        }

        void insert(int value, int position) {
            Node *newNode = new Node{value, nullptr};

            if (position == 0) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node *current = head;
            int currentIndex = 0;

            while (current != nullptr && currentIndex < position - 1) {
                current = current->next;
                currentIndex++;
            }

            newNode->next = current->next;
            current->next = newNode;
            return;
        }

        void erase(int index, int diapasone) {
            if (index == 0) {
                for (int i = 0; i < diapasone && head != nullptr; i++) {
                    deleteNode(head);
                }
                return;
            }

            Node *current = head;
            int currentIndex = 0;

            while (current != nullptr && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }

            Node *toDelete = current->next;

            for (int i = 0; i < diapasone && toDelete != nullptr; i++) {
                deleteNode(toDelete);
            }

            current->next = toDelete;
            return;
        }

        int size() {
            Node *current = head;

            int listSize = 0;
            while (current != nullptr) {
                current = current->next;
                listSize++;
            }

            return listSize;
        }

        void capacity() {
            Node *current = head;
            if (current == nullptr) {
                cout << 1 << endl;
                return;
            }

            int listSize = size();

            int num = 2;
            while (listSize >= num) {
                num *= 2;
            }
            cout << num << endl;
            return;
        }

        void get(int index) {
           Node *current = head;

           for (int i = 0; i < index; i++) {
            current = current->next;
           } 

           cout << current->value << endl;
           return;
        }

        void set(int index, int value) {
            Node *current = head;

           for (int i = 0; i < index; i++) {
            current = current->next;
           }

           current->value = value;
           return;
        }

        void print() const {
            Node *current = head;
            while (current != nullptr) {
                cout << current->value << " ";
                current = current->next;
            }
            
            cout << endl;
            return;
        }
};


int main() {
    linkedList list;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string choise;
        cin >> choise;

        if (choise == "insert") {
            int index, N; 
            cin >> index >> N;
            for (int j = 0; j < N; j++) {
                int value;
                cin >> value;
                list.insert(value, index + j);
            }

        } else if (choise == "erase") {
            int index, diapasone;
            cin >> index >> diapasone;
            list.erase(index, diapasone);

        } else if (choise == "capacity") {
            list.capacity();

        } else if (choise == "get") {
            int index;
            cin >> index;
            list.get(index);

        } else if (choise == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);

        } else if(choise == "size") {
            cout << list.size() << endl;

        } else if (choise == "print") {
            list.print();
        }
    }

    return 0;
}
