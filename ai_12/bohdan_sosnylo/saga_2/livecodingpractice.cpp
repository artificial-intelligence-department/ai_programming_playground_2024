#include <iostream>
using namespace std;

struct Node1 {
    int value;
    Node1 *next;
};

struct Node2 {
    int value;
    Node2 *next;
    Node2 *prev;
};

void insertAtStart(Node1 *&head, int val){
    Node1 *newElement = new Node1();
    newElement->value = val;
    newElement->next = head;
    head = newElement;
}

void insertAtStart2(Node2 *&head, Node2 *&tail, int val) {
    Node2 *newElement = new Node2();
    newElement->value = val;
    newElement->next = head;
    newElement->prev = nullptr;

    if (head == nullptr) {
        head = newElement;
        tail = head;
    } else {
        head->prev = newElement;
        head = newElement;
    }
}

void insertAtEnd(Node1 *head, int val) {
    Node1 *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node1 *newElement = new Node1();
    newElement->value = val;
    newElement->next = nullptr;
    current->next = newElement;
}

void insertAtEnd2(Node2 *&head, Node2 *&tail, int val) {
    Node2 *newElement = new Node2();
    newElement->value = val;
    newElement->next = nullptr;
    newElement->prev = tail;

    if (head == nullptr) {
        head = newElement;
        tail = newElement;
    } else {
        tail->next = newElement;
        tail = newElement;
    }
}

void insertAtPosition(Node1 *&head, int pos, int val) {
    if (pos == 0) {
        insertAtStart(head, val);
    } else {
        Node1 *current = head;
        while (current != nullptr && current->value != pos) {
            current = current->next;
        }
        if (current != nullptr) {
            Node1 *newElement = new Node1();
            newElement->value = val;
            newElement->next = current->next;
            current->next = newElement;
        }
    }
}

void insertAtPosition2(Node2 *&head, Node2 *&tail, int pos, int val) {
    if (pos == 0) {
        insertAtStart2(head, tail, val);
    } else {
        Node2 *current = head;
        while (current != nullptr && current->value != pos) {
            current = current->next;
        }
        if (current != nullptr) {
            Node2 *newElement = new Node2();
            newElement->value = val;
            newElement->next = current->next;
            newElement->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newElement;
            } else {
                tail = newElement;
            }
            current->next = newElement;
        } else {
            cout << "нема елемента" << endl;
        }
    }
}

