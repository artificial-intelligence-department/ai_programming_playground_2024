#include <algorithm>
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* prev;
    Node* next;

    Node(int key) : key(key), next(nullptr), prev(nullptr) {}
};

void forward_traversal(Node* node1){
    Node* current = node1;
    while(current){
        cout << current -> key << " ";   // forward
        current = current -> next;
    }
    cout << endl;
}

void back_traversal(Node* node3){
    Node* current = node3;
    while(current){                   // back
        cout << current -> key << " ";
        current = current -> prev;
    }
    cout << endl;
}

Node* insert_at_the_end(Node* node3, int key){
    Node* new_node = new Node(key);
    node3 -> next = new_node;
    new_node -> prev = node3;          // insert at the end

    if(node3){
        node3 = new_node;
    }
    return node3;
}

Node* insert_at_the_position(Node* node1, int position, int new_key){

    Node* new_node = new Node(new_key);
    if(position == 1){
        new_node -> next = node1;         // insert at the position
        if(node1){
            node1 -> prev = new_node;
        }

        node1 = new_node;
        return node1;
    }

    Node* current = node1;

    for(int i = 1; i < position - 1 && current; ++i){
        current = current -> next;            
        }
        if(current == NULL){
            cout << "POsition is out of bounds " << endl;
            delete new_node;
            return node1;
    }
    new_node -> prev = current;
    new_node -> next = current -> next;
    current -> next = new_node;

    if(new_node -> next){
        new_node -> next -> prev = new_node;
    }
    return node1;
}

int findLength(Node* node1){                          // length
    int count = 0;                                         
    for(Node* current = node1; current; current = current -> next){
        count++;
    }
    return count;
}

int main(){

    Node* node1 = new Node(1);  // head
    Node* node2 = new Node(2); 
    Node* node3 = new Node(3); 

    node1 -> next = node2;
    node2 -> prev = node1;
    node2 -> next = node3;
    node3 -> prev = node2;

    cout << "Forward traversal: " << endl;
    forward_traversal(node1);
    cout << "********\n";
    cout << findLength(node1) << endl;

    insert_at_the_end(node3, 435);
    forward_traversal(node1);
    cout << findLength(node1) << endl;

    return 0;
}                   
/* in this file I tried much more different codes, but i deleted them 
every time i make them work, and after that i saw massege from Ivan Zagorodniy, 
that we should add all our codes to saga 2 */