#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

const int variant = 41;

struct Student {
    string name;
    string lastName;
    double money;

    Student* next;
    Student* prev;
    Student(int val) {
        money = val;
        name = randomName();
        lastName = randomName();
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    Student* head;
    int size;
public:

    DoublyLinkedList() {
            size = 0;
            head = nullptr;
        }

    void pushBack(int value) {
        Student* newNode = new Student(value);
        if(head == nullptr)
            head = newNode;
        else {
            Student* curr = head;
            while(curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
        size++;
    }

    Student* getHead() {
        return head;
    }

    void print() {
        if(head == nullptr)
            cout << "The list is empty";
        else {
            Student* curr = head;
            while(curr != nullptr) {
                cout << curr->money << " ";
                curr = curr->next;
            }
        } 
        cout << endl;
    }
};

string randomName() {
    string name = "        ";
    int len = name.size();
    for(int i = 0; i < len; i++) {
        name[i] = rand()%25 + 'a';
    }
}

double function_1() {
    cout << "Enter 2 real numbers: ";
    float a, b;
    cin >> a >> b;
    cout << "Enter 3 integers: ";
    int c, d, e;
    cin >> c >> d >> e;
    cout << "Enter real number(with presicion): ";
    double f;
    cin >> f;
    int arr[6] = {a, b, c, d, e, f};
    sort(arr, arr+6);
    cout << "Three lesser numbers are: " << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    cout << "Three bigger numbers are: " << arr[3] << " " << arr[4] << " " << arr[5] << "\n";
    double bigger = arr[3] + arr[4] + arr[5];
    double smaller = arr[0] + arr[1] + arr[2];
    double x;
    if(bigger > smaller * 2) x = bigger*smaller;
    if(bigger > smaller * 3) {
        if(smaller == 0) {
            cout << "The sum of smaller = 0, so we cannot divide!\n";
        } else 
            x = bigger/smaller;
    }
    if(bigger > smaller * 4) x = bigger+smaller;
    x = x/variant;
    cout << "In the first task we got - " << x << "\n";
    return x;
}

auto function_2(double &num) {
    double **arr = new double*[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = new double[5];
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            arr[i][j] = num;
    }
    {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++)
                arr[i][j] = (num+variant+j-i)*(rand()%100);
        }   
    }
    cout << "Our matrix looks like: \n";
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return arr;
}

double findMin(double array[]) {
    double num = array[0];
    for(int i = 0; i < 5; i++) {
        if(array[i] < num) num = array[i];
    }
    return num;
}

auto function_3(double **array) {
    double *arr1 = new double[5];
    for(int i = 0; i < 5; i++) {
        arr1[i] = findMin(array[i]);
    }
    double arr2[5];
    for(int i = 0; i < 5; i++) {
        sort(array[i], array[i] + 5);
        arr2[i] = array[i][0];
    }
    bool match = true;
    for(int i = 0; i < 5; i++) {
        if(arr1[i] != arr2[i]) {
            cout << "The elements do not match!\n";
            match = false;
            break;
        } 
    }
    if(match)
        cout << "Elements match!\n";
    return arr1;
}

auto function_4(double *array) {
    DoublyLinkedList list;
    sort(array, array + 5);
    list.pushBack(array[0]);
    for(int i = 0; i < 5; i++) {
        if(i == 4) list.pushBack(array[i] + array[0]);
        else list.pushBack(array[i] + array[i+1]);
    }
    list.pushBack(array[4]);
    list.print();
    return list;
}
//variant Парний 
void help_for_function_5(DoublyLinkedList list) {
    ofstream file("Saga_1");
}
//variant Непарний
void help_for_function_5(DoublyLinkedList list, char c) {
    ofstream file("Saga_1");
    Student *cur = list.getHead();
    while(cur->next != nullptr) {
        //sfile << 
    }
}

void function_5(DoublyLinkedList list) {
    if(variant%2==0) {
        help_for_function_5(list);
    } else {
        help_for_function_5(list, 'c');
    }
}

void function_6() {
    ifstream file("Saga_1");
    if(!file.is_open()) {
        cerr << "File is not opened!\n";
        exit(1);
    }
    string buffer;
    cout << "Our file looks like:\n";
    while(getline(file, buffer)) {
        cout << buffer << "\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double x = function_1();
    double **tower = function_2(x);
    double *array = function_3(tower);
    DoublyLinkedList list = function_4(array);
    function_5(list);
}