void bubbleSort(Node1 *head) {
    bool swapped;
    do {
        swapped = false;
        Node1 *current = head;
        while (current->next != nullptr) {
            if (current->value > current->next->value) {
                swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void bubbleSort2(Node2 *head) {
    bool swapped;
    do {
        swapped = false;
        Node2 *current = head;
        while (current->next != nullptr) {
            if (current->value > current->next->value) {
                swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void selectionSort(Node1 *&head) {
    Node1 *placement = head;
    while (placement != nullptr) {
        Node1 *current = placement;
        Node1 *min = placement;
        while (current != nullptr) {
            if (current->value < min->value) {
                min = current;
            }
            current = current->next;
        }
        if (min != placement) {
            swap(placement->value, min->value);
        }
        placement = placement->next;
    }
}

void selectionSort2(Node2 *&head, Node2 *&tail) {
    Node2 *placement = head;
    Node2 *last = head;
    while (placement != nullptr) {
        Node2 *current = placement;
        Node2 *min = placement;
        while (current != nullptr) {
            if (current->value < min->value) {
                min = current;
            }
            current = current->next;
        }
        if (min != placement) {
            swap(min->value, placement->value);
        }
        last = placement;
        placement = placement->next;
    }
    tail = last;
}

void displayList(Node1 *head) {
    Node1 *current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
void displayList(Node1 *head, bool recursive) {
    if (recursive) {
        if (head != nullptr) {
            cout << head->value << " ";
            displayList(head->next, true);
        }
    } else {
        displayList(head);
    }
}


void displayList2(Node2 *head) {
    Node2 *current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void displayList2Reverse(Node2 *tail) {
    Node2 *current = tail;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}


int main(){

int matrix[5][5];
int matrix1[5][5];
int matrix2[5][5];
int res[5];

for(int i = 0; i<5;i++){
    for(int j = 0; j<5;j++){
        cin >> matrix[i][j];
    }
}
for(int j = 0; j<5;j++){ // min по стопвцях
    int min = matrix[0][j];
    for(int i = 0 ;i<5;i++){
        if(matrix[i][j] < min){
            min = matrix[i][j];
        }
    }
    res[j] = min;
}

for(int i = 0; i<5;i++){
   cout <<res[i] <<" ";
}
cout <<endl;

for(int i = 0; i<5;i++){
    for(int j = 0; j<5;j++){
        matrix1[i][j] = matrix[i][j];
    }
}

for (int i = 0; i < 5; i++) {     // max по рядках
    for (int k = 0; k < 4; k++) { 
        for (int j = 0; j < 4 - k; j++) { 
            if (matrix1[i][j] < matrix1[i][j + 1]) {
                swap(matrix1[i][j], matrix1[i][j + 1]); 
            }
        }
    }
    res[i] = matrix1[i][0]; 
}


for(int i = 0; i<5;i++){
   cout <<res[i] <<" ";
}
cout <<endl;
for(int i = 0; i<5;i++){
    for(int j = 0; j<5;j++){
        matrix2[i][j] = matrix[i][j];
    }
}
for(int i = 0; i<5;i++){
    for(int k = 0; k<4;k++){  // min по рядках
        for(int j = 0 ;j<5;j++){
            if(matrix2[i][j] > matrix2[i][j+1]){
                swap(matrix2[i][j],matrix2[i][j+1]);
            }
        } 
    }
    res[i] = matrix2[i][0]; 
    
}

for(int i = 0; i<5;i++){
   cout <<res[i] <<" ";
}
cout <<endl;
bool dir = true;
for(int j = 4; j>=0;j--){ // вивід зігзагом
    if(dir){
        for(int i = 4; i>=0; i--){
            cout << matrix[i][j]<<" ";
        }
        cout <<endl;
        dir = false;
    }
    else{
        for(int i = 0; i<5; i++){
            cout << matrix[i][j]<<" ";    
        }
        cout<<endl;
        dir = true;
    }
}

for(int i = 4; i>=0;i--){     //вивід знизу 
    for(int j = 4;j>=0;j--){
        cout << matrix[i][j] << " ";
    }
    cout<<endl;
}
cout <<endl;
int rotmat[5][5];
int matrix90[5][5];

for(int i = 0; i<5;i++){
    for(int j = 0;j<5;j++){
        rotmat[i][j] = matrix[j][i];
    }
}


for(int i = 0; i<5;i++){
    for(int j = 0;j<5;j++){
        matrix90[i][j] = rotmat[i][4-j];
    }
}

bool sym = true;
for(int i = 0; i<5;i++){
    for(int j = 0;j<5;j++){
        if(matrix[i][j] != matrix[j][i]){
            sym = false;
           
        }
    }
    if(!sym){
        break;
    }
}
int matrix65[6][5];
int matrix56[5][6] = {
{1,2,3,4,5,6},
{7,8,9,10,11,12},
{13,14,15,16,17,18},
{19,20,21,22,23,24},
{25,26,27,28,29,30} };

for(int i = 0; i<5;i++){
    for(int j = 0; j<6;j++){
        matrix65[j][i] = matrix56[i][j]; 
    }
}

for(int i = 0; i<6;i++){
    for(int j = 0; j<5;j++){
        cout <<matrix65[i][j]<<" ";
    }
    cout <<endl;
}

Node1 *head1 = nullptr; 
insertAtStart(head1, 3); 
insertAtStart(head1, 2); 
insertAtStart(head1, 1); 
insertAtEnd(head1, 4); 
insertAtEnd(head1, 5); 
insertAtPosition(head1, 3, 99); 
cout << "Однозв'язний список: "; 
displayList(head1); 
bubbleSort(head1);
cout << "Після сортування: "; 
displayList(head1);  
Node2 *head2 = nullptr; 
Node2 *tail2 = nullptr; 
insertAtStart2(head2, tail2, 3); 
insertAtStart2(head2, tail2, 2); 
insertAtStart2(head2, tail2, 1); 
insertAtEnd2(head2, tail2, 4); 
insertAtEnd2(head2, tail2, 5); 
insertAtPosition2(head2, tail2, 3, 99); 
cout << "Двозв'язний список: "; 
displayList2(head2); 
bubbleSort2(head2); 
cout << "Після сортування: "; 
displayList2(head2); 
cout << "Зворотний порядок: "; 
displayList2Reverse(tail2);

return 0;
}