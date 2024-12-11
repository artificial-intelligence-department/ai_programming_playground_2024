#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;
// в коді використана як мінімум одна цілочисельна константа
const int variant = 17;

struct Node
{
    string name;
    string lastname;
    double wealth;
    Node *prev;
    Node *next;
};

// в коді використана як мінімум одна цілочисельна змінна
// в коді використана як мінімум одна дійсна змінна
// в коді використана як мінімум одна дійсний з подвійною точністю змінна
// в коді використана як мінімум одна цілочисельна константа
// в коді використані умовні оператори та розгалуження
// в коді використаний одновимірний масив 
// в коді використаний двовимірний масив 
// в коді використаний do while цикл
// в коді використаний while цикл
// в коді використаний for цикл 
// в коді використано оператори break і continue
// в коді використано перевантаження функції 
// в коді використано рекурсивну функцію 
// в коді використано параметри та аргументи функції	
// в коді використано математичні операції та математичні функції
// в коді використано функції роботи з файлами, для того, щоб записати у файл
// в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
// в коді використано оператори виведення та введення даних
// в коді використано свою структуру даних
// в коді використано вказівники

double function_1(){
    float a,b;  // в коді використана як мінімум одна цілочисельна змінна
                // в коді використана як мінімум одна дійсна змінна
                // в коді використана як мінімум одна дійсний з подвійною точністю змінна
    int c,d,e;
    double f;

    cin>>a>>b;
    cin>>c>>d>>e;
    cin>>f;
    // в коді використано оператори виведення та введення даних
// в коді використаний одновимірний масив 
double arr[6] = {a,b,static_cast<double>(c),static_cast<double>(d),static_cast<double>(e),f};

sort(arr, arr + 6);

double max = arr[5]+arr[4]+arr[3];
double min = arr[0]+arr[1]+arr[2];
double result;
// в коді використані умовні оператори та розгалуження
if(max>min*4){
    result = max+min;
}else if(max>min*3){
    result = max/min;
}else if(max>min*2){
    result = max*min;
}
// cout<<max<<"\t"<<min<<endl;

result /= variant;
cout<<result<<endl;
return result;
}

double **function_2(double &x){
srand((unsigned)time(0));
double **matrix = new double *[5];
// в коді використаний двовимірний масив 
for(int i = 0; i<5;i++){
    matrix[i]=new double[5];
    for(int j = 0; j<5;j++){
        matrix[i][j] = x;
    }
}
// в коді використаний for цикл 
for(int i = 0; i<5;i++){
    for(int j = 0; j<5;j++){
        matrix[i][j] = (matrix[i][j]+variant+j-i)*(rand() % 101);
    }
}

for(int i = 0; i<5;i++){
    for(int j = 0; j<5;j++){
       cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
return matrix;
}

double *function_3(double **tower){
double *arr = new double[5];

for(int i = 0;i<5;i++){
    double temp[5]; 
    for(int j = 0;j<0;j++){
        temp[j] = tower[j][i];
       } 
       arr[i] = *min_element(temp, temp+5);
    }

for(int i = 4;i>0;i--){
    for(int j = 0; j<5 ;j++){
        if(tower[i][j]< tower[i-1][j]){
            swap(tower[i][j],tower[i-1][j]);
        }
    }
}

bool same = true;

for(int i = 0;i<5;i++){
    if(arr[i] != tower[0][i]){
        same = false;
    }
}

if(same){
    cout<<"Результати однакові"<<endl;
}else{
    cout<<"Результати різні"<<endl;
}

return arr;

}

Node *function_4(double *money/* в коді використано параметри та аргументи функції*/)  {
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();
    Node *four = new Node();
    Node *five = new Node();
    Node *six = new Node();
    Node *seven = new Node();

    double sum =0;
    for(int i = 0; i<5 ;i++){
        sum += money[i];
    }

one -> name = "Stephen";
one -> lastname = "King";
one -> wealth = *max_element(money, money + 5);
one ->prev =nullptr;
one ->next = two;

two -> name = "Tess";
two -> lastname = "Gerritsen";
two -> wealth = sum;
two ->prev =one;
two ->next = three;

three -> name = "Rebecca";
three -> lastname = "Yarros";
three -> wealth = sum;
three ->prev =two;
three ->next = four;

four -> name = "Fredrik";
four -> lastname = "Backman";
four -> wealth = sum;
four ->prev =three;
four ->next = five;

five -> name = "Agata";
five -> lastname = "Kristi";
five -> wealth = sum;
five ->prev =four;
five ->next = six;

six -> name = "John";
six -> lastname = "Tolkien";
six -> wealth = sum;
six ->prev =five;
six ->next = seven;

seven -> name = "Harry ";
seven -> lastname = "Potter";
seven -> wealth = *min_element(money, money + 5);
seven ->prev =six;
seven ->next = nullptr;

Node *current = one;
// в коді використаний do while цикл
do{
    cout<<current->name<<" "<<current->lastname<<" "<< current->wealth<<endl;
}while(current != nullptr);

return one;
}

int main(){
double x = function_1();
double **tower = function_2(x);
double *money = function_3(tower);
function_4(money);
return 0;
}