#include <iostream> 
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int variant = 20;

int function_1(){
    float a, b;
    int c, d, e;
    double f;
    vector<double> arr;

    cout << "Введіть числа" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    arr.push_back(d);
    arr.push_back(e);
    arr.push_back(f);

    double maxSum, minSum;

    for(int i=0; i<6; i++){
        for(int k=0; k<5; k++){
            if(arr[k]>arr[k+1]){
                swap(arr[k], arr[k+1]);
            }
        }
    }

    for(int i=0; i<3; i++){
        minSum+=arr[i];
    }
    
    for(int i=3; i<6; i++){
        maxSum+=arr[i];
    }

    cout << "Сума найібльших: " << maxSum << endl;
    cout << "Сума найменших: " << minSum << endl;

    double x;
    
    if(maxSum>minSum*2){
        x = (maxSum*minSum) / variant;
    }
    else if(maxSum>minSum*3){
        x = (maxSum/minSum) / variant;
    }
    else if(maxSum>minSum*4){
        x = (maxSum+minSum) / variant;
    }

    return x;
}

vector<vector<double>> function_2(double &x){
    vector<vector<double>> matrix(5, vector<double>(5,x));

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matrix[i][j] = (x+variant+j-i)* (rand()%100+1);
        }
    }

    cout << "Елементи матриці: " << endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

vector<double> function_3(vector<vector<double>> &tower){
    vector<double> res;
    double min2;
    for(int i=0; i<5; i++){
        double min = tower[0][i];
        for(int j=0; j<5; j++){
            if(tower[j][i] < min){
                min = tower[j][i];
            }
        } 
        for(int j=0; j<5; j++){
            for(int k=0; k<4; k++){
                if(tower[k][i]> tower[k+1][i]){
                    swap(tower[k][i], tower[k+1][i]);
                }
            }
        }
        min2 = tower[0][i];
        if(min == min2){
            cout << "Результати співпадають" << endl;
        }
        res.push_back(min);
    }

    return res;
}

struct Node{
    string name;
    string surname;
    double balance;
    Node* prev;
    Node* next;

    Node(const string& n, const string& s, double b) : name(n), surname(s), balance(b), prev(nullptr), next(nullptr) {};
};




Node* function_4(vector<double> &money){
    vector<string> names = {"Світлана", "Андріана", "Марта", "Анастасія", "Юля", "Марія", "Соломія"};
    vector<string> surnames = {"a", "b", "c", "d", "e", "f", "g"};
    
    sort(money.begin(), money.end());


    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0; i<7; i++){
        string name = names[i];
        string surname = surnames[i];
        double balance;
        if(i==0){
            balance = money[4];
        }
        else if(i==6){
            balance = money[0];
        }
        else{
            balance = 0;
            for(int j=0; j<money.size(); j++){
                balance += money[j];
            }
        }
        Node* newNode = new Node(name, surname, balance);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } 
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; 
        }
    }
        Node* current = head;
        while(current){
            cout << current->name << " " << current->surname << " " << current->balance << endl;
            current = current->next;
        }

        return head;
}

void function_5(Node*& head){
    ofstream("file.txt");
}


int main(){
    double x = function_1();

    cout << "Значення з функції №1: " << x << endl;

    vector<vector<double>> tower = function_2(x);

    vector<double> minEls = function_3(tower);

    Node* head = function_4(minEls);

    return 0;




}