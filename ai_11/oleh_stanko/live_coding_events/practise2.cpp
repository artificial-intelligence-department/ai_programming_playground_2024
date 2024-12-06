#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int index, int* arr, int size) {
        if (index == 0) {
            for (int i = size - 1; i >= 0; i--) {
                Node* newNode = new Node(arr[i]);
                newNode->next = head;
                if (head != nullptr) {
                    head->prev = newNode;
                }
                head = newNode;
                if (tail == nullptr) {
                    tail = head;
                }
            }
        } else {
            Node* tmp = head;
            int pos = 0;
            while (tmp != nullptr && pos < index - 1) {
                tmp = tmp->next;
                pos++;
            }
            if (tmp == nullptr) {
                throw invalid_argument("Index out of bounds");
            }
            Node* lastNode = tmp->next;
            for (int i = 0; i < size; i++) {
                Node* newNode = new Node(arr[i]);
                tmp->next = newNode;
                newNode->prev = tmp;
                tmp = newNode;
            }
            tmp->next = lastNode;
            if (lastNode != nullptr) {
                lastNode->prev = tmp;
            } else {
                tail = tmp;
            }
        }
    }

    void print() {
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void reverseprint() {
        if (tail == nullptr) return;
        Node* tmp = tail;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }
        cout << endl;
    }

    void clear() {
        while (head != nullptr) {
            Node* tmp = head->next;
            delete head;
            head = tmp;
        }
        tail = nullptr;
    }

    void sortarr() {
        int size = this->size();
        if (size == 0) return;

        int* arr = new int[size];
        Node* tmp = head;
        for (int i = 0; i < size; i++) {
            arr[i] = tmp->data;
            tmp = tmp->next;
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        clear();
        insert(0, arr, size);
        delete[] arr;
    }

    int size() {
        int count = 0;
        Node* tmp = head;
        while (tmp != nullptr) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void bubblesort() {
        int listsize = size();
        for (int i = 0; i < listsize; i++) {
            Node* tmp = head;
            while (tmp != nullptr && tmp->next != nullptr) {
                if (tmp->data > tmp->next->data) {
                    int tmpdata = tmp->data;
                    tmp->data = tmp->next->data;
                    tmp->next->data = tmpdata;
                }
                tmp = tmp->next;
            }
        }
    }
};

int main() {
    LinkedList list;

    int tmp[] = {1, -2, 3, 6, 13, 0, -1};
    int tm1[] = {2, 42};

    list.insert(0, tmp, 7);  
    list.insert(5, tm1, 2); 

    cout << "Початковий список:" << endl;
    list.print();

    list.bubblesort();
    cout << "Відсортований список:" << endl;
    list.print();

    cout << "Реверсований список:" << endl;
    list.reverseprint();

    return 0;
}
