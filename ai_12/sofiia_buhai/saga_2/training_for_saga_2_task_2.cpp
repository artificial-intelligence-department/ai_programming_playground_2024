#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};


struct LinkedList{
    Node* head;
    int size;
    LinkedList(){
        head = nullptr;
        size = 0;
    }

//створення однонаправленого списку структур
    void create(){
        int array[] = {1, 3, 45, -5, 93, 55, 33, 4};
        int s = *(&array+1)-array;
        size = s;
        for(int i=0; i<s; i++){
            Node* newNode = new Node(array[i]);
            if(head == NULL){
                head = newNode;
            }else{
                Node* tmp = head;
                while(tmp->next != nullptr){
                    tmp = tmp->next;
                }
                tmp->next = newNode;
            }
        }
    }

//додавання нового вузла списку в кінець списку
    void add_in_end(int value){
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        Node* temp = new Node(value);
        current->next = temp;
        size++;
    }

//додавання нового вузла списку на початок списку
    void add_in_beginning(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

//додавання нового вузла списку в середині списку
    void add_in_middle(int value, int position){
        Node* newNode = new Node(value);
        Node* current = head;
        for(int i=0; i<position-1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

//виведення значень з структури у списку
    void print(){
        Node* current = head;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

//сортування однонаправленого списку методом бульбашки
    void sort_bubble(){
        for(int i=0; i<size-1; i++){
            Node* current = head;
            bool swapped = 0;
            for(int j=0; j<size-i-1; j++){
                if(current->data > current->next->data){
                    int tmp = current->next->data;
                    current->next->data = current->data;
                    current->data = tmp;
                    swapped=1;
                }
                current = current->next;
            }
            if(!swapped){
                break;
            }
        }
    }
};

//всі такі самі дії з двонаправленим списком

struct NodeB{
    int data;
    NodeB* next;
    NodeB*  prev;
    NodeB(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


struct LinkedListBoth{
    NodeB* head;
    NodeB* tail;
    int size;
    LinkedListBoth(){
        head = nullptr;
        tail=nullptr;
        size = 0;
    }

//створення двонаправленого списку структур
    void create(){
        int array[] = {25, 77, 0, -6, 8, 12, -54, 22, 85};
        int s = *(&array+1)-array;
        size = s;
        for(int i=0; i<s; i++){
            NodeB* newNode = new NodeB(array[i]);
            if(head == NULL){
                newNode->prev = nullptr;
                head = newNode;
                head->next = tail;
            }else{
                NodeB* tmp = head;
                while(tmp->next != nullptr){
                    tmp = tmp->next;
                }
                tmp->next = newNode;
                newNode->prev = tmp;
                tail=newNode;
            }
        }
    }

//додавання нового вузла списку в кінець списку
    void add_in_end(int value){
        NodeB* current = tail;
        NodeB* temp = new NodeB(value);
        current->next = temp;
        temp->prev = current;
        tail=temp;
        size++;
    }

//додавання нового вузла списку на початок списку
    void add_in_beginning(int value){
        NodeB* newNode = new NodeB(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
    }

//додавання нового вузла списку в середині списку
    void add_in_middle(int value, int position){
        NodeB* newNode = new NodeB(value);
        NodeB* current = head;
        for(int i=0; i<position-1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
        size++;
    }

//виведення значень з структури у списку
    void print(){
        NodeB* current = head;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

//сортування однонаправленого списку методом бульбашки
    void sort_bubble(){
        for(int i=0; i<size-1; i++){
            NodeB* current = head;
            bool swapped = 0;
            for(int j=0; j<size-i-1; j++){
                if(current->data > current->next->data){
                    int tmp = current->next->data;
                    current->next->data = current->data;
                    current->data = tmp;
                    swapped=1;
                }
                current = current->next;
            }
            if(!swapped){
                break;
            }
        }
    }

    //виведення значень у двонаправленому списку  з ліва на право і з права на ліво
    void print_reverse(){
        NodeB* current = tail;
        while(current){
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }
};




int main(){
    LinkedList list;
    list.create();
    list.print();
    list.add_in_end(6);
    list.add_in_beginning(0);
    list.add_in_middle(12, 5);
    list.print();
    list.sort_bubble();
    list.print();
    LinkedListBoth list_both;
    list_both.create();
    list_both.print();
    list_both.add_in_end(100);
    list_both.add_in_middle(36, 4);
    list_both.add_in_beginning(4);
    list_both.print();
    list_both.sort_bubble();
    list_both.print();
    list_both.print_reverse();
    return 0;
}