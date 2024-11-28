#include <iostream>
#include <vector>
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
public:
    LinkedList() {
        head = nullptr;
    }

    void append(vector<int>& arr) {
        for (int i = arr.size() - 1; i >= 0; i--) {
            Node* newNode = new Node(arr[i]);
            newNode->next = head;
            head = newNode;
        }
    }

    void reverse() {
        Node* prv = head;
        if(head->next != nullptr) {
            Node* tmp = head->next;
            head->next = nullptr;
            head = tmp;
        }
        while(head->next != nullptr) {
            Node* nxt = head->next;
            head->next = prv;
            prv = head;
            head = nxt;
        }
        head->next = prv;
    }

    void print() {
        Node* tmp = head;
        while(tmp != nullptr) {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << "null" << endl;
    }

    Node* getHead() {
        return head;
    }

};

void add(Node* n1, Node* n2) {
    vector<int> tmp(0);
    string forsum = "";
    while(n1 != nullptr && n2 != nullptr) {
        int sum = n1->data + n2->data;
        string sum_str = to_string(sum);
        if(sum_str.length() > 1) {
            for(int i = 0; i < sum_str.length(); i++) {
                tmp.insert(tmp.begin(), sum_str[i] - '0');
            }
        } else{
            tmp.insert(tmp.begin(), sum);
        }
        forsum += to_string(sum);
        n1 = n1->next;
        n2 = n2->next;
    }

    LinkedList list;
    list.append(tmp);
    cout << "Number of sum is: " << forsum << endl;
    list.print();
    }


bool compare(Node* h1, Node* h2) {
    while(h1->next != nullptr && h2->next != nullptr) {
        if(h1->data != h2->data) {
            return false;
        } else {
            h1 = h1->next;
            h2 = h2->next;
        }
    }

    return h1->next == nullptr && h2->next == nullptr;
}

int main () {

    string opt;
    LinkedList list1;
    LinkedList list2;
    vector<int> arr1 = {6,4,1,2,3,11};
    vector<int> arr2 = {9,0,7,8,4,1};
    // vector<int> arr2 = {6,4,1,2,3,11};
    list1.append(arr1);
    list2.append(arr2);
    cout << "Our lists: " << endl;
    list1.print();
    list2.print();
    cout << endl;
    list1.reverse();
    list2.reverse();
    cout << "Task 1" << endl <<  "Our reversed lists: " << endl;
    list1.print();
    list2.print();
    cout << endl << "Task 2" << endl;
    if(compare(list1.getHead(), list2.getHead())) {
        cout << "Lists are equal" << endl << endl;
    } else {
        cout << "Lists are different" << endl << endl;
    }

    cout << "Task 3" << endl;
    add(list1.getHead(), list2.getHead());

    return 0;
}