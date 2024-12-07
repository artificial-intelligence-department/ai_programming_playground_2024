#include <iostream>

using namespace std;

    struct Node {
        int data;
        Node* next;
    } ;



void push_back(Node*& head,int value) {
    
    if (head == nullptr) {
        head = new Node{value, nullptr};
       
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
            
        }
        current->next = new Node {value, nullptr};
       
    }
}

void push_front(Node*& head,int value) {
    
    if (head == nullptr) {
        head = new Node{value, nullptr};
    } else {
        Node* newNode = new Node {value, head};
        head = newNode;
    }
}    

void pop_back(Node*& head) {
    
    if (head == nullptr) {
        cout << "Empty!" << endl;
        return;
       
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* previous = head;
        Node* current = head->next;
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        delete current;
        previous->next = nullptr;
    }
}

void pop_front(Node*& head) {
    
    if (head == nullptr) {
        cout << "Empty!" << endl;
        return;
       
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* newHead = head->next;
        delete head;
        head = newHead;
    }
}


void remove(Node*& head,int value) {

        Node* previous = nullptr;
        Node* current = head;//0 елементів нічо не спрацює

        while (current != nullptr) {
            if (current->data == value) {
                if (previous == nullptr) {
                    head = head->next;//перевіряєм чи ми на голові візуалізую H  hшлях  шуканий елемент   h next   другий елемент 
                    //тому hшлях = h next
                } else {
                    previous->next = current->next;
                }
            delete current;
            return;
            }
        previous = current;
        current = current->next;
        }

    }

bool find(Node*& head,int value) {
    if (head == nullptr) {
        return false;
    }

    Node* current = head;

    while(current != nullptr) {
        if(current->data == value) {
            cout << "Found!" << endl;
            return true;
        }
        current = current->next;
    }
    return false;
}

int Size(Node* head) {
    int size = 0;
    Node* current = head;

    while(current != nullptr) {
        size++;
        current = current->next;
    }


    return size;

}

bool compare(Node* h1,Node* h2) {

    Node* current1 = h1;
    Node* current2 = h2;

    if(Size(h1) != Size(h2)) {
        cout << "Not the same(" << endl;
        return false;
    } else {
        if (h1 == nullptr && h2 == nullptr) {//нема елементів
                cout << "Not the same(";
                return false;
    }

    while(current1 != nullptr && current2 != nullptr) {
        if(current1->data != current2->data) {
            cout <<"Not the same(" << endl;
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    cout << "Yeeeess" << endl;
    return true;
    }

}


Node* reverse(Node* head) {
    Node* prev = nullptr;   // Вказівник на попередній вузол
    Node* current = head;   // Вказівник на поточний вузол
    Node* next = nullptr;   // Вказівник на наступний вузол

    while (current != nullptr) {
        next = current->next; // Зберігаємо наступний вузол
        current->next = prev; // Міняємо напрямок зв'язку
        prev = current;       // Зсуваємо prev на поточний вузол
        current = next;       // Переходимо до наступного вузла
    }

    return prev;
}


Node* add(Node* h1, Node* h2) {
    Node* result_head = nullptr;  // Результуючий список
    Node* tail = nullptr;    // Вказівник на останній вузол результатуючого списку
    int carry = 0;           // Перенос у старший розряд

    while (h1 != nullptr || h2 != nullptr || carry > 0) {
        int sum = carry;  // Почати з переносу

        if (h1 != nullptr) {
            sum += h1->data;// carry + h1
            h1 = h1->next;
        }

        if (h2 != nullptr) {
            sum += h2->data; // carry + h1 + h2
            h2 = h2->next;
        }

        carry = sum / 10;  // Оновити перенос і залишити на наступну ітерацію
        Node* newNode = new Node{sum % 10, nullptr};  // Створюємо новий вузол

        if (result_head == nullptr) {  // Якщо список порожній, новий вузол стає головою
            result_head = newNode;
            tail = newNode;
        } else {  // Інакше додаємо новий вузол до кінця
            tail->next = newNode;
            tail = newNode;  // Оновлюємо хвіст
        }
    }

    return result_head;
}
void print(Node* head) {
    Node* current = head;
    while (current != nullptr) {
    cout << "data " << current->data << endl;
    cout << "next " << current->next << endl;
    current = current->next;
    }
}
int main(){
    int value;

    Node* h1 = nullptr;
    Node* h2 = nullptr;

    push_back(h1,6);
    push_back(h1,8);

    push_back(h2,6);
    push_back(h2,9); 

    cout << "Size h1: " << Size(h1) << endl;
    cout << "Size h2: " << Size(h2) << endl;
    
    cout << "Comparing: " << endl;
    
    compare(h1,h2);

    cout << "Print h1: " << endl;

    print(h1);

    cout << "Print h2: " << endl;

    print(h2);

    h1 = reverse(h1);
    cout << "Вивід реверсивної h1: " << endl;
    print(h1);
    cout << endl;
    h1 = reverse(h1);
    cout << "Реверснули назад: " << endl;
    print(h1);

    Node* sum = add(h1, h2);

    cout << "Sum: " << endl;
    print(sum);

    cout << endl;

    print(h1);

    print(h2);

    return 0;
}