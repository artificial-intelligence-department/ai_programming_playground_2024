#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int key) : value(key), next(nullptr) {}
};

class LinkedList {
private:
    Node* head1;
    Node* head2;
    Node* head3;

    void deleteNode(Node*& current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    void destroyLists() {
        while (head1) {
            deleteNode(head1);
        }
        while (head2) {
            deleteNode(head2);
        }
        while (head3) {
            deleteNode(head3);
        }
    }

public:
    LinkedList() : head1(nullptr), head2(nullptr), head3(nullptr) {}

    ~LinkedList() {
        destroyLists();
    }

    void createCaller(int headNum, int* values, int valuesNum) {
        switch (headNum) {
        case 1:
            create(head1, values, valuesNum);
            break;
        case 2:
            create(head2, values, valuesNum);
            break;
        case 3:
            create(head3, values, valuesNum);
            break;
        default:
            cout << "Invalid list number" << endl;
        }
    }

    void create(Node*& head, int* values, int valuesNum) {
        Node* current = head;
        int start = 0;

        if (current == nullptr) {
            head = new Node(values[0]);
            current = head;
            start++;
            
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
        }

        for (int i = start; i < valuesNum; i++) {
            current->next = new Node(values[i]);
            current = current->next;
        }
    }

    void funcCaller(string action, int listNum) {
        if (action == "reverse") {
            switch (listNum) {
            case 1: reverse(head1); break;
            case 2: reverse(head2); break;
            case 3: reverse(head3); break;
            default: cout << "Invalid list number" << endl;
            }
        } else if (action == "print") {
            switch (listNum) {
            case 1: print(head1); break;
            case 2: print(head2); break;
            case 3: print(head3); break;
            default: cout << "Invalid list number" << endl;
            }
        } else {
            cout << "Invalid action" << endl;
        }
    }

    void reverse(Node*& head) {
        Node* curNode = head;
        Node* nextNode = nullptr;
        Node* prevNode = nullptr;

        while (curNode != nullptr) {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head = prevNode;
    }

    void add() {
        Node* current1 = head1;
        Node* current2 = head2;
        Node* current3 = head3;

        while (current1 != nullptr || current2 != nullptr) {
            int value = 0;

            if (current1 != nullptr) {
                value += current1->value;
                current1 = current1->next;
            }

            if (current2 != nullptr) {
                value += current2->value;
                current2 = current2->next;
            }

            Node* newNode = new Node(value);

            if (head3 == nullptr) {
                head3 = newNode;
                current3 = head3;
            } else {
                current3->next = newNode;
                current3 = newNode;
            }
        }
    }

    bool compare() {
        Node* current1 = head1;
        Node* current2 = head2;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->value != current2->value) 
                return false;
            current1 = current1->next;
            current2 = current2->next;
        }

        return current1 == nullptr && current2 == nullptr;
    }


    void print(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int actionsNum;
    cout << "Enter number of actions: ";
    cin >> actionsNum;

    while (actionsNum--) {
        string action;
        cout << "Enter action: ";
        cin >> action;

        if (action == "add") {
            list.add();
            continue;
        } else if (action == "compare") {
            if (bool answer = list.compare()) cout << "true\n";
            else cout << "false\n";
            
            continue;
        }

        int headNum;
        cout << "Enter list number: ";
        cin >> headNum;

        if (action == "create") {
            int valuesNum;
            cout << "Enter number of values: ";
            cin >> valuesNum;

            int* values = new int[valuesNum];
            cout << "Enter values: ";
            for (int i = 0; i < valuesNum; i++) cin >> values[i];

            list.createCaller(headNum, values, valuesNum);
            delete[] values;

        } else {
            list.funcCaller(action, headNum);
        }
    }

    return 0;
}
