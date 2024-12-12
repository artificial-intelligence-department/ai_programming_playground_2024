#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string name;
    string surname;
    double money;
    Node* next;
    Node* prev;
};
Node* head = nullptr; 
void insert(Node*& head, const char* name, const char* surname, double money)
{
    // Create a new node with the given data.
    Node* newNode = new Node{name, surname, money};

    // Check if the doubly linked list is empty.
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node of the list.
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Update the next and previous pointers to insert the
    // new node at the end.
    temp->next = newNode;
    newNode->prev = temp;
}
const int var = 59;

double function_1() {
    double a = 0;
    double b = 0;
    int c,d,e;
    float f; 
    //cin >> a >> b >> c  >> d  >> e  >> f;
    //double arr[6]={a,b,c,d,e,f};
    double arr[6]={6,5,4,3,2,1};



int n = sizeof(arr) / sizeof(arr[0]);
sort(arr, arr+n);

    double summin = arr[0]+arr[1]+arr[2];
    double summax = arr[3]+arr[4]+arr[5];
    double x = 0;
if (summax > summin*2) {
    x = (summax*summin)/var;
} 
if (summax > summin*3) {
    x = (summax / summin)/var;
}
if (summax > summin*4) {
    x = (summax + summin)/var;
}

return x;
}

void function_2(double arr2[5][5], double& x) {
        srand(time(0));
    arr2[5][5] = {x};

    for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 5; j++) {
        arr2[i][j] = (arr2[i][j]+var+j-i)*(rand()%100)+1;
       }

    }

    for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 5; j++) {
        cout << arr2[i][j] << " ";
       }
       cout << endl;
    }

}

void function_3(double arik[5], double tower[5][5]) {

    for (int j = 0; j < 5; j++) {
        double min1 = tower[0][j];
        for (int i = 0; i < 5; i++) {
            if (tower[i][j] < min1) {
                min1 = tower[i][j];
            }
            arik[j] = min1;
        }// той просто передивляється
        min1 = 0;
    }

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                for (int i = 4; i > k; i--) {
                    if (tower[i][j] < tower[i -1][j]) {
                    int r = tower[i][j];
                    tower[i][j] = tower[i][j-1];
                    tower[i][j-1] = r;
                    }
                }//той вже міняє
            }
        }

        for (int i =0;i <5;i++) {
            if (arik[i] != tower[0][i]) {
                cout << " " << endl;
            }
        }
       sort(arik, arik+5);
}


Node* function_4(Node*& head, double arik[5]){
insert(head,"Max","Tool", arik[4]);
insert(head,"Igor","Python", arik[0]);
insert(head,"Angela","Paskal", arik[0] + arik[1]);
insert(head,"Donald","Trump", arik[0] + arik[1] + arik[2]);
insert(head,"Vova","Zelenskii", arik[0] + arik[1] + arik[2] + arik[3]);
insert(head,"Oleg","Plotnitskiy", arik[0] + arik[1] + arik[2] + arik[3] + arik[4]);
insert(head,"Dmytro","Basarab", arik[0]);

Node* current = head;

while (current != nullptr) {
    cout << current->name << endl;
    cout << current->surname << endl;
    cout << current->money << endl;
    current = current->next;
    cout << endl;
}

return head;
}

void function_5(Node* current,ofstream& file) {
    while (current != nullptr) {
    file << current->name << endl;
    file << current->surname << endl;
    file << current->money << endl;
    current = current->next;
    file << endl;
    }

}

void function_5(Node* head) {
    ofstream file;
    file.open("when.txt", ios::out | ios::app);
    function_5(head, file);
    file.close();
}



void function_6() {
    ifstream file;
    file.open("when.txt", ios::in);
    string s;

    while (getline(file, s))
        cout << s << endl;
    file.close();
}


int main() {

double x = function_1();
double arr2[5][5] = {0};
function_2(arr2,x);


    double tower[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; i < 5;j++)
        {
            tower[i][j] = arr2[i][j];
        }   
    }

double arik[5];


function_3(arik, tower);

head = function_4(head, arik);

function_5(head);

function_6();

return 0;
} 