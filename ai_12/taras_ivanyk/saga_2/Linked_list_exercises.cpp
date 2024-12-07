#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

void print_node(Node* head){
    Node* current = head;

    while(current){
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}

Node* create_node_at_the_end(Node* head, int new_data){
    Node* new_node = new Node(new_data);
    if(!head){
        return new_node;
    }

    Node* current = head;
    while (current->next) { 
        current = current->next;
    }

    current -> next = new_node;
    return head;
}

Node* create_node_at_start(Node* head, int new_data){
    Node* new_node = new Node(new_data);
    new_node -> next = head;
    return new_node;
}

Node* create_node_in_the_position(Node* head, int new_data, int position){
    Node* new_node = new Node(new_data);
    
    if(position == 0 || !head){
        new_node -> next = head;
        return new_node;
    }

    Node* current = head;
    int index = 0;
    while(current && index < position - 1){
        current = current -> next;
        index++;
    }

    if(current){
        new_node -> next = current -> next;
        current -> next = new_node;
    } else{
        cout << "Error, you enter a wrong position, try again. \n";
        delete new_node;
        return head;
    }

    return head;
}

void delete_elements(Node* &head, int position){
   
    if(position < 0 || !head){
        cout << "You enter the wrong position or the list is empty! \n";
        return;
    } 

    if(position == 0){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    Node* current = head;
    int index = 0;

    while(current -> next && index < position - 1){
        current =current -> next;
        index++;
    }

    if(!current -> next){
        cout << "You enter the wrong position \n";
        return;
    }
    Node* temp = current -> next;
    current -> next = current -> next -> next;
    delete temp;
}

void buble_sort(Node* head){

    if(!head){
        cout << "List is empty! \n";
        return;
    }

    bool swapped;
    do{
        swapped = false;
        Node* current = head;

        while(current && current -> next){
            if( (current->data) > (current->next->data) ){ 
                int temp = current->data;
                current->data = current->next->data;    
                current->next->data = temp;
                swapped = true;
            }
            current = current -> next;
        } 
    } while(swapped);
}

Node* merge_sorted(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data <= head2->data) {
        head1->next = merge_sorted(head1->next, head2);
        return head1;
    } else {
        head2->next = merge_sorted(head1, head2->next);
        return head2;
    }
}

struct Cyclist{
    string first_name;
    string second_name;
    int age;
    int FTP; // functional threshold power
    Cyclist* next;

    Cyclist(string fName, string lName, int a, int ftp){
        first_name = fName;
        second_name = lName;
        age = a;
        FTP = ftp;
        next = nullptr;
    }
};

void append_cyclist(Cyclist* &head, string first_name, string second_name, int age, int FTP){
    Cyclist* newCyclist = new Cyclist(first_name, second_name, age, FTP);

    if(!head){
        head = newCyclist;
        return;
    }

    Cyclist* current = head;
    while(current -> next){
        current = current -> next;
    }
    current -> next = newCyclist;
}

void print_all_cyclists(Cyclist* &head_c){
    if(!head_c){
        cout << "The list is empty! \n";
        return;
    }

    Cyclist* current = head_c;
    while(current){
        cout << endl <<"Name: " << current -> first_name << ", surname: " << current -> second_name;
        cout << ", age: " << current -> age << ", FTP = " << current -> FTP << endl;
        current = current -> next;
    }
}


int main(){

    Node* head = new Node(1);
    head = create_node_at_the_end(head, 2);
    head = create_node_at_the_end(head, 3);
    head = create_node_at_the_end(head, 4);

    cout << "Our start list: \n";
    print_node(head);

    cout << endl << "New list with new element at the end \n";
    create_node_at_the_end(head, 5);
    print_node(head);

    cout << endl << "New list with new element at the start \n";
    head = create_node_at_start(head, 0);
    print_node(head);

    int position, number;
    cout << endl << "Enter position and number at your new list: \n";
    cin >> position >> number;
    cout << endl << "New list with element at the position " << position << "\n";
    create_node_in_the_position(head, number, position);
    print_node(head);

    cout << "********************************" << endl;


// Buble sort
    cout << endl << "New list before sorting: \n";
    
    delete_elements(head, 6);
    delete_elements(head, 5);
    delete_elements(head, 4);
    delete_elements(head, 3);
    delete_elements(head, 2);
    delete_elements(head, 1);
    delete_elements(head, 0);

    head = create_node_at_start(head, 6);
    head = create_node_at_start(head, 2);
    head = create_node_at_start(head, 234);
    head = create_node_at_start(head, 5);
    head = create_node_at_start(head, 4);

    print_node(head);
    cout << endl;

    buble_sort(head);
    cout << "New list after buble sort: \n";
    print_node(head);

// Merge sort
    cout << "********************************" << endl;
    cout << endl << "New list before sorting: \n";

    delete_elements(head, 4);
    delete_elements(head, 3);
    delete_elements(head, 2);
    delete_elements(head, 1);
    delete_elements(head, 0);

    head = create_node_at_start(head, 278);
    head = create_node_at_start(head, 124);
    head = create_node_at_start(head, 55);
    head = create_node_at_start(head, 1);
    head = create_node_at_start(head, 32);

    print_node(head);
    cout << endl;

    buble_sort(head);
    cout << "New list after merge sort: \n";
    print_node(head);

    cout << "********************************" << endl;

// some actions with structure:

    Cyclist* head_c = nullptr;

    append_cyclist(head_c, "Taras", "Ivanyk", 17, 360);
    append_cyclist(head_c, "Yurij", "Ivanyk", 40, 330);
    append_cyclist(head_c, "Tadej", "Pogacar", 24, 450);
    
    print_all_cyclists(head_c);

    return 0;
}