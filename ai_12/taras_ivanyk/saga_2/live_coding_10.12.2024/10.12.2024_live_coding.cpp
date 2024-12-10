#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <list>
using namespace std;

const int variant = 36;

float function_1(){
    float a, b;
    int c, e, d;
    double f;

    cout << "Enter 2 float numbers: \n";
    cin >> a >> b;
    cout << "Enter 3 integers: \n";
    cin >> c >> d >> e;
    cout << "Enter double number: \n";
    cin >> f;
    
    double arr[] = {double(a), double(b), double(c), double(d), double(e), double(f)};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    double max_sum = 0.0;
    double min_sum = 0.0;

    cout << "3 max numbers: \n";
    for(int i = 3; i < size; ++i){
        cout << arr[i] << " ";
        max_sum += arr[i];
    }

    cout << endl;
    cout << "3 min numbers: \n";
    for(int i = 0; i < size - 3; ++i){
        cout << arr[i] << " ";
        min_sum += arr[i];
    }
    double sum = 0.0;

    if(max_sum > min_sum * 2){
        sum = max_sum * min_sum;
    } else if(max_sum > min_sum * 3){
        sum = max_sum / min_sum;
    } else if(max_sum > min_sum * 4){
        sum = max_sum + min_sum;
    } else{
        cout << "max_sum < min_sum * 2 \n";
    }
    double x = sum / double(variant);
    cout << endl << "x = " << x << endl;
    cout << endl;

    return x;
}

int** function_2(float x){

    srand(static_cast<unsigned>(time(nullptr)));
    int** matrix = new int*[5]; // dynamic memory
    
    for(int i = 0; i < 5; ++i){
        matrix[i] = new int[5];
    }
    
    // matrix full with x-es:
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = x;
        }
    }

    // matrix full with random elements:

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = (matrix[i][j] + variant + j - i) * rand() % 100;
        }
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

int* function_3(int** tower){
    int* min_in_cols = new int[5];
    int* min_col_another = new int[5];

    bool are_same = false;

    cout << endl << "First method" << endl;
    for(int j = 0; j < 5; ++j){
        int minimum = tower[0][j];
        for(int i = 1; i < 5; ++i){
            if(tower[i][j] < minimum){
                minimum = tower[i][j];
            }
        }
        min_in_cols[j] = minimum;
        cout << minimum << " ";
    }
    cout << endl;

    // Another method:

    cout << "Another method: \n";
    for(int j = 0; j < 5; ++j){
        for(int i = 0; i < 5; ++i){
            for(int k = 0; k < 5-i-1; ++k){
                if(tower[k][j] > tower[k + 1][j]){
                    int temp = tower[k][j];
                    tower[k][j] = tower[k + 1][j];
                    tower[k + 1][j] = temp;
                }
            }
        }
        min_col_another[j] = tower[0][j];
        cout << min_col_another[j] << " ";
    }
    cout << endl;

    for(int j = 0; j < 5; ++j){
        if(min_in_cols[j] != min_col_another[j]){
            are_same = false;
        }
    }

    are_same = true;

    if(are_same){
        cout << "All good, you can just be a chill guy and go to sleep, because arrays of minimum numbers in cols are the same in 2 different methods \n";
    } else{
        cout << "Naaaah, the numbers are not same, but you can just zabyty bolt and be the chill guy too) \n";
    }

    delete[] min_col_another;
    return min_in_cols;
}

struct Student{
    string firstName;
    string secondName;
    double accountBalance;
    Student* prev;
    Student* next;

    Student(string fName, string sName, double balance) : firstName(fName), secondName(sName), accountBalance(balance), prev(nullptr), next(nullptr){}
};

Student* function_4(int* array){
    srand(static_cast<unsigned>(time(nullptr)));

    string firstNames[] = {"Taras", "Iryna", "Mariya", "Stefan", "Nazar", "Teodor", "Brownie"};
    string secondNames[] = {"Ivanyk", "Svyrydenko", "Bilotska", "Shyika", "Kryvychko", "Talan", "Cookie"};
    
    for(int i = sizeof(firstNames) / sizeof(firstNames[0]) - 1; i > 0; --i){
        int j = rand() % (i + 1);
        swap(firstNames[i], firstNames[j]);
    }

    for(int i = sizeof(secondNames) / sizeof(secondNames[0]) - 1; i > 0; --i){
        int j = rand() % (i + 1);
        swap(secondNames[i], secondNames[j]);
    }

    Student* head = nullptr;
    Student* tail = nullptr;

    for(int i = 0; i < 7; ++i){
        Student* newstudent = new Student(firstNames[i], secondNames[i], array[i % 5]);

        newstudent -> prev = tail;
        newstudent -> next = nullptr;

        if(tail){
            tail -> next = newstudent;
        }  else{
            head = newstudent;
        }
        tail = newstudent;
    }

    cout << endl << "Students list: " << endl;
    cout << "****************************************\n";
    Student* curr = head;
    while(curr){
        cout << "Name: " << curr -> firstName << " " << ",surname: " << curr -> secondName;
        cout << ", balance = " << curr -> accountBalance << endl; 
        curr = curr -> next;
    }

    return head;
}

void help_for_function_5(Student* head, ofstream &file_write, bool is_even){

    if(is_even){
        if(head){
            help_for_function_5(head -> next, file_write, is_even);
            file_write << "Name: " << head -> firstName << ", surname: " << head -> secondName << ", balance account = " << head -> accountBalance << endl;
        }
    }
    else{
        Student* curr = head;
        while(curr){
            file_write << "Name: " << curr -> firstName << ", surname: " << curr -> secondName << ", balance account = " << curr -> accountBalance << endl;
            curr = curr -> next;
        }
    }
}

void help_for_function_5(Student* head, int variant){
    bool is_even = variant % 2 == 0;
    string filename = "students_list.txt";
    ofstream file_write(filename);

    if(file_write.is_open()){
        help_for_function_5(head, file_write, is_even);
        file_write.close();
    } else{
            cout << "Can't open a file( \n";
        }

    cout << endl << "What we have in our file? \n";
    cout << "here it is: \n";
    ifstream file_read(filename);

    if(file_read.is_open()){
        string line;
        while(getline(file_read, line)){
            cout << line << endl;
        } 
        file_read.close();
    } else{
        cerr << "Error file wasn't opened or created! \n";
    }
}

int main(){
    float x = function_1();
    int** tower = function_2(x);
    int* result = function_3(tower);

    Student* students = function_4(result);
    
    help_for_function_5(students, variant);

    Student* current = students;
    while(current){
        Student* next = current -> next;
        delete current;
        current = next;
    }

    return 0;
}