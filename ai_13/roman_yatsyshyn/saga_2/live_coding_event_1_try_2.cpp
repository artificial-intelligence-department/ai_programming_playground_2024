#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const double var = 85.0;

struct Student
{
    string firstname;
    string lastname;
    double accountbalance;

    Student(const string &fname, const string &lname, double bankacc) : firstname(fname), lastname(lname), accountbalance(bankacc) {}
};

struct Node
{
    Student student;
    Node* prev;
    Node* next;

    Node(const Student& stud) : student(stud), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {

public:
    Node* head;
    Node* tail;

    DoubleLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoubleLinkedList() {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp; 
        }
        
    }

    Node* getHead() const {
        return head;
    }

    void addStudent(const Student& student){
        Node* newNode = new Node(student);
        if (!head)
        {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print() const {
        Node* current = head;
        while (current)
        {
            cout << current->student.firstname << " " << current->student.lastname << " " << current->student.accountbalance << "\n";
            current = current->next;
        }
    }

    void writeintofile(Node* head, const string& filename) {
        fstream file(filename, ios::out | ios::in | ios::trunc);
        Node* current = head;
        while (current) {
            file << current->student.firstname << " " << current->student.lastname << current->student.accountbalance << "\n";
            current = current->next;
        }

        file.close();
    }

};

double function_1(){
    int a, b;
    cin >> a >> b;
    
    double c, d, e;
    cin >> c >> d >> e;

    float f;
    cin >> f;

    double arr[6];

    arr[0] = a; arr[1] = b;
    arr[2] = c; arr[3] = d; arr[4] = e;
    arr[5] = f;

    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);

    double sum_min = arr[0] + arr[1] + arr[2];
    double sum_max = arr[3] + arr[4] + arr[5];
    double result_1;

    if (sum_max > (sum_min * 4))
    {
        result_1 = sum_max + sum_min;
    }

    else if (sum_max > (sum_min * 3))
    {
        result_1 = sum_max / sum_min;
    }

    else if (sum_max > (sum_min * 2))
    {
        result_1 = sum_max * sum_min;
    }

    double x = result_1 / var;

    return x;
}

double (*(function_2)(double &x))[5]
{
    static double matrix[5][5];

    // Заповнення матриці значеннями x
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }
    
    // Оновлюємо значення
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + var + i + j) * (rand() % 100 + 1);
        }
    }

    // Виводимо значення матриці в консоль
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

double * function_3(double tower[5][5]){
    static double arr[5]; // масив, який нас просять створити
    
    // Масиви, які ми створюємо для подальшого порівняння
    double arr_check_1[5];
    double arr_check_2[5];

// Алгоритм 1
    for (int j = 0; j < 5; j++)
    {   
        double arr_col_1[5];

        for (int i = 0; i < 5; i++)
        {
            arr_col_1[i] = tower[i][j];
        }

        int n = sizeof(arr_col_1) / sizeof(arr_col_1[0]);
        sort(arr_col_1, arr_col_1 + n);
        arr_check_1[j] = arr_col_1[0];

    }

// Алгоритм 2

    // Транспонуємо матрицю
    double trans_tower[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            trans_tower[i][j] = tower[j][i];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        double arr_col_2[5];

        for (int j = 0; j < 5; j++)
        {
            arr_col_2[j] = trans_tower[i][j];
        }

        int n = sizeof(arr_col_2) / sizeof(arr_col_2[0]);
        sort(arr_col_2, arr_col_2 + n);
        arr_check_2[i] = arr_col_2[0];

    }

    bool checker = true;
    for (int i = 0; i < 5; i++)
    {
        if (arr_check_1[i] != arr_check_2[i])
        {
            checker = false;
            break;
        } else{
            arr[i] = arr_check_1[i];
            continue;
        }
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    return arr;
}

Node* function_4(double* arr){
    DoubleLinkedList student_list;
    student_list.addStudent(Student("John", "Doe", 0));
    student_list.addStudent(Student("Alice", "Smith", 0));
    student_list.addStudent(Student("Bob", "Johnson", 0));
    student_list.addStudent(Student("Emily", "Brown", 0));
    student_list.addStudent(Student("Chris", "Davis", 0));
    student_list.addStudent(Student("Anna", "Wilson", 0));
    student_list.addStudent(Student("Michael", "Schumacher", 0));

    double* arr_point = arr;

    int n = sizeof(arr_point) / sizeof(arr_point[0]);
    sort(arr, arr + n);
    double arr_sorted[5];
    for (int i = 0; i < 5; i++)
    {
        arr_sorted[i] = arr_point[i];
    }
    
    student_list.head->student.accountbalance = arr_sorted[4];
    student_list.head->next;
    
    double sum;

    for (int i = 0; i < 5; i++)
    {
        sum += arr_point[i];
        student_list.head->student.accountbalance = sum;
        student_list.head->next;
    }
    
    student_list.head->student.accountbalance = arr_sorted[0];

    student_list.print();

    return student_list.head;
}

void function_5(){
    ifstream file("file.txt");

    if (!file.is_open())
    {
        cerr << "Failed to open file on such existing file!";
    }
    
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    
    file.close();
}


void function_5(Node* head){
    DoubleLinkedList student_list;
    
    head = student_list.head;

    student_list.writeintofile(head, "file.txt");

    function_5();
}

int main(){
    double x = function_1();
    double(*tower)[5];
    tower = function_2(x);
    double* arr;
    arr = function_3(tower);
    Node* head = function_4(arr);
    function_5(head);
}