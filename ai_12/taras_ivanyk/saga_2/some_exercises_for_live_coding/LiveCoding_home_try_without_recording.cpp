#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <string>
#include <list>
using namespace std;

const int variant = 36;

float function_1(){
    float a,b;
    int c,d,e;
    double f;

    cout << "Enter 2 float numbers: " << endl;
    cin >> a >> b;
    cout << "Enter 3 int numbers: " << endl;
    cin >> c >> d >> e;
    cout << "Enter  float number: " << endl;
    cin >> f;

    double arr[] = {double(a), double(b),double(c),double(d),double(e),double(f)};
    int size_n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size_n - 1; ++i){
        for(int j = 0; j < size_n - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    } 
    double sum_max = 0;
    double sum_min = 0;

    cout << "3 maximum elements: \n";
    for(int i = size_n - 3; i < size_n; ++i){
        cout << arr[i] << " ";
        sum_max += arr[i];
    }

    cout << "\n 3 minimum elements: \n";
    for(int i = 0; i < 3; ++i){
        cout << arr[i] << " ";
        sum_min += arr[i];
    }
    cout << endl;
    double sum = 0.0;

    if(sum_max > sum_min * 2){
        sum = sum_max * pow(sum_min, 1);  // using math functions
    } else if(sum_max > sum_min * 3){
        if(sum_min != 0){
            sum = sum_max / sum_min;
        }
    } else if(sum_max > sum_min * 4){
        sum = sum_max + sum_min;
    } else{
        cout << "sum_max < sum_min * 2 \n";
    }
    double x = sum / double(variant);
    cout << endl << "X = " << x << endl;
    cout << endl;

    return x;
}

int** function_2(float x){

    srand(static_cast<unsigned>(time(nullptr)));
    int** matrix = new int*[5];

    cout << "Ordinar matrix full with x-es: \n";
    cout << "***********************" << endl;

    for(int i = 0; i < 5; ++i){
        matrix[i] = new int[5];
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = x;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = (matrix[i][j] + variant + j - i) * (rand() % 100);
        }
    }   
    cout << endl;
    cout << "New matrix: \n";
    cout << "**************************" << endl;

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return matrix;
}

int* function_3(int** tower) {
    int* min_elements = new int[5];
    bool are_the_same = false;

    cout << "Minimum values in columns: \n";
    for(int j = 0; j < 5; ++j){
        int min_value = tower[0][j];
        for(int i = 1; i < 5; ++i){
            if(tower[i][j] < min_value){
                min_value = tower[i][j];
            }
        }
        min_elements[j] = min_value;
        cout << min_value << " ";  
    }
    cout << endl;
    cout << "Another method: \n"; 

    for(int j = 0; j < 5; ++j){
        int min_value_2 = tower[0][j];
        for(int i = 1; i < 5; ++i){
            if(tower[i][j] < min_value_2){
                min_value_2 = tower[i][j];
            }
        }

    if(min_elements[j] != min_value_2){
            are_the_same = false;
        } 
        cout << min_value_2 << " ";  
    }
    cout << endl;

    if(are_the_same) 
        cout << "All good, you can be chill guy, results are the same)" << endl;
    else 
        cout << "Naaaah, results are not the same, so, it's bad, but you can just zabyty bolt and be the chill guy too)" << endl;
    cout << endl;

    return min_elements; 
}

struct Student {
    string firstName;
    string secondName;
    double accountBalance;
    Student* prev;
    Student* next;

    Student(string fName, string sName, double balance)
        : firstName(fName), secondName(sName), accountBalance(balance), prev(nullptr), next(nullptr) {}
};

Student* function_4(int* array) {
    srand(static_cast<unsigned>(time(nullptr)));

    string firstNames[] = {"Taras", "Iryna", "Mariya", "Stefan", "Nazar", "Ivanna", "Natalia"};
    string secondNames[] = {"Ivanyk", "Svyrydenko", "Ivanyk", "Shyjka", "Kryvychko", "Smachylo", "Ptychka"};

    for (int i = sizeof(firstNames) / sizeof(firstNames[0]) - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(firstNames[i], firstNames[j]);
    }

    for (int i = sizeof(secondNames) / sizeof(secondNames[0]) - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(secondNames[i], secondNames[j]);
    }

    Student* head = nullptr;
    Student* tail = nullptr;

    for (int i = 0; i < 7; ++i) {
        Student* newStudent = new Student(firstNames[i], secondNames[i], array[i % 5]);  // Assign balance from array
        newStudent->prev = tail;
        newStudent->next = nullptr;

        if (tail) {
            tail->next = newStudent;
        } else {
            head = newStudent;
        }
        tail = newStudent;
    }

    cout << endl << "Students list: " << endl;  //forward
    cout << "****************************" << endl;
    Student* current = head;
    while (current) {
        cout << "Name: " << current->firstName << " " << current->secondName;
        cout << ", Balance = " << current->accountBalance << endl;
        current = current->next;
    }

    return head;
};

void help_for_function_5(Student* head, ofstream &file_write, bool is_even){
    
    if(is_even){
        if(head){
            help_for_function_5(head -> next, file_write, is_even); // RECURSION
            file_write << "Name: " << head -> firstName << ", second name: " << head -> secondName << ", ";
            file_write << "balance account = " << head -> accountBalance << endl; 
        }
    } 
        else{
            Student* current = head;
            while(current){
                file_write << "Name: " << current -> firstName << " second name: " << current -> secondName;
                file_write << "Balance account = " << current -> accountBalance << endl; 
                current = current -> next;
            }
        }
    }

void help_for_function_5(Student* head, int variant){ // funtion_5 OVERLOADING FUNCTIONS
    
    bool is_even = variant % 2 == 0;

    string fileName = "students_list.txt";
    ofstream file_write(fileName);

    if(file_write.is_open()){
        help_for_function_5(head, file_write, is_even);
        file_write.close();
    } else{
        cout << "Unable to open the file( \n";
    }

    cout << endl << "Hmmmmm, what we have in our file? " << endl;
    cout << "*********************************" << endl;
    ifstream file_read(fileName);

    if(file_read.is_open()){
        string line;
        while(getline(file_read, line)){
            cout << line << endl;
        }
        file_read.close();
    } else{
        cerr << "Error file wasn't opened or created( \n";
    }
}

int main(){

    float x = function_1();
    int** tower = function_2(x);
    int* result = function_3(tower);

    cout << "Minimum elements in each column: \n";
    for(int j = 0; j < 5; ++j){
        cout << "Element in column #" << j+1 << ": " << result[j] << endl;
    }

    Student* students = function_4(result);

    help_for_function_5(students, variant);
    
    Student* current = students;
    while(current){
        Student* next = current -> next;
        delete current;                 // cleaning of dynamic memory
        current = next;
    }

    return 0;
}