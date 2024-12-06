#include <iostream>
#include <cstdio>
#include <cstring>

struct Node{
    char *str;
    Node *next_el;
    Node *prev;
};



void createList(Node*& head, Node*& tail, int n){
    if(head == nullptr){
        std::cout << "Your list is empty"<< std::endl;
}

tail = nullptr;
std::cout << "Enter 1 element: ";
char *text = new char[50];
std::cin.ignore();

fgets(text, 50, stdin);
text[strcspn(text, "\n")] = '\0';

head = new Node {text, nullptr};
Node* current = head;
char *loop;
for(int i = 0;i < n-1; ++i){
    std::cout << "Enter " << i + 2 << " element: ";
    loop = new char[50];
    fgets(loop, 50, stdin);
    loop[strcspn(loop, "\n")] = '\0';
    
    current->next_el = new Node {new char[strlen(loop) + 1], nullptr}; 
    strcpy(current->next_el->str, loop);
    current->next_el->prev = current;
    current = current->next_el;
}

tail = current;
}


void printList(Node *head){

Node *current = head;
if(current == nullptr){
    std::cout << "Your list is empty. ";
    return ;
}

while(current != nullptr){
    fputs(current->str, stdout);
    std::cout << ' ';
    current = current->next_el;
}
    return;
}


void func1(Node*& head, Node*& tail) {
    char temp[50];
    std::cout << "\nEnter an element you want to delete: ";
    fgets(temp, 50, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    Node* current = head;
    int k;
    std::cout << "K = ";
    std::cin >> k;
    std::cin.ignore();

    char *loop;
    bool found = false;

    while (current != nullptr) {
        if (strcmp(current->str, temp) == 0) {
            found = true;

            Node* nextNode = current->next_el;
            Node* previousNode = current->prev;
            for (int i = 0; i < k; ++i) {
                std::cout << "Enter " << i + 1 << " element: ";
                loop = new char[50];
                fgets(loop, 50, stdin);
                loop[strcspn(loop, "\n")] = '\0';

                Node* newNode = new Node {new char[strlen(loop) + 1], nullptr, previousNode};
                strcpy(newNode->str, loop);


                if (previousNode != nullptr) {
                    previousNode->next_el = newNode;
                } else {
                    head = newNode;
                }
                previousNode = newNode;
            }

            if (previousNode != nullptr) {
                previousNode->next_el = current->next_el;
            }
            if (nextNode != nullptr) {
                nextNode->prev = previousNode;
            }

            if (current == head) {
                head = current->next_el;
            }
            if (current == tail) {
                tail = previousNode;
            }

            delete[] current->str;
            delete current;
            break;
        }
        current = current->next_el;
    }

    if (!found) {
        std::cout << "Element not found!" << std::endl;
    }

    printList(head);
}








int main(){

Node* head = nullptr;   
std::cout << "How many elements you want your list to have: ";
int n;
std::cin >> n;
Node* tail = nullptr;

createList(head,tail ,n);
printList(head);
func1(head, tail);


    return 0;
}





