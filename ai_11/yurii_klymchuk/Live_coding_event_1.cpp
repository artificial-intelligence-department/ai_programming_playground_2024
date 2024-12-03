#include <iostream>
#include <bits/stdc++.h> 
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

float function_1(){
    float a,b;
    cin >> a >> b;

    int c,d,e;
    cin >> c >> d >> e;

    double f;

    cin >> f;

    double array[] = {(double)a, (double)b, (double)c,(double)d,(double)e,(double)f};

    sort(array, array + 6);
    double max_sum = array[0]+array[1]+array[2];
    double min_sum = array[3]+array[4]+array[5];
    float x;
    if(max_sum > min_sum*2 && max_sum < min_sum*3){
        x = (float)(max_sum * min_sum);
    } else if(max_sum > min_sum*3 && max_sum < min_sum*4 && min_sum != 0){
        x = (float)(max_sum / min_sum);
    } else if(max_sum > min_sum*4){
        x = (float)(max_sum + min_sum);
    }
    else{
        x = 1;
    }

    float fin = x/11;
    cout << fin << endl;

    return fin;
}

float** function_2(float x){
    float** matrix= new float*[5];

    for (int i = 0; i < 5; ++i) {
        matrix[i] = new float[5];
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] = (matrix[i][j] + 11 + j - i) * (rand() % 101);
        } 
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        } 
        cout << endl;
    }
    return matrix;
}

float* function_3(float** matrix){
    float* array_sort1 = new float[5];

    for(int i = 0; i < 5; i++){
        float minimal = 10000000;
        for(int j = 0; j < 5; j++){
            if(matrix[j][i] < minimal){
                minimal = matrix[j][i];
                array_sort1[i] = matrix[j][i];
                
            }
        } 
    }

    float* array_sort2 = new float[5];
    for (int i = 0; i < 5; i++){
        array_sort2[i] = min(matrix[0][i], matrix[4][i]);
    }

    bool identical = true;
    for (int i = 0; i < 5; i++){
        if (array_sort1[i] != array_sort2[i]){
            identical = false;
            break;
        }
    }

    return array_sort1;
}


struct Student{
    string name;
    string surname;
    float money;
};

// struct Node {
//     Student data;          
//     Node* prev;        
//     Node* next;         

    
//     Node(Student value.name) : data.name(value.name), prev(nullptr), next(nullptr) {}
// };


// class DoublyLinkedList {
// private:
//     Node* head; 
//     Node* tail; 

// public:
//     DoublyLinkedList() : head(nullptr), tail(nullptr) {}

//     void append(int value) {
//         Node* newNode = new Node(value);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     void prepend(int value) {
//         Node* newNode = new Node(value);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//     }

//     ~DoublyLinkedList() {
//         Node* current = head;
//         while (current) {
//             Node* temp = current;
//             current = current->next;
//             delete temp;
//         }
//     }
// };
void function_5(){

}
int main() {
    float x = function_1();

    float** tower;
    tower = function_2(x);

    float* min_array;
    min_array = function_3(tower);

    
    return 0;
}