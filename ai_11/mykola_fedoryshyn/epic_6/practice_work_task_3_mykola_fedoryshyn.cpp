#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;

    Node (int val) : value(val), next(nullptr) {};
};

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

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* addAfterReverse(Node* n1, Node* n2) {
    Node* result = nullptr;  
    Node* tail = nullptr;    
    int carry = 0;           

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry; 

        if (n1 != nullptr) {
            sum += n1->value;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->value;
            n2 = n2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);
        
        if (result == nullptr) {
            result = newNode;
        } else {
            tail->next = newNode;
        }
        
        tail = newNode; 
    }

    return result; 
}

Node* add(Node* n1, Node* n2){

    n1 = reverse(n1);
    n2 = reverse(n2);
    
    Node* sum = addAfterReverse(n1, n2);

    return reverse(sum);
} 

int main (){

    Node* list1 = createList();
    printList(list1);
    
    Node* list2 = createList();
    printList(list2);

    Node* result = add(list1, list2);

    cout << "Sum: ";
    printList(result);

    return 0;

}