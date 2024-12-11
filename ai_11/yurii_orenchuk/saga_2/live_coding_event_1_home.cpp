#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

const int VAR = 19;

double function_1(){
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    double nums[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(nums, nums+6);

    double maxSum = nums[5] + nums[4] + nums[3];
    double minSum = nums[0] + nums[1] + nums[2];

    double res = 0;
    if(maxSum > minSum * 2){
        res = maxSum * minSum;
    } else if (maxSum > minSum * 3){
        res = maxSum / minSum;
    } else if (maxSum > minSum * 4){
        res = maxSum + minSum;
    }

    res /= VAR;
    cout << "Result of function 1: " << res;
    cout << endl;
    return res;
}

double** function_2(double &x){
    double** arr = new double*[5];
    for(int i = 0; i < 5; i++){
        arr[i] = new double[5];
        for(int j = 0; j < 5; j++){
            arr[i][j] = x;
        } 
    }

    srand(time(0));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int random = (rand() % 100 + 1);
            arr[i][j] = (arr[i][j] + VAR + j - i) * random;
            cout << arr[i][j] << " ";
        } 
        cout << endl;
    }

    return arr;
}

double* function_3(double** tower){
    double* arr = new double[5];
    double min1 = 1000, min2 = 1000;

    for(int j = 0; j < 5; j++){
        min1 = 1000;
        for(int i = 0; i < 5; i++){
            if(tower[i][j] < min1) min1 = tower[i][j];
        }
        arr[j] = min1;
    }

    return arr;
}

struct Node{
    string name;
    string surname;
    double money;

    Node* prev;
    Node* next;
    Node(string name, string surname, double money) : name(name), surname(surname), money(money), next(nullptr), prev(nullptr) {};
};

struct DBLinkedList {
    Node* head;
    Node* tail;
};

DBLinkedList function_4(double* arr){
    string names[7] = {"Angelo", "Josuke", "Joseph", "Giorno", "DIO", "Bruno", "Adam"};
    string surnames[7] = {"Sur1", "Sur2", "Sur3", "Sur4", "Sur5", "Sur6", "Sur7",};

    int random = rand() % 6;
    Node* head = new Node(names[random], surnames[random], *max_element(arr, arr+5));
    Node* curr = head;

    for(int i = 1; i < 6; i++){
        double sum = 0;
        for(int j = 0; j < i; j++){
            sum += arr[j];
        }
        random = rand() % 6;
        Node* NewNode = new Node(names[random], surnames[random], sum);
        curr->next = NewNode;
        NewNode->prev = curr;
        curr = NewNode;
    }

    random = rand() % 6;
    Node* tail = new Node(names[random], surnames[random], *min_element(arr, arr+5));
    curr->next = tail;
    tail->prev = curr;
    curr = head;

    do{
        cout << "Name: " << curr->name << endl;
        cout << "Surname: " << curr->surname << endl;
        cout << "Money: " << curr->money << endl;
        curr = curr->next;
    } while(curr);

    DBLinkedList res;
    res.head = head;
    res.tail = tail;
    return res;
}

void help_for_function_5(Node* head, ofstream& file){
    if(head == nullptr) return;

    file << "Student: " << head->name << " " << head->surname << " " << head->money << endl;
    help_for_function_5(head->next, file);
}

void help_for_function_5(Node* tail, ofstream& file, bool choice){
    while(tail){
        file << endl << "Student: " << tail->name << " " << tail->surname << " " << tail->money << endl;
        tail = tail->prev;
    }
}

void function_5(Node* head, Node* tail){
    ofstream file("students.txt");
    bool even = false;
    if(VAR % 2 == 0){
        even = true;
        help_for_function_5(tail, file, even);
    } else {
        help_for_function_5(head, file);
    }
    file.close();
}

void function_6(){
    ifstream file("students.txt");

    if(file.is_open()){
        cout << "\nFile contents: \n";
        string read;
        while(getline(file, read)){
            cout << read << endl;
        }
    } else cout << "File failed to open";

    file.close();
}   

int main(){
    double x = function_1();
    double** tower = function_2(x);
    double* arr = function_3(tower);

    DBLinkedList list = function_4(arr);
    Node* head = list.head;
    Node* tail = list.tail;

    function_5(head, tail);

    function_6();

    return 0;
}