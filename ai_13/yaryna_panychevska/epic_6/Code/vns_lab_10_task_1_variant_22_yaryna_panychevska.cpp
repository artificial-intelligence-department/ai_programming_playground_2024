#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    string Data;
    Node* Next;
    Node* Prev;
};

//Запис у файл
void writeListToFile(Node* head, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Error: Could not open file for writing!" << endl;
        return;
    }

    Node* Current_Node = head;
    while (Current_Node != NULL) {
        outFile << Current_Node->Data << endl; // Записуємо кожен вузол у файл
        Current_Node = Current_Node->Next;
    }

    outFile.close();
    cout << "\n" << "List written to file: " << filename << endl;
}

Node* createNode(string s) {
    Node* New_Node = new Node;
    New_Node->Data = s;
    New_Node->Prev = NULL;
    New_Node->Next = NULL;
    return New_Node;
}

//Відновлення списку з файлу
Node* readListFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error: Could not open file for reading!" << endl;
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;
    string line;

    while (getline(inFile, line)) {
        Node* New_Node = createNode(line);

        if (head == NULL) {
            head = tail = New_Node;
        }
        else {
            tail->Next = New_Node;
            New_Node->Prev = tail;
            tail = New_Node;
        }
    }

    inFile.close();
    cout << "\n" << "List restored from file: " << filename << endl;
    return head;
}

//Додання елементів перед заданим елементом
Node* insertBefore(Node* head, Node* position, const string& s1, const string& s2) {
    Node* newNode1 = createNode(s1);
    Node* newNode2 = createNode(s2);

    newNode1->Next = position;
    head->Prev = newNode1;
    head = newNode1;

    newNode2->Next = newNode1;
    newNode1->Prev = newNode2;
    head = newNode2;

    return head;
}

//Видалення вузла 
Node* deleteNode(Node* head, int position) {
    Node* Current_Node = head;
    int index = 1;

    // Перехід до вузла на заданій позиції
    while (Current_Node != NULL && index < position) {
        Current_Node = Current_Node->Next;
        index++;
    }

    // Якщо позиція не знайдена
    if (Current_Node == NULL) {
        cout << "\n" << "Position out of range." << endl;
        return head;
    }

    Current_Node->Prev->Next = Current_Node->Next;
    Current_Node->Next->Prev = Current_Node->Prev;

    delete (Current_Node);
    return head;
}

//Видалення списку
void deleteList(Node* head) {
    Node* Current_Node = head;
    while (Current_Node != NULL) {
        Node* tempNode = Current_Node->Next;
        delete Current_Node;
        Current_Node = tempNode;
    }
    head = NULL;
    cout << "\n" << "List deleted successfully." << endl;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << "" << head->Data << " <-> ";
        head = head->Next;
        if (head == NULL) {
            cout << "NULL";
        }
    }
}
//-----------------------------------------------------------------------------//
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string s = "Apple Kiwi Banana Pineaplle Orange ";
    istringstream iss(s);
    string word;

    while (iss >> word) {
        Node* New_Node = createNode(word);

        if (head == NULL) {
            head = New_Node;
            tail = New_Node;
        }
        else {
            tail->Next = New_Node;
            New_Node->Prev = tail;
            tail = New_Node;
        }
    }

    cout << "Linked list: ";
    printList(head);

    int position = 3;
    head = deleteNode(head, position);

    cout << "\n" << "Updated linked list after deleting Banana: ";
    printList(head);

    head = insertBefore(head, head, "Grapes", "Mango");

    cout << "\n" << "Updated linked list after adding 2 elements before Apple: ";
    printList(head);

    writeListToFile(head, "list.txt");

    deleteList(head);

    head = readListFromFile("list.txt");

    cout << "Restored linked list: ";
    printList(head);

    return 0;
}