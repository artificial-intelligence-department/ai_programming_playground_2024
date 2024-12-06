// зайняло 1 год
#include <iostream>
#include <vector>
#include <algorithm>
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

    void insert(int index,vector<int>& arr) {
        if(index == 0) {
            for (int i = arr.size() - 1; i >= 0; i--) {
                Node* newNode = new Node(arr[i]);
                newNode->next = head;
                head = newNode;
                if(head->next == nullptr) {
                    tail = head;
                } else{ 
                    head->next->prev = newNode;
                }
            }

        } else {
            Node* tmp = head;
            int pos = 0;
            while(tmp != nullptr && pos < index - 1) {
                tmp = tmp->next;
                pos++;
            }
            Node* lastNode = tmp->next;
            for(int elm : arr) {
                Node* newNode = new Node(elm);
                tmp->next = newNode;
                newNode->prev = tmp;
                tmp = newNode;
            }
            tmp->next = lastNode;
            lastNode->prev = tmp;
        }
    }

    void print() {
        Node* tmp = head;
        while(tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    void reverseprint() {
        Node* tmp = tail;
        while(tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }
        cout << endl;
    }

    void clear() {
        while(head != nullptr) {
            Node* tmp = head->next;
            delete[] head;
            head = tmp; 
        }
    }

    void sortarr() {
        vector<int> sortedarr(0);
        Node* tmp = head;
        while(tmp != nullptr) {
            sortedarr.push_back(tmp->data);
            tmp = tmp->next;
        }

        for(int i = 0; i < sortedarr.size() - 1; i++) {
            for(int j = 0; j < sortedarr.size() - i - 1; j++) {
                if(sortedarr[j] > sortedarr[j + 1]) {
                    swap(sortedarr[j], sortedarr[j + 1]);
                }
            }
        }
        // sort(sortedarr.begin(), sortedarr.end());

        clear();
        insert(0,sortedarr);
    }

    int size() {
        int count = 0;
        Node* tmp = head;
        while(tmp != nullptr) {
            tmp = tmp->next;
            count++;
        }
        return count;
    }

    void bubblesort() {
        int listsize = size();
        for(int i = 0; i < listsize; i++) {
            Node* tmp = head;
            while(tmp->next != nullptr) {
                if(tmp->data > tmp->next->data) {
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
    vector<int> tmp = {1,-2,3,6,13,0,-1};
    vector<int> tm1 = {2,42};
    list.insert(0, tmp);
    list.insert(5, tm1);
    list.print();
    list.bubblesort();
    list.print();

    return 0;

}