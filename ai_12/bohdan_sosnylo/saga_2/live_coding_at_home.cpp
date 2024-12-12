#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

double function_1(){
    float a,b;
    cin >>a>>b;
    int c,d,e;
    cin >>c>>d>>e;
    double f;
    cin >>f;

    double mas[] = {a,b,c,d,e,f};
    sort(mas,mas+6);

    double min = mas[0]+mas[1]+mas[2];
    double max = mas[3]+mas[4]+mas[5];

    double x;
    if(max>min*2){
        if(max>min*3){
            if(max>min*4){
                x = max + min;
            }
            else{
                x = max/min;
            }
        }
        else{
            x = max * min;

        }
    }
    x/=52;
    return x;

}

double** function_2(double &x){
    double** matrix = new double*[5];
    for(int i = 0;i < 5;i++){
        matrix[i] = new double[5];
    }

    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j<5; j++){
            matrix[i][j] = x;
        }
    }
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j<5; j++){
        matrix[i][j] = (matrix[i][j]+52+j-i)*(rand()%101);
        }
    }

    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j<5; j++){
            cout << matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return matrix;
}

double* function_3(double** matrix){
    double* mas1 = new double[5];
    double* mas2 = new double[5];

    for(int j = 0;j<5;j++){
        double min = matrix[0][j];
        for(int i = 0;i<5;i++){
            if(matrix[i][j]<min){
                min = matrix[i][j];
            }
        }
    mas1[j] = min;
    }

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5;j++){
            for(int k = 0; k<4;k++){
                if(matrix[i][j]>matrix[i+1][j]){
                    swap(matrix[i][j],matrix[i+1][j]);
                }
            }
        }
    }
    for(int i = 0; i<5; i++){
    mas2[i] = matrix[0][i];
    }
    bool equal = true;
    for(int i = 0; i<5;i++){
        if(mas1[i] != mas2[i]){
            equal = false;
            break;
        }
    }

    return mas1;
}

struct Node{

string name;
string surn;
double balance;
Node* next;
Node* prev;

Node(string n,string sname,double blnc){
    name = n;
    surn = sname;
    balance = blnc;
    next = nullptr;
    prev = nullptr;
}
};

Node* function_4(double* mas){
    Node* head = nullptr;
    Node* tail = nullptr;

    string fnames[] = {"Alina", "maria","sofia", "irina", "Oksana", "Ivan"};
    string snames[] = {"Malina", "zaba", "sofka", "svyryd","Kohuch","Zagorodniy"};

    double sum;
    for(int i = 0; i<5;i++){
        sum+=mas[i];
    }

    for(int i = 0; i<7;i++){
        double balance[7];
        if(i == 0){
            balance[0] = *max_element(mas,mas+5);
        }
        else if(i == 6){
            balance[6] = *min_element(mas,mas+5);
        }
        else{
            balance[i] = sum;
        }

        Node* newNode = new Node(fnames[i],snames[i],balance[i]);
        if(!head){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        }
        
Node* temp = head;
while(temp){
cout <<temp->name<<" "<<temp->surn<<" "<<temp->balance<<endl;
return head;
}

}

void help_for_function_5(ofstream &file, Node* node){
    if(node != nullptr){
        file << node->name << node->surn<<node->balance<<endl;
        help_for_function_5(file,node->prev);
    }
}
void help_for_function_5(ofstream &file, Node* node, bool nep){
    while(node != nullptr){
        file << node->name << node->surn<<node->balance<<endl;
        node = node->next;
    }
    
}

void function_5(Node* node){
    ofstream file("students.txt");
    int var = 52;
    if(file.is_open()){
        if(var%2 == 0){
            while(node->next != nullptr){
                node = node->next;
            }
            help_for_function_5(file,node);
        }
        else{
            help_for_function_5(file,node,true);
        }

    }
    else{
        cout << "не можу файл відкрити ";
    }
    
}

void function_6(){
    ifstream outf("student.txt");
    if(!outf.is_open()){
        cout <<"pomilka";
    }
    else{
        string data;
        while(getline(outf,data)){
            cout << data<<endl;
        }

    }
}


int main(){

srand(time(0));

double x = function_1();
double** tower = function_2(x);
double* mas = function_3(tower);

Node* head = function_4(mas);
function_5(head);
function_6();

return 0;
}