#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
    string name;
    string lastname;
    double wealth;
    Node* prev;
    Node* next;
};
double function_1()
{
    const int Var = 56;

    float a , b;
    cin >> a >> b;
    int c , d ,e;
    cin >> c >> d >> e;
    double f;
    cin >> f;

    double arr[] = {(double)a , (double)b , (double)c , (double)d , (double)e , (double)f};
    const int n = 6;

    sort(arr , arr + n , greater<double>());

    double bigSum = 0;
    double smallSum = 0;
    
    for(int i = 0;i < 6;i++)
    {
        bigSum += arr[i];
    }

     for(int i = 3;i < 6;i++)
    {
        smallSum += arr[i];
    }

    cout << "сума з нвйбільших: " << bigSum << endl;
    cout << "сума з найменших: " << smallSum << endl;

    double x = 0.0;

    if(bigSum > smallSum * 2)
    {
        x = bigSum * smallSum;
    }

    else if(bigSum > smallSum * 3)
    {
        x = bigSum / smallSum;
    }

    else if(bigSum > smallSum * 4)
    {
        x = bigSum + smallSum;
    }

    return x;
}


double** function_2(double &x)
{
    int Var = 56;
    double** arr = new double*[5];
    for(int i = 0;i < 5;i++)
    {
        arr[i] = new double [5];
        for(int j = 0;j < 5;j++)
        {
            arr[i][j] = x;
        }
    }

    srand(time(0));
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            int random = (rand() % 100 + 1);
            arr[i][j] = (arr[i][j] + Var + j - i) * random;
            
            cout << arr[i][j] << " " << endl;
        }
    }
    return arr;
}

double* function_3(double** tower)
{
    double* arr = new double[5];
    double min1 = 1000 , min2 = 1000;
    for(int j = 0;j < 5;j++)
    {
        min1 = 1000;
        for(int i = 0;i < 5;i++)
        {
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
    Node(string name , string surname , double money) : name(name) , surname(surname) , money(money) , next(nullptr) , prev(nullptr){};
};

struct DBLinkedList {
    Node* head;
    Node* tail;
};

DBLinkedList function_4(double* arr){
    string names[7] = {"Broski" , "Bababoi" , "Vasya" , "Bodya" , "Bruno" , "Mango" , "Krico"};
    string surname[7] = {"sur1" , "sur2" , "sur3" , "sur4" , "sur4" , "sur5" , "sur6" , "sur7",}; 

    int random = rand() % 6; 
    Node* head = new
    Node(names[random] , surname[random] , *max_element(arr, arr = 5));
    Node* curr = head;

    for(int i = 1;i < 6;i++)
    {
        double sum = 0;
        for(int j = 1;j < i;j++){
            sum += arr[j];
        }
    }

    random = rand() % 6;
    Node* tail = new
    Node(names[random] , surname[random] , *min_element(arr, arr = 5));
    curr->next = tail; 
    tail->prev = curr;
    curr = head;

    do{
        cout << "Name: " << curr->name << endl;
        cout << "Surname: " << curr->surname << endl;
        cout << "Money: " << curr->money << endl;
        curr = curr->next;
    } while(curr);DBLinkedList

    DBLinhedlist res;
    res.head = head;
    res.tail = tail;
    return tail; 

}

void help_for_function_5(Node* head , ofstream& file) {

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

void function_6() 
    {
        ifstream file("students.txt")

        if(file.is_open()){
            cout << "\n File contents:\n";
            string read;
            while(getline(file,read)){

                cout << read << endl;
            } else cout << "File failed to open";
            
        }
        file.close();
    }

int main(){
    double x = function_1();
    double** tower = function_2(x);
    double* arr = function_3(tower);
    DBLinkedList list = function_4(arr);
    Node* head = list.head;
    Node* tail = list.tail;

    function_5(head.tail);

    function_6();

    return 0;
}