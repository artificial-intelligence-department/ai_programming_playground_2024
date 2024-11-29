#include <iostream>
using namespace std;

//Structure for an element of the list
struct Node {
    int data;
    Node* next;
    //Constructor
    Node(int val) : data(val), next(nullptr) {}
};

//Function to display a list
void PrintList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//Function to insert elements at a specified index
void insert(Node*& head, int index, int listSize, int values[]) {
    //Invalid index given
    if (index < 0 || index > listSize) {
        return;
    }

    Node* newNode = nullptr;
    Node* current = head;
    
    //If inserting at the beginning, create a new head node
    if (index == 0) {
        for (int i = 0; i < listSize; i++) {
            newNode = new Node(values[i]);
            newNode->next = head;
            head = newNode;
        }
        return;
    }
    
    //Find node at the given index
    for (int i = 0; i < index - 1; i++) {
        if (current != nullptr) {
            current = current->next;
        }
    }
    
    //Insert new nodes
    for (int i = 0; i < listSize; i++) {
        newNode = new Node(values[i]);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode;
    }
}

//Function to reverse the list
Node* reverse(Node* head) {
    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    //Swap each two nearby elements
    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

//Practical task #2: compare lists
bool compare(Node* h1, Node* h2) {
    /*Take each individual element and compare to 
    the element on the same position on the other list*/
    while (h1 != nullptr && h2 != nullptr){
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next; 
        h2 = h2->next; 
    }
    //Check if each list run out of elements 
   return h1 == nullptr && h2 == nullptr;
}

//Practical task #3: sum numbers
Node* add(Node* n1, Node* n2) {
    // Reverse both input lists first
    n1 = reverse(n1);
    n2 = reverse(n2);

    // Create a new list for the sum
    Node* temp_head = new Node(0);
    Node* current_head = temp_head;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;
        
        // Add the digits from both lists, if present
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }
        
        // Carry for the next place
        carry = sum / 10;
        
        // Add the current digit to the result list
        current_head->next = new Node(sum % 10);
        current_head = current_head->next;
    }

    // Reverse the result list to maintain the reversed order
    Node* result = reverse(temp_head->next);
    return result;
}

int main() {
    // First programme: reverse the list
    Node* head = nullptr;
    int new_elements[] = {8,5,3,2,1,1};
    int new_elements_size = sizeof(new_elements) / sizeof(new_elements[0]);
    insert(head, 0, new_elements_size, new_elements);

    cout << "Original list: ";
    PrintList(head);

    head = reverse(head);
    cout << "Reversed list: ";
    PrintList(head);

    // Second programme: compare lists
    Node* head1 = nullptr;
    int new_elements_head1[] = {-47,34,22};
    int new_elements_size_head1 = sizeof(new_elements_head1) / sizeof(new_elements_head1[0]);
    insert(head1, 0, new_elements_size_head1, new_elements_head1);

    Node* head2 = nullptr;
    int new_elements_head2[] = {-47,34,22};
    int new_elements_size_head2 = sizeof(new_elements_head2) / sizeof(new_elements_head2[0]);
    insert(head2, 0, new_elements_size_head2, new_elements_head2);

    Node* head3 = nullptr;
    int new_elements_head3[] = {-36,4,-47};
    int new_elements_size_head3 = sizeof(new_elements_head3) / sizeof(new_elements_head3[0]);
    insert(head3, 0, new_elements_size_head3, new_elements_head3);

    //With identical lists
    cout << "List 1: ";
    PrintList(head1);

    cout << "List 2: ";
    PrintList(head2);

    if (compare(head1, head2)){
        cout << "The lists are equal" << endl;
    } 
    else {
        cout << "The lists are not equal" << endl;
    }

    //With different lists
    cout << "List 1: ";
    PrintList(head1);

    cout << "List 3: ";
    PrintList(head3);

    if (compare(head1, head3)){
        cout << "The lists are equal" << endl;
    } 
    else {
        cout << "The lists are not equal" << endl;
    }

    // Third programme: sum numbers
    // 207
    Node* number_1 = nullptr;
    int new_elements_number_1[] = {2, 0, 7};
    int new_elements_size_number_1 = sizeof(new_elements_number_1) / sizeof(new_elements_number_1[0]);
    insert(number_1, 0, new_elements_size_number_1, new_elements_number_1);

    // 664
    Node* number_2 = nullptr;
    int new_elements_number_2[] = {6,6,4};
    int new_elements_size_number_2 = sizeof(new_elements_number_2) / sizeof(new_elements_number_2[0]);
    insert(number_2, 0, new_elements_size_number_2, new_elements_number_2);

    cout << "Number 1: ";
    PrintList(number_1);
    
    cout << "Number 2: ";
    PrintList(number_2);

    Node* result = add(number_1, number_2);

    cout << "Sum: ";
    PrintList(result);
    return 0;
}
