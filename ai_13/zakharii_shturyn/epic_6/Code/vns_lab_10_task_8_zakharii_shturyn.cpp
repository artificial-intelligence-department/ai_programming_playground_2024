#include <iostream>
#include <vector>
#include <fstream>
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

    void add(vector<int>& arr) {
        for (int i = arr.size() - 1; i >= 0; i--) {
            Node* newNode = new Node(arr[i]);
            newNode->next = head;
            head = newNode;
        }
    }

    void erase(int index, int size) {
        if(index > 0 && index < size) {
            int pos = 0;
            Node* firstNode = head;
            while(firstNode != nullptr && pos != index) {
                firstNode = firstNode->next;
                pos++;
            }
            Node* lastNode = firstNode->next;
            Node* tmp = firstNode;
            tmp = tmp->next;
            lastNode = tmp->next;
            firstNode->next = lastNode;
        } else if (index == 0){
            head = head->next;
        } else {
            cout << "Invalid option" << endl;;
        }
    }

    void print(int size) {
        if(size > 0) {
            Node* tmp = head;
            while(tmp != nullptr) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        } else {
            cout << "List is empty" << endl;
        }
    }

    void save(string& filename) {
        ofstream myFile(filename, ios::out);
        if (myFile.is_open()) {
        Node* tmp = head;
        while(tmp != nullptr) {
            myFile << tmp->data << " ";
            tmp = tmp->next;
        }
        myFile.close();
        } else {
            cout << "Can't open file" << endl;
        }
    }

    void load(string& filename) {
        clear();
        ifstream myFile(filename, ios::in);
        vector<int> tmp;
        if (myFile.is_open()) {
            int num;
            while(myFile >> num) {
                tmp.push_back(num);
            }
            myFile.close();
            add(tmp);
        } else {
            cout << "Can't open file" << endl;
        }
    }

    void clear() {
        while(head != nullptr) {
            Node* tmp = head->next;
            delete[] head;
            head = tmp; 
        }
    }

    int size() {
        int size = 0;
        Node* tmp = head;
        while(tmp != nullptr) {
            tmp = tmp->next;
            size++;
        }
        return size;
    }


};


int main() {
    string filename = "linked list.txt";
    int size;
    LinkedList list;
    string opt;
    while(opt != "exit") {
        cin >> opt;
        size = list.size();
        if(opt == "add") {
            int size;
            cin >> size;
            vector<int> arr(size);
            for(int j = 0; j < size; j++) {
                cin >> arr[j];
            }
            list.add(arr);
        } else if (opt == "erase") {
            int index;
            cin >> index;
            list.erase(index,size);
        } else if(opt == "print") {
            list.print(size);
        } else if(opt == "save") {
            list.save(filename);
        } else if(opt == "load") {
            list.load(filename);
        } else if(opt == "clear") {
            list.clear();
        }
    }
    return 0;
}