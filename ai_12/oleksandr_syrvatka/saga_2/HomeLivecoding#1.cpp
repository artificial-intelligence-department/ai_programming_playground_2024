#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

const int var = 50;

struct Student {
    string name;
    string surname;
    double money;

  Student(string n, string s, double m): name(n), surname(s), money(m){}  
};

struct Node{
    Student student;
    Node* prev;
    Node* next;

    Node(Student& s): student(s), prev(nullptr), next(nullptr){}
};

struct DoublyLinkedList{
    Node* head;
    Node* tail;

    DoublyLinkedList(): head(nullptr), tail(nullptr){}

    void addstudent(Student& student){
    Node* newNode = new Node(student);
    if(tail == nullptr){
        head = tail = newNode; 
    }else{
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    };
};

double function_1(){
    float a, b;
    cin >> a >> b;
    int c, d, e;
    cin >> c >> d >> e;
    double f;
    cin >> f;

    double arr[6]{(double)a, (double)b, (double)c, (double)d, (double)e, f};
    sort(arr, arr + 6); 
    double maxsum = arr [5]+ arr[4]+ arr[3];
    double minsum = arr [0]+ arr[1]+ arr[2];
    double x = 0;

    if (maxsum > minsum*4){
        x = maxsum + minsum;
    }else if (maxsum > minsum * 3){
        x = maxsum / minsum;
    }else {
        x = maxsum * minsum;
    }
    x /=var;
    cout << x << endl;
    return x;
}

double** function_2(double& x){
    srand(time(0));
    double** matrix = new double*[5];
    for (int i = 0 ; i< 5 ; i++){
        matrix[i]= new double [5]{x,x,x,x,x};
    }
    for (int i = 0; i < 5 ;i++){
        for (int j = 0 ; j < 5 ; j++){
            matrix[i][j] = ( matrix[i][j]+ var + j - i) * (rand()%100 + 1);
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return matrix;
}

double* function_3(double** tower){
    double* minvalues = new double[5];
    for(int j = 0; j < 5; j++){
        minvalues[j] = tower[0][j];
        for (int i = 0; i <5; i++){
            if(minvalues[j]<tower[i][j]){
                minvalues[j]=tower[i][j];
            }
        }
    }
    double column [5];
    double* minvalues2 = new double[5];
    for (int j = 0 ; j< 5; j++){
        for(int i = 0; i<5; i++){
            column[i]= tower [i][j];
        }
        sort (column, column+5);
        minvalues2[j] = column[0];
    }
    if(minvalues == minvalues2){
        cout << "Значення у обох пошуках спіпадають";
    }

    return minvalues;
}

DoublyLinkedList function_4(double* minvalues){
    DoublyLinkedList List;
    sort(minvalues, minvalues +5);
    double min = minvalues[0];
    double max = minvalues[4];
    double sum = 0.0;
    string Names[7] = {"Name1","Name2","Name3","Name4","Name5","Name6","Name7"};
    string Surnames[7] = {"Surname1","Surname2","Surname3","Surname4","Surname5","Surname6","Surname7"};

    for(int i = 0; i < 5; i++ ){
        sum +=minvalues[i];
    }
    for (int i = 0; i < 7; i++){
        double money = 0.0;
        if (i == 0){
            money = max;
        }else if(i == 6){
            money = min;
        }else{
            money = sum;
        }
        Student student (Names[i],Surnames[i], money);
        List.addstudent(student);
    }
    cout << "Список студентів: " << endl;
    Node* current = List.head;
    while(current!=nullptr){
        cout << current -> student.name <<" " << current -> student.surname <<" " << current -> student.money << endl;
        current = current -> next;
    }
    return List;
}

//Для парного
void help_for_function_5(ofstream& file, DoublyLinkedList& List, Node*node){
    if(node == nullptr){
        return;
    }
    help_for_function_5(file, List, node->next);
    file << node -> student.name << " " << node -> student.surname << " "<< node -> student.money << endl;
}

//Для непарного
void help_for_function_5(ofstream& file, DoublyLinkedList& List){
    Node* current = List.head;
    while(current != nullptr){
        file << current -> student.name << " " << current -> student.surname << " "<< current -> student.money << endl;
        current = current -> next;
    }
}    

void function_5(DoublyLinkedList& List){
    ofstream file("students.txt");
    if(var %2 == 0){
        help_for_function_5(file,List,List.head);
    }else {
        help_for_function_5(file,List);
    }
    file.close();
}


void function_6(){
    ifstream file("students.txt");
    if (!file.is_open()){
        cerr << "Помилка" << endl;
        return;
    }
    string Line;
    cout << "Вміст файла: " << endl;
    while(getline(file,Line)){
        cout << Line << endl;
    }
    file.close();

}

int main(){
    double x = function_1();
    
    double** tower = function_2(x);

    double* minvalues = function_3(tower);

    DoublyLinkedList List = function_4(minvalues);

    function_5(List);

    function_6();

    return 0;
}