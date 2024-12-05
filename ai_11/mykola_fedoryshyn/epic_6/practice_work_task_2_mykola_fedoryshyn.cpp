#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;

    Node (int val) : value(val), next(nullptr) {}; 
};

bool compareList(Node* head1, Node* head2){
    while (head1 != nullptr && head2 != nullptr){
        if (head1->value != head2->value){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next; 
    }

    return head1 == nullptr && head2 == nullptr;    
}

void printList(Node* head){
    Node* current = head;

    while (current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

Node* createList(){
    int n, value;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    if (n <= 0){
        return nullptr;
    }

    cout << "Enter the value for Node 1: ";
    cin >> value;
    Node* head = new Node(value);
    Node* temp = head;

    for (int i = 2; i <= n; i++){
        cout << "Enter the value for Node " << i << ": ";
        cin >> value;
        temp->next = new Node(value);
        temp = temp->next;
    }   

    return head;
}

int main (){

    Node* list1 = createList();
    Node* list2 = createList();
    
    cout << "First list: ";
    printList(list1);

    cout << "Second list: ";
    printList(list2);

    if (compareList(list1, list2) == true){
        cout << "List 1 is equal list 2.";
    } else {
        cout << "List 1 isn't equal list 2.";
    }

    return 0;
}