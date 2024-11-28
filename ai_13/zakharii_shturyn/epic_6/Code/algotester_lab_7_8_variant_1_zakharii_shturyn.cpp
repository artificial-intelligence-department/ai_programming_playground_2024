#include <iostream>
#include <vector>
using namespace std;


template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class LinkedList {
    Node<T>* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int index,vector<T>& arr) {
        if(index == 0) {
            for (int i = arr.size() - 1; i >= 0; i--) {
                Node<T>* newNode = new Node<T>(arr[i]);
                newNode->next = head;
                head = newNode;
            }
        } else {
            Node<T>* tmp = head;
            int pos = 0;
            while(tmp != nullptr && pos < index - 1) {
                tmp = tmp->next;
                pos++;
            }
            Node<T>* lastNode = tmp->next;
            for(T elm : arr) {
                Node<T>* newNode = new Node<T>(elm);
                tmp->next = newNode;
                tmp = newNode;
            }
            tmp->next = lastNode;
        }
    }

    void erase(int index, int n) {
        if(index > 0) {
            int pos = 0;
            Node<T>* firstNode = head;
            while(firstNode != nullptr && pos != index - 1) {
                firstNode = firstNode->next;
                pos++;
            }
            Node<T>* lastNode = firstNode->next;
            Node<T>* tmp = firstNode;
            while(n-- > 0) {
                tmp = tmp->next;
                lastNode = tmp->next;

            }
            firstNode->next = lastNode;
        } else{
            for(int i = 0; i < n; i++) {
                head = head->next;
            }
        }
    }

    void size() {
        int count = 0;
        Node<T>* tmp = head;
        while(tmp != nullptr) {
            tmp = tmp->next;
            count++;
        }
        cout << count << endl;
    }

    void get(int index) {
        int start = 0;
        Node<T>* tmp = head;
        while(start != index) {
            tmp = tmp->next;
            start++;
        }
        cout << tmp->data << endl;
    }

    void set(int index, T value) {
        int start = 0;
        Node<T>* tmp = head;
        while(start != index) {
            tmp = tmp->next;
            start++;
        }
        tmp->data = value;
    }

    void print() {
        Node<T>* tmp = head;
        while(tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

};


int main() {
    LinkedList<int> list;
    string opt;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i ++) {
        cin >> opt;
        if(opt == "insert") {
            int index, size;
            cin >> index >> size;
            vector<int> arr(size);
            for(int j = 0; j < size; j++) {
                cin >> arr[j];
            }
            list.insert(index,arr);
        } else if (opt == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index,n);
        } else if(opt == "size") {
            list.size();
        } else if(opt == "get") {
            int index;
            cin >> index;
            list.get(index);
        } else if(opt == "set") {
            int index, a;
            cin >> index >> a;
            list.set(index,a);
        } else if(opt == "print") {
            list.print();
        }
    }
    return 0;
}