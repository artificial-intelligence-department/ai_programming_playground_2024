#include<bits/stdc++.h>
using namespace std;
const int varnum = 49;

struct Node{
    string firstName;
    string lastName;
    double balance;
    Node* prev;
    Node* next;
};

double findMin(const double arr[5]){
    double minVal = arr[0];
    for(int i = 0; i < 5; i++){
        if(arr[i] < minVal){
            minVal = arr[i];
        }
    }
    return minVal;
}
double function_1(){
    //input
    float a,b;
    int c, d, e;
    double f;
    cout << "Введіть два дійсні числа а і b ";
    cin >> a >> b;
    cout << "Введіть три цілі числа с, d і е ";
    cin >> c >> d >> e;
    cout << "Введіть дійсне число з подвійною точністю f ";
    cin >> f;
    double arr[] = {(double) a, (double) b, (double) c, (double) d, (double) e, f};
    //procesing
    //sort
    for(int i = 0; i < 5; i++){
        for(int j = i; j < 6; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    //output and find sumMax and Min
    double sumMin = 0;
    double sumMax = 0;
    double x = 0;
    cout << "Три найменші числа: ";
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
        sumMin += arr[i];
    }
    cout << endl;
    cout << "Три найбільші числа: ";
    for(int i = 3; i < 6; i++){
        cout << arr[i] << " ";
        sumMax += arr[i];
    }
    cout << endl;
    //find x
    if(sumMax > sumMin * 4){
        x = sumMax + sumMin;
    }
    else if(sumMax > sumMin * 3){
        x = sumMax / sumMin;
    }
    else if(sumMax > sumMin * 2){
        x = sumMax * sumMin;
    }
    else{
        cout << "Випадок не підпадає під жодну з умов";
        return 0.0;
    }
    x /= varnum;
    return x;
}

double** function_2(double *x){
    double** matrix = new double* [5];
    for(int i = 0 ; i < 5; i++){
        matrix[i] = new double [5];
    }
    //fill matrix x
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] = *x;
        }
    }
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] = matrix[i][j] + varnum + j - i * ((rand() % 101) + 1);
        }
    }
    //output matrix
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

double* function_3(double** tower){
    double* arr = new double[5];
    double min[5];
    //first way find min
    for(int i = 0; i < 5; i++){
        min[i] = tower[0][i];
        for(int j = 0; j < 5; j++){
            if(tower[j][i] < min[i]){
                min[i] = tower[j][i];
            }
        }
    }
    //second way find min
    double arr0[5], arr1[5], arr2[5], arr3[5], arr4[5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 0){
                arr0[j] = tower[j][i];
            }
            else if(i == 1){
                arr1[j] = tower[j][i];
            }
            else if(i == 2){
                arr2[j] = tower[j][i];
            }
            else if(i == 3){
                arr3[j] = tower[j][i];
            }
            else if(i == 4){
                arr4[j] = tower[j][i];
            }
        }
    }
    double min1[5];
    min1[0] = findMin(arr0);
    min1[1] = findMin(arr1);
    min1[2] = findMin(arr2);
    min1[3] = findMin(arr3);
    min1[4] = findMin(arr4);
    //compare
    bool equal = true;
    for(int i = 0; i < 5; i++){
        if(min[i] != min1[i]){
            equal = false;
            cerr << "Мінімальні значення знайдені двома способами не співпадають, програма продовжить своє виконання не правильно" << endl;
            break;
        }
    }
    if(equal){
        cout << "Мінімальні значення знайдені двома способами співпадають" << endl;
    }
    for(int i = 0; i < 5; i++){
        arr[i] = min[i];
    }
    return arr;
}

Node* createNode(string firstName, string lastName, double balance){
    Node* newnode = new Node;
    newnode -> firstName = firstName;
    newnode -> lastName = lastName;
    newnode -> balance = balance;
    newnode -> prev = nullptr;
    newnode -> next = nullptr;
    return newnode;
}

Node* function_4(double* arr){
    Node* head = nullptr;
    Node* tail = nullptr;
    string firstNames[] = {"Maksym", "Nazar", "Roman", "Danylo", "Andriy", "Robert", "Misha"};
    string lastNames[] = {"Perkhun", "Romanov", "Antonov", "Rebrov", "Neroba", "Kryvonis", "Naluvayko"};
    double maxBalance = arr[0];
    double minBalance = arr[0];
    for(int i =0; i < 5; i++){
        if(arr[i] > maxBalance){
            maxBalance = arr[i];
        }
        if(arr[i] < minBalance){
            minBalance = arr[i];
        }
    }
    double sum = 0;
    for(int i = 0; i < 5; i++){
        sum += arr[i];
    }
    string curFirstName;
    string curLastName;
    double curBalance;
    for(int i = 0; i < 7; i++){
        curFirstName = firstNames[i];
        curLastName = lastNames[i];
        if(i == 0){
            curBalance = maxBalance;
        }
        else if (i == 6){
            curBalance = minBalance;
        }
        else{
            curBalance = sum;
        }
        Node* newnode = createNode(curFirstName, curLastName, curBalance);
        if (!head){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
        }
    }
    Node* current = head;
    while(current){
        cout << "Ім'я: " << current->firstName << "\n";
        cout << "Прізвище: " << current->lastName << "\n";
        cout << "Баланс: " << current->balance << "\n";
        cout << "-----------------------------" << endl;
        current = current->next;
    }
    return head;
}

void help_for_function_5(FILE* fileStream, Node* current){
    fputs((current -> firstName).c_str(), fileStream);
    fputs(" ", fileStream);
    fputs((current -> lastName).c_str(), fileStream);
    fputs(" ", fileStream);
    fputs((to_string(current -> balance)).c_str(), fileStream);
    fputs("\n", fileStream);
}

void function_5(char* fileName, Node* head){
    Node* current = head;
    FILE* fileStream = fopen(fileName, "w");
    if(!fileStream){
        cerr << "Нe вдалося відкрити файл";
        return;
    }
    while(current){
        help_for_function_5(fileStream, current);
        current = current -> next;
    }
    fclose(fileStream);
    fileStream = fopen(fileName, "r");
    if(!fileStream){
        cerr << "Нe вдалося відкрити файл";
        return;
    }
    char str[50];
    while(fgets(str, 50, fileStream)){
        cout << str << endl;
    }
    fclose(fileStream);
}
int main() {
    double x;
    x = function_1();
    double** tower = function_2(&x);
    double* func_3Res = function_3(tower);
    Node* head = function_4(func_3Res);
    char* fileName = "Students.txt";
    function_5(fileName, head);
    return 0;
}