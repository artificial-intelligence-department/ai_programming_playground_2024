#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Node{
    int key;
    Node* next;
};

// 1. Create list
Node* createList() {
    Node* head = new Node{10, NULL}; 

    Node* second = new Node{20, NULL};
    head->next = second;  

    Node* third = new Node{30, NULL};
    second->next = third; 

    return head;
}

Node* list = createList(); 


// 2. Add element before element with key
void addBeforeTheKey(Node*& head, int targetKey, int newKey){
    Node* newNode = new Node {newKey, NULL};

    if (!head){
        cout << "List is empty. Adding is impossible." << endl;
        delete newNode;
        return;
    }

    //search for a node before a node with a given key 
    Node* current = head;
    while (current->next && current->next->key != targetKey){
        current = current->next;
    }

    if (current->next){
        newNode->next = current->next;
        current->next = newNode;
        cout << "Element is added successfully!" << endl; 
    } 
    else {
        cout << "Element with key " << targetKey << " isn't found." << endl;
        delete newNode;
    }
}

// 3. Killing element with specified key
void killElementWithKey(Node*& head, int keyForDelete){
    
    if (!head){
        cout << "List is empty. Adding is impossible." << endl;
        return;
    }

    if (head->key == keyForDelete){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    //search for a node before a node with a given key
    Node* current = head;
    while (current->next && current->next->key != keyForDelete){
        current = current->next;
    }

    if (current->next){
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    else{
        cout << "Element with key " << keyForDelete << " isn't found." << endl;
    }
}

// 4. Print list
void printList(Node*& head){
    
    if (!head){
        cout << "List is empty. Printing is impossible. " << endl;
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "Null" << endl;

}

// 5. Writing to file
void writingToFile(Node*& head){
    
    ofstream outFile("file.txt");

    if(!outFile){
        cerr << "Error while opening file for writing." << endl;
        return;
    }

    Node* current = head;
    while (current){
        outFile << current->key << " ";
        current = current->next; 
    }
    
    outFile.close();
    cout << "List is writing to file.txt successfully" << endl;

}

// 6. Restore list from file
void restoreListFromFile(Node*& head){
    ifstream inFile("file.txt");

    if (!inFile){
        cerr << "Error while opening file for reading." << endl;
        return;
    }

    int key;
    while (inFile >> key){
        Node* newNode = new Node {key, NULL};
        if (!head){
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    inFile.close();
    cout << "List is restored from file.txt " << endl;

}

// 7. Killing list
void killList(Node*& head){
    while (head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "List is deleted." << endl;
}

int main (){
    Node* list = createList();
    int choice, key, targetKey;

    do{
        cout << "1. Add element before element with key. " << endl;
        cout << "2. Killing element with specified key. " << endl;
        cout << "3. Print list. " << endl;
        cout << "4. Writing to file. " << endl;
        cout << "5. Restore list from file" << endl;
        cout << "6. Killing list" << endl;
        cout << "7. Exit" << endl;
        cout << "Please, choose an option. " << endl;
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter key for search: ";
                cin >> targetKey;
                cout << "Enter new key: ";
                cin >> key;
                addBeforeTheKey(list, targetKey, key);
                break;            
            
            case 2:
                cout << "Enter key for deleting: ";
                cin >> key;
                killElementWithKey(list, key);
                break;
                
            case 3:
                printList(list);
                break;
            
            case 4:
                writingToFile(list);
                break;
            
            case 5:
                killList(list);
                restoreListFromFile(list);
                break;
            
            case 6:
                killList(list);
                break;

            case 7: 
                cout << "Exit. Have a nice day:)";
                break;

            default:
                cout << "You've entered wrong number. Please try again." << endl;
        }

    } while (choice != 7);


    return 0;
}