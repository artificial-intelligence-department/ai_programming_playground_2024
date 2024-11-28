#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};



class LinkedList {

    public:
    Node* head;
    int size;
    LinkedList() {
        size = 0;
        head = nullptr;
    }



    void insertLL(int index, int listSize, int values[]) {
        if (index < 0 || index > size || listSize <= 0) {
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        for (int j = 0; j < listSize; j++) {
            Node* newNode = new Node(values[j]);
            if (current) {
                newNode->next = current;
            }
            current = newNode;
            size++;
        }
        head = current;
    }


};

// реверс списку
Node* reverse(Node* &head){
    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return prev;
}


// друк списку
void printList(Node* head) {
    Node* current = head;
    while(current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


// порівняння списків
bool compare(Node* h1,  Node* h2){
    Node* head1 = h1;
    Node* head2 = h2;
    while(head1 && head2) {
        if(head1->data == head2->data){
            head1 = head1->next;
            head2 = head2->next;
        } else {
            return false;
        }
    }
    if((head2==nullptr && head1!=nullptr) || (head2!=nullptr && head1==nullptr)){
        return false;
    }

    return true;
}


//створення нодів
void insertN(int index, int listSize, int values[], Node* &n) {
        Node* current = n;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        for (int j = 0; j < listSize; j++) {
            Node* newNode = new Node(values[j]);
            if (current) {
                newNode->next = current;
            }
            current = newNode;
        }
        n = current;
    }


// додавання
Node* add(Node* n1, int size1, Node* n2, int size2){
    Node* head1 = n1;
    Node* head2 = n2;
    Node* NEW = nullptr;
    int s1 = size1;
    int s2 = size2;
    int diff1 = s1-s2;
    int diff2 = s2-s1;
    int d=0;
    int size;
    if(s1>s2){
        size = s2;
    } else {
        size = s1;
    }
    for(int i = 0; i<size; i++){
        int value = (head1->data + head2->data)%10;
        int plus= (head1->data + head2->data)/10;
        Node* newNode = new Node(value);
        if(plus == 1){
            Node* newNode = new Node(value);
            d=1;
        } else {
            Node* newNode = new Node(value+1);
            d=0;
        }
        if (NEW) {
            newNode->next = NEW;
        }
        NEW = newNode;
        head1 = head1->next;
        head2 = head2->next;
    }
    if(diff1>0){
        for(int j=0; j<diff1; j++){
            int value = (head1->data+d)%10;
            int plus =(head1->data+d)/10;
            Node* newNode = new Node(value);
            if(plus==1){
                Node* newNode = new Node(value);
                d=1;
            } else {
                Node* newNode = new Node(value+d);
                d=0;
            }
            if (NEW) {
                newNode->next = NEW;
            }
            NEW = newNode;
            head1 = head1->next;
        }
    }
    if(diff2>0){
        for(int j=0; j<diff2; j++){
            int value = (head2->data+d)%10;
            int plus =(head2->data+d)/10;
            Node* newNode = new Node(value);
            if(plus==1){
                Node* newNode = new Node(value);
                d=1;
            } else {
                Node* newNode = new Node(value+d);
                d=0;
            }
            if (NEW) {
                newNode->next = NEW;
            }
            NEW = newNode;
            head2 = head2->next;
        }
    }
    if(d==1){
        Node* newNode = new Node(d);
        if (NEW) {
            newNode->next = NEW;
        }
        NEW = newNode;
    }
    printList(NEW);
    return NEW;
}




int main(){

    LinkedList list;
    LinkedList list2;
    Node* n1;
    Node* n2;
    list.size=4;
    list2.size=4;
    int node1[]={9, 7, 3, 2, 1};
    int size1 = 5;
    int size2 = 4;
    int node2[]={7, 3, 4, 1};
    int elements[] = {4, 8, 6, 11};
    int elements2[] = {4, 8, 6, 11};
    int elementsSize = sizeof(elements)/sizeof(elements[0]);
    int elementsSize2 = sizeof(elements2)/sizeof(elements2[0]);
    list.insertLL(0, elementsSize, elements);
    list2.insertLL(0, elementsSize2, elements2);

    printList(list.head);

    reverse(list.head);
    printList(list.head);
    reverse(list.head);

    std::cout << "Чи однаковими є списки 1 та 2 ? : " 
    << ( compare(list.head, list2.head) ? "Yes" : "No") 
    << "\n";

    insertN(0, size1, node1, n1);
    insertN(0, size2, node2, n2);

    add(n1, size1, n2, size2);

    return 0;
}