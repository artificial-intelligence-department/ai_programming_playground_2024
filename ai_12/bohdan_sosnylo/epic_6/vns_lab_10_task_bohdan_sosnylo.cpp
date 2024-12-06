#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr){}
};

Node* addNode(Node* head, const vector<int>& value){
    Node* NewNode = new Node(value[0]);
    head = NewNode;
    Node* current = head;
    for (int i = 1; i < value.size(); i++) {
        Node* newNode = new Node(value[i]);
        current->next = newNode;  
        current = newNode;
    }
    return head;
    
    }

void printlist(Node* head){
    Node* current = head;
    while(current != nullptr){
    cout << current->data;
    current = current->next;
    }
}

void printFile(string file) {
    ifstream inFile(file);
    if (!inFile) {
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

    string content;
    getline(inFile, content); 
    inFile.close();

    if (content.empty()) {
        cout << "Список порожній" << endl;
    } else {
        cout << "Вміст файлу: " << content << endl;
    }
}

void addtoFile(string file, vector<int> node){
    ofstream outFile(file);

if (!outFile) { 
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }

    for (int n : node) {
        outFile << n << " ";
    }
    outFile.close(); 

}

void clearFile(string file) {
    ofstream outFile(file, ofstream::trunc); 
    if (!outFile) { 
        cerr << "Error: Unable to open file " << file << endl;
        return;
    }
    outFile.close(); 
}

Node* restoreFromFile(string file) {
    ifstream inFile(file);
    if (!inFile) {
        cerr << "Error: Unable to open file " << file << endl;
        return {};
    }
    Node* head = nullptr;
    vector<int> node;
    int value;
    while (inFile >> value) { 
        node.push_back(value);
    }

    addNode(head, node);
    inFile.close();
    
    return head;
}

void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteAtPosition(Node*& head, int position) {
    if (!head || position < 1) {
        cout << "Некоректний номер елемента" << endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    for (int i = 1; current && i < position - 1; ++i) {
        current = current->next;
    }
    if (!current || !current->next) {
        cout << "Елемент із заданим номером не існує" << endl;
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void addKElements(Node*& head, int position, int K) {
    if (position < 1 || K < 1) { 
        cout << "Некоректний номер або кількість елементів" << endl;
        return;
    }
    Node* current = head;

    for (int i = 1; current && i < position; ++i) {
        current = current->next;
    }

    if (!current) {
        cout << "Позиція поза списком" << endl;
        return;
    }

    for (int i = 0; i < K; ++i) {
        int value;
        cout << "Введіть значення для нового елемента: ";
        cin >> value; 

        Node* newNode = new Node(value); 
        newNode->next = current->next;  
        current->next = newNode;         
        current = newNode;               
    }
}


int main() {

    string fileName = "list.txt";
    Node* head = nullptr;
    int k;
    vector<int> vec;
    cout << "Введіть к-сть елементів у списку: ";
    cin>>k;
    vec.resize(k);
    for(int i = 0; i<k;i++){
        cin>>vec[i];
    }
    head = addNode(head, vec);
    cout << "Початковий список: ";
    printlist(head);
    cout<<endl;
    deleteAtPosition(head, 2);
    cout << "Після видалення елемента з позиції 2: ";
    printlist(head);
    cout<<endl;
    addKElements(head, 3, 3);
    cout << "Після додавання 3 елементів: ";
    printlist(head);
    cout<<endl;
    addtoFile(fileName, vec);

    clearList(head);
    cout << "Після знищення списку: ";
    printlist(head);
    cout<<endl;
    head = restoreFromFile(fileName);
    cout << "Після відновлення списку з файлу: ";
    printFile(fileName);
    cout<<endl;
    clearList(head);
    cout << "Після остаточного знищення списку: ";
    printlist(head);
    cout<<endl;
    return 0;
}