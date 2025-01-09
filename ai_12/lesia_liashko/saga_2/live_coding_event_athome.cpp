#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int variant = 44; //цілочисельна константа

double function_1 (){
    int c,d,e;  //цілочисельна змінна
    float a,b;  //дійсна змінна
    double f;   //дійсний з подвійною точністю змінна
   
    cout << "enter numbers 6:" << endl;
    cin >> a >> b >> c >> d >> e >> f; //оператори виведення та введення даних
    double numbers[6]={(double)a,(double)b,c,d,e,f}; //одновимірний масив

    double max1, max2, max3;
    max1=max2=max3=numbers[0];
    
    for (int i=0; i<6;i++){
        if (numbers[i]> max1){ //умовні оператори та розгалуження
            max3=max2;
            max2=max1;
            max1 = numbers[i];
        }  else if (numbers[i]> max2){
            max3= max2;
            max2= numbers[i];
        } else if (numbers[i]>max3){
            max3= numbers[i];
        }
    }
     double min1, min2, min3;
     min1=min2=min3=numbers[0];

     for (int i=0; i<6;i++){
        if (numbers[i] < min1){
            min3=min2;
            min2=min1;
            min1 = numbers[i];
        }  else if (numbers[i] < min2){
            min3= min2;
            min2= numbers[i];
        } else if (numbers[i]< min3){
            min3= numbers[i];
        }
    }
    
    double sumax = max1+max2+max3;
    double sumin = min1+min2+min3;
    double x;
    if (sumax > sumin*2){
         x = sumax*sumin; //математичні операції та математичні функції
    } else if (sumax > sumin*3 && sumin*2 < sumin*3){
         x = sumax/sumin;
    } else if(sumax > sumin*4 && sumin*3 < sumin*4){
         x = sumax+sumin;
    }
   x/=variant;
   return x;
}

double** function_2 (double& x){ //використано вказівники
    double** matrix = new double*[5];
    for (int i =0; i < 5; i++){
        matrix[i]= new double[5];
    }

    for (int i =0; i < 5; i++){
        for (int j =0; j < 5; j++){
            matrix[i][j]=x; //двовимірний масив
        }
    }

     for (int i =0; i < 5; i++){
        for (int j =0; j < 5; j++){
            matrix[i][j]=(matrix[i][j]+variant+j-i)*(rand()%100+1);
        }
    }
   
    for (int i =0; i < 5; i++){
        for (int j =0; j < 5; j++){
            cout << matrix[i][j] << " " << endl;
        }}
    return matrix;
}

double* function_3 (double** tower){
    double* rmatrix1 = new double[5];
    //1
    for (int j = 0; j < 5; j++) {
        int min = tower[0][j];
        for (int i = 1; i < 5; i++) {
            if (tower[i][j] < min) {
                min = tower[i][j];
            }
        }
        rmatrix1[j] = min; 
    }
       //2
     double* rmatrix2 = new double[5];
    for (int i = 0; i < 5; i++) {
        double min = tower[i][0]; 
        for (int j = 1; j < 5; j++) {
            if (tower[i][j] < min) {
                min = tower[i][j];
            }
        }
        rmatrix2[i] = min;
    }
     
     bool check = true;
    for (int i = 0; i < 5; i++) {
        if (rmatrix2[i] != rmatrix1[i]) {
            check = false;
            break; //оператори break
        }
    }
    
    if (!check) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }
    
    return rmatrix1;
}

struct Node { //свою структуру даних
    string name;
    string sname;
    double money;
    Node* next;
    Node* prev;

    Node (string name, string sname, double money): name(name), sname(sname), money(money), prev(nullptr), next(nullptr){}  
};

Node* function_4(double* minimum) {
    string names[] = {"Lesia", "Sasha", "Artem", "Petro", "Ivanka", "Nazar", "Dima"};
    string snames[] = {"Liashko", "Pavlov", "Vyshnevskyiy", "Shpak", "Antykalo", "Diachenko", "Los"};

    Node* head = new Node(names[0], snames[0], *max_element(minimum, minimum + 5));
    Node* current = head;

    for (int i = 1; i < 6; i++) { //for цикл 
        Node* newnode = new Node(names[i], snames[i], minimum[i - 1] + minimum[i % 5]);
        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }

    Node* last = new Node(names[6], snames[6], *min_element(minimum, minimum + 5));
    current->next = last;
    last->prev = current;

    current = head;
    while (current) { //while cycle
        cout << current->name << " " << current->sname << " " << current->money << endl;
        current = current->next;
    }

    return head;
}

void help_function_5 (Node* tail, ofstream& OutFile){ //recursion
    if (tail==nullptr){
        return;
    } else {
        OutFile << tail -> name << " " << tail -> sname << " " << tail-> money << endl;
        help_function_5 (tail -> prev, OutFile);
    }
   
}

void help_function_5 (Node* head, ofstream& OutFile, bool use){ //перевантаження функції
    Node* current=head;
    while (current){
     OutFile << current -> name << " " << current -> sname << " " << current-> money << endl;
     current = current -> next;
    }
}

void function_5 (Node* Students){
    ofstream OutFile("students.txt");  //функції роботи з файлами, для того, щоб записати у файл
    if(!OutFile.is_open()){
        cout << "error";
        return;
    } else {
        if (variant%2==0){
        Node* tail= Students;
        while (tail -> next !=nullptr){
            tail = tail -> next;
        }
        help_function_5 (tail, OutFile);
    } else {
        help_function_5 (Students, OutFile, true);
    }
    }}

void function_6 (){
    ifstream OutFile("students.txt"); //функції роботи з файлами, для того, щоб зчитати з файлу
    if (!OutFile.is_open()){
        cout << "error";
    } else {
        string data;
        while (getline(OutFile, data)){
            cout << data << endl;
        }

    }
}

void deletef(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main (){
double x = function_1();
double** tower = function_2(x);
double* minimum = function_3(tower);
for (int i =0; i < 5; i++){
    cout << minimum[i] << " "; //оператори виведення та введення даних
}
cout << endl;
Node* Students = function_4(minimum);
function_5(Students);
function_6();
deletef(Students);

for (int i = 0; i < 5; i++) {
    delete[] tower[i];
}
delete[] tower;
delete[] minimum;

return 0;
}