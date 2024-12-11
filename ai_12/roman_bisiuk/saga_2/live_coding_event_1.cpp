#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int variant = 30; // цілочисельна константа

struct Student{ //  свою структуру даних
    string name;
    string surname;
    float balance;
    Student* next;
    Student* prev;
};

float function_1(){
    float a, b; // дійсна змінна
    cout << "Enter 2 floats: "; // виведення та введення даних
    cin >> a >> b;
    int c, d, e; // цілочисельна змінна
    cout << "Etner 3 integers: ";
    cin >> c >> d >> e;
    double f; // дійсний з подвійною точністю змінна
    cout << "Enter 1 double: ";
    cin >> f;
    //одновимірний масив
    double arr[] = {static_cast<double>(a), static_cast<double>(b), static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(arr, arr + 6, greater<double>());
    cout << "Biggest numbers: ";
    for (int i = 0; i < 3; i++) //  for цикл
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Smallest numbers: ";
    for (int i = 3; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    double sum1 = arr[1] + arr[2] + arr[0];
    double sum2 = arr[3] + arr[4] + arr[5];
    double result;
    // умовні оператори та розгалуження
    if(sum1 > sum2*4){ 
        result = sum1 * sum2;
    }else if(sum1 > sum2*3){
        result = sum1/sum2;
    }else if(sum1 > sum2*2){
        result = sum1 + sum2;
    }

    float x = result / variant;
    cout << "x = " << x << endl;
    return x;
}

float** function_2(float& x){ // параметри та аргументи функції
    const int size = 5;
    float** arrMatrix = new float*[size];
    for (int i = 0; i < size; i++)
    {
        arrMatrix[i] = new float[size];
        for (int j = 0; j < size; j++)
        {
            arrMatrix[i][j] = x; //двовимірний масив
        }
    }

    srand(static_cast<unsigned>(time(0)));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            arrMatrix[i][j] = (arrMatrix[i][j] + variant + j - i) * (rand() % 100 + 1); // математичні операції та математичні функції
        }
    }
    cout << "Matrix: " << endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << arrMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return arrMatrix;
}

double *function_3(float **tower){ //використано вказівники
    double *array1 = new double[5];
    double *array2 = new double[5];
    for(int i = 0; i < 5; i++){
        double min = tower[0][i];
        for(int j = 0; j < 5; j++){
            if(tower[i][j] < min){
                min = tower[i][j];
            } 
        }
        array1[i] = min;
    }
    for(int i = 0; i < 5; i++){
        double temp[5];
        for (size_t j = 0; j < 5; j++)
        {
            temp[j] = tower[j][i];
        }
        sort(temp, temp + 5);

        for (size_t j = 0; j < 5; j++)
        {
            tower[j][i] = temp[j];
        }
        array2[i] = tower[0][i];
    }
    bool the_same = true;
    for(int i = 0; i < 5; i++){
        if (array1[i] != array2[i]){
            the_same = false;
            break; //  break
        }
    }
    if(the_same){
        cout << "Results are the same" << endl;
    }else{
        cout << "Results are not the same" << endl;
    }

    return array1;
}
Student* function_4(double arr[]){
    Student* head = nullptr;
    Student* tail = nullptr;
    const int countLimit = 8;

    double arrSum = 0;
    double min = arr[0];
    double max = arr[0];
    for(int i = 0; i < 5; i++){
        arrSum += arr[i];
        if(arr[i] < min) 
        min = arr[i];
        if(arr[i] > max) 
        max = arr[i];
    }
    for(int count = 1; count < countLimit; count++){
        Student* s = new Student{
            "name" + to_string(count), "surname" + to_string(count), 0, nullptr, nullptr
        };
        if(count == 1){ 
            s -> balance = max;
        }else if(count < 7){
            s->balance = arrSum;
        }else if(count == 7){
            s->balance = min;
        }
        if(!head){
            head = s;
            tail = s;
        }else{
            tail -> next = s;
            s -> prev = tail;
            tail = s;
        }
    }
    cout << "Linked list:" << endl;
    tail = head;
    while (tail) { // while цикл
        cout << "Name: " << tail -> name << " Surname: " << tail -> surname << " Balance: " << tail -> balance << endl;
        tail = tail -> next;
    }
    return head;
}

void help_for_function_5(ofstream& outputFile, Student* head){ // рекурсивну функцію
    if (!head) return;
    help_for_function_5(outputFile, head -> next);
    outputFile << head -> name << " " << head -> surname << " " << head -> balance << endl;
}

void readAndPrintFile(ifstream& inputFile){
    cout << "File contents: " << endl;
    string buffer;
    while (getline(inputFile, buffer)){
        cout << buffer << endl;
    }
}

void function_5(Student* head){ 
    ofstream outputFile("students.txt"); // функції роботи з файлами, для того, щоб записати у файл
    if(!outputFile){
        cerr << "Cannot open the file for writing." << endl;
        return;
    }
    help_for_function_5(outputFile, head);
    outputFile.close();
    ifstream inputFile("students.txt"); // функції роботи з файлами, для того, щоб зчитати з файлу
    if(!inputFile){
        cerr << "Cannot open the file for reading." << endl;
        return;
    }
    readAndPrintFile(inputFile);
    inputFile.close();
}

void freeMemory(Student* head){
    do{ //do while цикл
        Student* temp = head;
        head = head -> next;
        delete temp;
    }while(head);
}
void freeMatrix(float** matrix){
    for(int i = 0; i < 5; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}


int main(){
    float x = function_1();
    float** tower = function_2(x);
    double* arr = function_3(tower);
    Student* head = function_4(arr);
    function_5(head);

    freeMemory(head);
    freeMatrix(tower);
    delete[] arr;

    return 0;
}