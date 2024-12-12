#include <iostream>




struct Node {
    int data;
    Node* next;

    Node(int data, Node* next = nullptr): data(data), next(next) {}
    

};











class SingleList {
private:
    Node* head;
    
public:
    SingleList() : head(nullptr) {}

    ~SingleList() {
         clear();
        
    }


 void start(){
    clear();
    head = new Node(38, nullptr);
    head->next = new Node(54, nullptr);
    head->next->next = new Node(6, nullptr);
    
}

    void addInEnd(int value){
    Node* newNode =  new Node(value);
    if(head == nullptr){
        head = newNode;

    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;

    }
    temp->next = newNode;
    return;
    
}

void addInStart(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    
}



    void printNode(){
    Node* temp = head;
    while(temp){
         std::cout << temp->data << " ";
        temp = temp->next;
       

    }
}


 void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
    }

    Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next; // Зберігаємо наступний вузол
        current->next = prev; // Змінюємо напрямок зв'язку
        prev = current;       // Переміщуємо `prev` вперед
        current = next;       // Переміщуємо `current` вперед
    }
    return prev; // Новий головний вузол
}

    void bubbleSort(){
bool swapped; 
    do {
        swapped = false;
        Node* current = head;

        while (current->next) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data); 
                swapped = true; 
            }
            current = current->next; 
        }
    } while (swapped);
        
    }


};


struct coble {
    int data;
    coble* next;
    coble* prev;

    coble(int data, coble* next = nullptr, coble* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

class DoubleList {
private:
    coble* head;
    coble* tail;

public:
    DoubleList() : head(nullptr), tail(nullptr) {}

    ~DoubleList() {
        clear();
    }

    void start() {
        clear();
        head = new coble(38);
        head->next = new coble(54, nullptr, head);
        head->next->next = new coble(6, nullptr, head->next);
        tail = head->next->next;
    }

    void addInEnd(int value) {
        coble* newCoble = new coble(value);
        if (!head) {
            head = tail = newCoble;
            return;
        }
        tail->next = newCoble;
        newCoble->prev = tail;
        tail = newCoble;
    }

    void addInStart(int value) {
        coble* newCoble = new coble(value, head);
        if (head) {
            head->prev = newCoble;
        }
        head = newCoble;
        if (!tail) {
            tail = head;
        }
    }

    void printNode() {
        coble* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        while (head) {
            coble* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void bubbleSort() {
        if (!head || !head->next) return; // Перевірка: список порожній або має 1 елемент

        bool swapped;
        do {
            swapped = false;
            coble* current = head;

            while (current->next) {
                if (current->data > current->next->data) {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};






int main(){
       
    
    SingleList testLIst;
    testLIst.start(); 

    testLIst.addInEnd(20);
    testLIst.printNode();
    
    std::cout << std::endl;
    testLIst.start();

    testLIst.addInStart(25);
    testLIst.printNode();

    std::cout << std::endl;
    testLIst.start();

    testLIst.bubbleSort();
    testLIst.printNode();
    std::cout << std::endl;

    DoubleList testList;

    testList.start();
    testList.addInEnd(20);
    testList.printNode();

    std::cout << std::endl;
    testList.start();

    testList.addInStart(25);
    testList.printNode();

    std::cout << std::endl;
    testList.start();

    testList.bubbleSort();
    testList.printNode();

    return 0;
    
    


    return 0;
}