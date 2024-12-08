#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int variant = 20; // цілочисельна константа

double function_1(){
    float a, b; // дійсна змінна
    int c, d, e; // цілочисельна змінна
    double f; // дійсна з подвійною точністю змінна

    cin >> a >> b >> c >> d >> e >> f; // використано оператори вводу
    // одновимірний масив
    double arr[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f}; 
    sort(arr, arr+6);

    double minSum = 0;
    double maxSum = 0;

    for(int i=0; i<3; i++){ // цикл for
        minSum+=arr[i];
    }

    for(int i=3; i<6; i++){
        maxSum+=arr[i];
    }

    double x;
    if(maxSum > minSum*4){ // умовні оператори
        x = maxSum + minSum;
    }
    else if(maxSum > minSum*3){
        x = maxSum / minSum;
    }
    else if(maxSum > minSum*2){
        x = maxSum*minSum;
    }

    return x;
}

double** function_2(double& x){
    double** matrix = new double*[5]; // двовимірний масив

    for(int i=0; i<5; i++){
        matrix[i] = new double[5];
        for (int j=0; j<5; j++){
            matrix[i][j] = x;
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matrix[i][j] = (matrix[i][j]+variant+j-i) * (rand()%100 + 1); // математичні операції
            cout << matrix[i][j] << " "; // використано оператор виведення
        }
        cout << endl;
    }

    return matrix;
}

double* function_3(double** matrix){
    double* arr = new double[5];
    double min2;
    for(int j=0; j<5; j++){
        double min = matrix[0][j]; //перший спосіб - лінійний пошук
        for(int i=0; i<5; i++){
            if(matrix[i][j] < min){ 
                min = matrix[i][j];
            }
        }

        for(int i=0; i<5; i++){
            for(int k=0; k<4; k++){ //другий спосіб - через сортування
                if(matrix[k][j]>matrix[k+1][j]){
                    swap(matrix[k][j], matrix[k+1][j]);
                }
            }
            min2 = matrix[0][j];
        }
        
        if(min==min2){
            cout << "Результати пошуку найменшого елементу співпадають: " << min << " " << min2 << endl;
            arr[j] = min;
        }
    }
    return arr;
}

struct Node{ // своя структура даних
    string name;
    string surname;
    double balance;
    Node* next; // використано вказівники
    Node* prev;
    Node (string nm, string srn, double bl) : name(nm), surname(srn), balance(bl), next(nullptr), prev(nullptr) {};
};

struct DoublyLinkedList{
    Node* head;
    Node* tail;
};


DoublyLinkedList function_4(double* arr){
    string names[7] = {"Ann", "Ashley", "Mary", "James", "Chris", "Sophie", "Adam"};
    string surnames[7] = {"A", "B", "C", "D", "E", "F", "G"};

    Node* head = new Node(names[0], surnames[0], *max_element(arr, arr+5));
    Node* current = head;

    for(int i=1; i<6; i++){
        double sum = 0;
        for(int k=0; k<i; k++){
            sum+=arr[k];
        }
        Node* newNode = new Node(names[i], surnames[i], sum);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    Node* tail = new Node(names[6], surnames[6], *min_element(arr, arr+5));

    current->next = tail;
    tail->prev = current;
    current = head;

    do{
        cout << current->name << " " << current->surname << " " << current->balance << endl;
        current = current->next;
    } while(current); // цикл do while
    
    DoublyLinkedList res;
    res.head = head;
    res.tail = tail;
    return res;
}

void help_for_function_5(Node* tail, ofstream& file){
    if(!tail){
        return;
    }
    file << tail->name << " " << tail->surname << " " << tail->balance << endl;
    help_for_function_5(tail->prev, file); //рекурсія
}

void help_for_function_5(Node* head, ofstream& file, int a){ // перевантаження функції
    while(head){ // цикл while
        file << head->name << " " << head->surname << " " << head->balance << endl;
        head = head->next;
    }
}

void function_5(Node* head, Node* tail){
    ofstream file("list.txt"); // функція роботи з файлом для запису
    if(variant%2 == 0){
        help_for_function_5(tail, file);
    }
    else{
        help_for_function_5(head, file, 2);
    }
    file.close();
}

void function_6(){
    ifstream file("list.txt"); // функція роботи з файлом для зчитування
    if(!file.is_open()){
        cout << "Файл не був створений" << endl;
        return;
    }

    cout << endl << "Вміст файлу:" << endl;
    string buff;
    while(getline(file,buff)){
        cout << buff << endl;
    }

    file.close();
}

int main(){
    double x = function_1();

    double** tower = function_2(x); 

    double* arr = function_3(tower);

    DoublyLinkedList list = function_4(arr);
    Node* head = list.head;
    Node* tail = list.tail;

    function_5(head, tail);
    
    function_6();

    return 0;
}