#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void AddAtEnd(Node*& head, int val){
    Node* NewNode = new Node(val);
    if (head == nullptr) {
        head = NewNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = NewNode;
}

void AddAtStart(Node*& head, int val){
    Node* NewNode = new Node(val);
    NewNode->next = head;
    head = NewNode;
}

void Print(Node* main) {
    Node* temp = main;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void AddAtMiddle(Node** head, int x) {
    if (*head == NULL)
        *head = new Node(x);
    else {
        Node* newNode = new Node(x);
 
        Node* ptr = *head;
        int len = 0;
 
        while (ptr != NULL) {
            len++;
            ptr = ptr->next;
        }
 
        int count = ((len % 2) == 0) ? (len / 2) : (len + 1) / 2;
        ptr = *head;
 
        while (count-- > 1) ptr = ptr->next;
 
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void BubbleSort(Node* head){
    bool check;
    do {
        check = false;
        Node* curr = head;
        while (curr->next) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
                check = true;
            }
            curr = curr->next;
        }

    } while (check);
}


struct DBNode{
    int data;
    DBNode* next;
    DBNode* prev;
    DBNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void AddAtEndDB(DBNode*& head, int val){
    DBNode* NewNode = new DBNode(val);
    if (head == nullptr) {
        head = NewNode;
        return;
    }

    DBNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = NewNode;
    NewNode->prev;
}

void AddAtStartDB(DBNode*& head, int val){
    DBNode* NewNode = new DBNode(val);
    NewNode->next = head;
    if (head != nullptr){
        head->prev = NewNode;
    }

    head = NewNode;
}

void PrintDB(DBNode* head){
    DBNode* curr = head;
    while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void BubbleSortDB(DBNode* head){
    bool check;
    do {
        check = false;
        DBNode* curr = head;
        DBNode* last = nullptr;
        while (curr->next != last){
            if (curr->data > curr->next->data){
                swap(curr->data, curr->next->data);
                check = true;
            }
            curr = curr->next;
        }
        last = curr;
    } while (check);

}

int main(){
    Node* main = nullptr;
    AddAtEnd(main, 43);
    AddAtEnd(main, 22);
    AddAtEnd(main, 174);
    AddAtEnd(main, 16);
    Print(main);

    AddAtStart(main, 82);
    Print(main);

    AddAtMiddle(&main, 55);
    Print(main);

    BubbleSort(main);
    Print(main);


    DBNode* mainDB = nullptr;
    AddAtEndDB(mainDB, 53);
    AddAtEndDB(mainDB, 6);
    AddAtEndDB(mainDB, 864);
    AddAtEndDB(mainDB, 22);
    PrintDB(mainDB);

    AddAtStartDB(mainDB, 72);
    PrintDB(mainDB);

    BubbleSortDB(mainDB);
    PrintDB(mainDB);

    return 0;
}