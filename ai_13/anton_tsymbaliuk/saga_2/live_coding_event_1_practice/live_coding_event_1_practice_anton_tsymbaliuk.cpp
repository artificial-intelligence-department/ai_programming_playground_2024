#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <fstream>

int const VARIANT = 82;             //цілочисельна константа 4

struct Student{             //своя структура 19
    std::string name, surname;
    double balance;

    Student(){
        std::string str = "0_0";
    }

    Student(std::string name, std::string surname, double balance){
        this->name = name;
        this->surname = surname;
        this->balance = balance;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student){
        os << "Balance on " << student.name << " " << student.surname << "'s account is " << student.balance << std::endl; 
        return os;
    }
};

struct Node{
    Student student;
    Node* next;
    Node* prev;

    Node(){
        next = nullptr;
        prev = nullptr;
    }

    Node(Student student){
        this->student = student;
        next = nullptr;
        prev = nullptr;
    }

    void add(Student student){
        if(next == nullptr) {           //розгалуження і умовний оператор 5
            next = new Node(student);
            next->prev = this;
        }
        else{
            Node* temp = next;
            if(temp->next == nullptr){
                temp->next = new Node(student);
                temp->next->prev = temp;
            }
            else{
                while(temp->next->next != nullptr) temp = temp->next;
                temp->next->next = new Node(student);
                temp->next->next->prev = temp->next;
            }
        }
        
    }

    Student& operator[](int index){
        int i = 1;
        Node* temp = next;
        if(index == 0) return student;
        while(true){                // while   9
            if( i == index) return temp->student;
            i++;
            temp = temp->next;
        }
    }
};

double function_1(){
    double a, b;                    //дійсна змінна з подвійною точністю 3
    std::cout << "Enter a and b : ";
    std::cin >> a >> b;         //введення та виведення 18
    int c, d, e;            // змінна int    1
    std::cout << "Enter integers c, d and e : ";
    std::cin >> c >> d >> e;
    float f;
    std::cout << "Enter float number f : ";
    std::cin >> f;                  //дійсна змінна 2
    double* arr = new double[6];            //одновимірний масив і вказівник       6 і 20
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;
    arr[5] = f;
    std::sort(arr, arr + 6);
    std::cout << "Three biggest values are : " << arr[5] << "  " << arr[4] << "  " << arr[3] << std::endl;
    std::cout << "Three smallest values are : " << arr[0] << "  " << arr[1] << arr[2] << std::endl;
    double res;
    double maxSum = arr[5] + arr[4] + arr[3];
    double minSum = arr[0] + arr[1] + arr[2];
    if(maxSum > minSum * 4){
        res = minSum + maxSum;
        std::cout << "Addition : " << res << std::endl;
    }
    else if(maxSum > minSum * 3){
        res = minSum / maxSum;
        std::cout << "Division : " << res << std::endl;
    }
    else if(maxSum > minSum * 2){
        res = minSum * maxSum;
        std::cout << "Multiplication : " << res << std::endl;
    }
    res /= VARIANT;
    std::cout << res << std::endl;
    return res;
}

double** function_2(double& x){
    int const SIZE = 5;
    double** matrix = new double*[SIZE];            //двовимірний масив 7
    for(int i = 0; i < SIZE; i++) {                 // for  10
        matrix[i] = new double[SIZE];
        for(int j = 0; j < SIZE; j++){
            matrix[i][j] = x;
        }    
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++){
            matrix[i][j] = (x + VARIANT + i + j) *(std::rand() & 100 + 1);
            std::cout << matrix[i][j] << "  ";
        }    
        std::cout << std::endl;
    }

    return matrix;
    // for(int i = 0; i < SIZE; i++) delete[] matrix[i];
    // delete[] matrix;
}

double* function_3(double** tower){
    int const SIZE = 5;
    double* maxs = new double[SIZE];
    double** copy1 = new double*[SIZE];
    double** copy2 = new double*[SIZE];
    for(int i = 0; i < SIZE; i++){
        copy1[i] = new double[SIZE];
        copy2[i] = new double[SIZE];
        for(int k = 0; k < SIZE; k++){
            copy1[i][k] = tower[i][k];
            copy2[i][k] = tower[i][k];
        }
    }
    for(int i = 0;  i < SIZE; i++){
        bool sorted = true;
        do{                     // do while  8
            sorted = true;
            for(int j = 0; j < SIZE - 1; j++){
                if(copy1[i][j] > copy1[i][j+ 1]){
                    sorted = false;
                    std::swap(copy1[i][j], copy1[i][j+ 1]);
                }
            }
        }while(!sorted);
    }
    std::sort(copy2[0], copy2[0] + SIZE);
    std::sort(copy2[1], copy2[1] + SIZE);
    std::sort(copy2[2], copy2[2] + SIZE);
    std::sort(copy2[3], copy2[3] + SIZE);
    std::sort(copy2[4], copy2[4] + SIZE);
    bool isIdentical = true;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(copy1[i][j] != copy2[i][j]) {
                isIdentical = false;
                break;                  //break 11
            }
        }
        if(!isIdentical) break;
    }
    if(isIdentical) std::cout << "Two sorting algorithms wotkins identicaly\n";
    else std::cout << "Sorting algorithm are working with errors!\n";

    maxs[0] = copy2[0][SIZE - 1];
    maxs[1] = copy2[1][SIZE - 1];
    maxs[2] = copy2[2][SIZE - 1];
    maxs[3] = copy2[3][SIZE - 1];
    maxs[4] = copy2[4][SIZE - 1];
    return maxs;
}

Node* function_4(double* f3){
    std::sort(f3, f3 + 5);
    Node* head = new Node(Student("Boba", "Bobovych", f3[4]));
    head->add(Student("B", "BB", f3[0]));
    head->add(Student("A", "AA", f3[0] + f3[1]));
    head->add(Student("C", "CC", f3[0] + f3[1] + f3[2]));
    head->add(Student("V", "VV", f3[0] + f3[1] + f3[2] + f3[3]));                           // математичні операції 15
    head->add(Student("N", "NN", f3[0] + f3[1] + f3[2] + f3[3] + f3[4]));
    head->add(Student("M", "MM", f3[0]));
    for(int i = 0; i < 7; i++){
        std::cout << (*head)[i];
    }
    return head;
}

void function_5(Node*& node, std::ofstream& file){              //перевантажена функція 12 і рекурсивна функція та аргументи    12 і 13 та 14
    if(node->prev == nullptr) return;
    file << node->student.name.c_str() << ' ';
    file << node->student.surname.c_str() << ' ';
    file << node->student.balance << std::endl;
    function_5(node->prev, file);
}

void function_5(Node* head){
    std::ofstream file("file.txt", std::ofstream::out);             //робота з файлами 16 і 17
    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    function_5(temp, file);
    file.close();
    std::ifstream readFile("file.txt", std::ifstream::in);
    std::string text;
    while(std::getline(readFile, text)){
        std::cout << text << std::endl;
    }
    readFile.close();

}

int main(){
    double x = function_1();
    double** tower = function_2(x);
    double* f3 = function_3(tower);
    Node* head = function_4(f3);
    function_5(head);
    return 0;
}