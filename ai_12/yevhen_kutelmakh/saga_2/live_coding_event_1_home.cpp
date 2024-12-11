#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int variant = 41;

double function_1() {
    cout << "Enter 2 float numbers: ";
    float a, b;
    cin >> a >> b;
    cout << "Enter 3 int numbers: ";
    int c, d, e;
    cin >> c >> d >> e;
    cout << "Enter 1 double number: ";
    double f;
    cin >> f;
    double arr[6] = {a, b, c, d, e, f};
    sort(arr, arr+6);
    cout << "Smaller 3 nums: " << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    cout << "Bigger 3 nums: " << arr[3] << " " << arr[4] << " " << arr[5] << "\n";
    double sum_l = arr[0]+arr[1]+arr[2];
    double sum_b = arr[3]+arr[4]+arr[5];
    double sum;
    if(sum_b > sum_l*4) 
        sum = sum_b + sum_l;
    else if(sum_b > sum_l*3 && sum_l != 0.0) 
        sum = sum_b / sum_l;
    else if(sum_b > sum_l*2)
        sum = sum_b * sum_l;
    sum /= 41;
    cout << "Function_1 returns us " << sum << "\n";
    return sum;
}

double** function_2(double &x) {
    double** matrix = new double*[5];
    for(int i = 0; i < 5; i++) {
        matrix[i] = new double[5];
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }
    {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matrix[i][j] = (matrix[i][j]+variant+j-i)*(rand()%100);
            }
        }
    }
    cout << "We get this matrix:\n";
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return matrix;
}

double* function_3(double **array) {
    double* arr1 = new double[5];
    for(int i = 0; i < 5; i++) {
        arr1[i] = array[0][i];
        for(int j = 0; j < 5; j++) {
            if(array[j][i] < arr1[i])
                arr1[i] = array[j][i];
        }
    }
    double* help = new double[5];
    double* arr2 = new double[5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            help[j] = array[j][i];
        }
        sort(help, help+5);
        arr2[i] = help[0];
    }

    for(int i = 0; i < 5; i++) {
        if(arr1[i] != arr2[i]){
            cout << "Function_3 doesn`t work properly!";
            exit(0);
        }
    }
    cout << "All good in function_3\n";
    delete[] help;
    delete[] arr2;
    return arr1;
}

struct Node{
    double money;
    string name;
    string lastName;
    Node* next;
    Node* prev;
    Node(double num, string s, string str) : money(num), name(s), lastName(str) {}
};

class DLinkedList {
    Node *head;
    Node *tail;
    int size;
public:
    DLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void pushBack(double num, string s, string str) {
        if(head == nullptr) {
            head = new Node(num, s, str);
            tail = head;
        } else {
            Node *newNode = new Node(num, s, str);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode; 
        }
        size++;
    }

    void print() {
        Node* cur = head;
        if(size==0) cout << "The list is empty\n";
        while(cur != nullptr) {
            cout << "Student " << cur->name << " " << cur->lastName << " has " << cur->money << " hrn.\n";
            cur = cur->next;
        }
    }

    Node* getTail() {
        return tail;
    }

    Node* getHead() {
        return head;
    }
};

string getName() {
    string name = "";
    int len = rand()%7 + 3;
    for(int i = 0; i < len; i++) {
        name += rand()%25 + 'a';
    }
    return name;
}

DLinkedList function_4(double *array) {
    sort(array, array+5);
    DLinkedList list;
    list.pushBack(array[4], getName(), getName());
    for(int i = 0; i < 5; i++) {
        if(i==4)
            list.pushBack(array[i]+array[0], getName(), getName());
        else
            list.pushBack(array[i]+array[i+1], getName(), getName());
    }
    list.pushBack(array[0], getName(), getName());
    list.print();
    return list;
}

void help_for_function_5(Node *cur) {
    if(cur == nullptr) return;
    ofstream file("Saga.csv", ios::app);
    if(!file.is_open()) {
        cerr << "Couldn`t open a file!";
        exit(0);
    }
    file << cur->name << "," << cur->lastName << "," << cur->money << "\n";
    file.close();
    help_for_function_5(cur->prev);
}

void help_for_function_5(Node *cur, char c) {
    ofstream file("Saga.csv", ios::app);
    if(!file.is_open()) {
        cerr << "Couldn`t open a file!";
        exit(0);
    }
    do {
        file << cur->name << "," << cur->lastName << "," << cur->money << "\n";
        cur = cur->next;
    } while(cur != nullptr);
}

void function_5(DLinkedList list) {
    ofstream file("Saga.csv");
    if(!file.is_open()) {
        cerr << "Couldn`t open a file!";
        exit(0);
    }
    file.close();
    if(variant%2 == 0){
        Node* node = list.getTail();
        help_for_function_5(node);
    }
    else {
        Node* node = list.getHead();
        help_for_function_5(node, 'c');
    }
}

void function_6() {
    ifstream file("Saga.csv");
    if(!file.is_open()) {
        cerr << "Couldn`t open a file!";
        exit(0);
    }
    cout << "File contains:\n";
    cout << setw(13) << "Name" << setw(13) << "Last name" << setw(13) << "Money\n";
    string line;
    string word = "";
    while(getline(file, line)) {
        for(int i = 0; i < line.size(); i++) {
            if(line[i]==',') {
                cout << setw(13) << word;
                word = "";
            } else if(i == line.size()-1) {
                word += line[i];
                cout << setw(13) << word << "\n";
                word = "";
            }
            else word += line[i];
        }
    } 
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double x = function_1();
    double **tower = function_2(x);
    double *array = function_3(tower);
    DLinkedList list = function_4(array);
    function_5(list);
    function_6();
    return 0;
}       