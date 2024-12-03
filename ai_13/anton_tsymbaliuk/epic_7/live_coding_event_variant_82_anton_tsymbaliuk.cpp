#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <iostream>      // варіант 4
#include <algorithm>
#include <cstdlib>

const int INF = INT32_MAX;
const int VARIANT = 82;

struct Student{
    std::string name, surname;
    double balance;
};

struct Node{
    Student student;
    Node* next;
    Node* prev;

    Node(Student student){
        this->student = student;
        next = nullptr;
        prev = nullptr;
    }

    void add(Student student){
        Node* temp = next;
        if(temp == nullptr){
            next = new Node(student);
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node(student);
    }

    Student& operator[](int i){
        if(i == 0) return student;
        Node* temp = next;
        int j = 1;
        while(temp->next != nullptr && i != j){
            temp = temp->next;
            j++;
        }
        return temp->student;
    }
};

double function_1(){
    float a, b; 
    std::cin >> a >> b;
    int c, d, e;
    std::cin >> c >> d >> e;
    double f;
    std::cin >> f;
    double arr[6] = {a, b, c, d, e, f};
    double* arr1 = new double [6];
    arr1[0] = arr[0];
    arr1[1] = arr[1];
    arr1[2] = arr[2];
    arr1[3] = arr[3];
    arr1[4] = arr[4];
    arr1[5] = arr[5];
    std::sort(arr1, arr1 +6);
    double res;
    std::cout << "Max values: " << arr1[3] << "  " << arr1[4] << "  " << arr1[5] << std::endl;
    std::cout << "Min values: " << arr1[0] << "  " <<  arr1[1] << " " << arr1[2] << std::endl;
    if(arr1[5] + arr1[4] > (arr1[0] + arr1[1] ) * 4){
        res = (arr1[5] + arr1[4]) + (arr1[0] + arr1[1]);
        std::cout << (arr1[5] + arr1[4]) + (arr1[0] + arr1[1]) << std::endl;
    } 
    else if(arr1[5] + arr1[4] > (arr1[0] + arr1[1] ) * 3){
        res = (arr1[5] + arr1[4]) / (arr1[0] + arr1[1]);
        std::cout << (arr1[5] + arr1[4]) / (arr1[0] + arr1[1]) << std::endl;
    } 
    else if(arr1[5] + arr1[4] > (arr1[0] + arr1[1] ) * 2){
        res = (arr1[5] + arr1[4]) + (arr1[0] + arr1[1]);
        std::cout << (arr1[5] + arr1[4]) * (arr1[0] + arr1[1]) << std::endl;
    } 
    double X = VARIANT / res;
    std::cout << X << std::endl;
    return X;
}

double** function_2(double& x){
    double** arr = new double*[5];
    for(int i = 0; i < 5; i++){
        arr[i] = new double[5];
        for(int j = 0; j < 5 ; j++){
            arr[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 ; j++){
            arr[i][j] = (x +VARIANT + i + j) * (std::rand() % 100 + 1);
        }
    }

    for(int i = 0; i < 5; i++){
        std::cout << std::endl;
        for(int j = 0; j < 5 ; j++){
            std::cout << arr[i][j] << "  ";
        }
    }
    return arr;
}

double* function_3(double** tower){
    double* arr = new double[5];
    for(int i = 0; i < 5; i++){
        double min = tower[i][0];
        for(int j = 0; j < 5; j++){
                if(min > tower[i][j]) min = tower[i][j];
        }
        arr[i] = min;
    }
    std::sort(tower[0], tower[0] + 5);
    std::sort(tower[1], tower[1] + 5);
    std::sort(tower[2], tower[2] + 5);
    std::sort(tower[3], tower[3] + 5);
    std::sort(tower[4], tower[4] + 5);
    double* arr2 = new double[5];
    arr2[0] = tower[0][0];
    arr2[1] = tower[1][0];
    arr2[2] = tower[2][0];
    arr2[3] = tower[3][0];
    arr2[4] = tower[4][0];
    for(int i = 0; i < 5; i++){
        std:: cout << "arr1 : " << arr[i] << "\tarr2 : " << arr2[i] << std::endl;
    }
    return arr2;
}

Node& function_4(double* bebe){
    Student student1;
    student1.balance = 100;
    student1.name = "Zahar";
    student1.surname = "Shturyn";
    Node node(student1);
    Student student2;
    student2.balance = 1;
    student2.name = "A";
    student2.surname = "X";
    Student student3;
    student3.balance = 0;
    student3.name = "S";
    student3.surname = "C";
    Student student4;
    student4.balance = 50;
    student4.name = "F";
    student4.surname = "B";
    Student student5;
    student5.balance = 200;
    student5.name = "G";
    student5.surname = "B";
    Student student6;
    student6.balance = 40;
    student6.name = "H";
    student6.surname = "N";
    Student student7;
    student7.balance = 65;
    student7.name = "J";
    student7.surname = "M";
    node.add(student2);
    node.add(student3);
    node.add(student4);
    node.add(student5);
    node.add(student6);
    node.add(student7);
    node[0].balance = bebe[4];
    node[1].balance = bebe[0] + bebe[1];
    node[2].balance = bebe[0] + bebe[1];
    node[3].balance = bebe[0] + bebe[1]  + bebe[2];
    node[4].balance = bebe[0] + bebe[1]  + bebe[2] + bebe[3];
    node[5].balance = bebe[0] + bebe[1]  + bebe[2] + bebe[3] + bebe[4];
    node[6].balance = bebe[0];
    int i = 0;
    do{
        std::cout << node[i].name << std::endl;
        i++;
    }while(i < 7);          //DO WHILE!!
    return node;
}

int main(){
    double x = function_1();
    double** tower = function_2(x); 
    double* bebe = function_3(tower);
    Node node = function_4(bebe);
    return 0;
}