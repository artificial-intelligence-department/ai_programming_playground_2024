#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

void print_forward(Node* node1) {
    Node* curr = node1;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void print_backward(Node* node1) {
    Node* curr = node1;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

Node* add_to_the_end(Node* node1, int data) {
    Node* new_node = new Node(data);

    if (!node1) {
        return new_node;
    }

    Node* curr = node1;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;

    return node1;
}

Node* add_to_the_start(Node* node1, int data) {
    Node* new_node = new Node(data);

    if (!node1) {
        return new_node;
    }

    new_node->next = node1;
    node1->prev = new_node;

    return new_node;
}

Node* new_node_at_the_position(Node* node1, int position, int data) {
    Node* new_node = new Node(data);

    if (position == 1) {
        new_node->next = node1;
        if (node1) {
            node1->prev = new_node;
        }
        return new_node;  
    }

    Node* curr = node1;
    int index = 1;
    while (curr && index < position - 1) {
        curr = curr->next;
        index++;
    }

    if (!curr) {
        cout << "Error, you entered the wrong position \n";
        delete new_node;
        return node1;
    }

    new_node->prev = curr;
    new_node->next = curr->next;
    if (curr->next) {
        curr->next->prev = new_node;
    }
    curr->next = new_node;

    return node1;
}

void buble_sort(Node*& head) {
    if (!head) {
        cout << "Error: list is empty! \n";
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

int main() {
    Node* node1 = new Node(55);        // create double_linked_list
    Node* node2 = new Node(345);
    Node* node3 = new Node(32);
    Node* node4 = new Node(12);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;

    // print forward:
    cout << endl << "********************************\n" << "             PRINT FORWARD: \n \n";

    cout << "Create a double-linked list: (print forward)\n";
    print_forward(node1);

    cout << endl << "Insert the element at the end: (print forward)\n";
    node1 = add_to_the_end(node1, 8);
    print_forward(node1);

    cout << endl << "Insert the element at the start: (print forward)\n";
    node1 = add_to_the_start(node1, 657);
    print_forward(node1);

    int position, num;
    cout << endl << "Enter position where you want to insert an element and value of this element: " << endl;
    cin >> position >> num;

    cout << endl << "Insert the element at the position " << position << ": " << endl;
    node1 = new_node_at_the_position(node1, position, num);
    print_forward(node1);

    cout << endl << "List before sorting: (print forward)\n";
    print_forward(node1);

    cout << endl << "List after bubble sort: (print forward)\n";
    buble_sort(node1);
    print_forward(node1);

    // print backward: (so, when we will insert an element to position, we must to write opposite position, because list is gone backward)
    cout << endl << "********************************\n" << "             PRINT BACKWARD: \n \n";

    cout << "Create a double-linked list: (print backward)\n";
    print_backward(node4);

       cout << endl << "Insert the element at the end: (print backward)\n";
    node1 = add_to_the_end(node1, 8);
    print_backward(node4);

    cout << endl << "Insert the element at the start: (print backward)\n";
    node1 = add_to_the_start(node1, 657);
    print_backward(node4);

    int position_2, num_2;
    cout << endl << "Enter position where you want to insert an element and value of this element: " << endl;
    cin >> position_2 >> num_2;

    cout << endl << "Insert the element at the position " << position_2 << ": " << endl;
    node1 = new_node_at_the_position(node1, position_2, num_2);
    print_backward(node4);

    cout << endl << "List before sorting: (print backward)\n";
    print_backward(node4);

    cout << endl << "List after bubble sort: (print backward)\n";
    buble_sort(node1);
    print_backward(node4);

    return 0;
}

