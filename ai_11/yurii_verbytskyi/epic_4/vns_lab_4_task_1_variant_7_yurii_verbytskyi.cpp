#include <iostream>
#include <stdio.h>
#include <cstdlib> //random

using namespace std;

int main(){
    
    int size; // = 9;
    cin >> size;
    //int array[size] = {5, 7, 98, 65, 74, 34, 67, 12, 0};
    int array[size];
    for(int i = 0; i < size; i++){
         array[i] = rand() % 100;
    } 

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    } cout << endl;


    for(int i = size - 1; i >= 0; i--){
        if(array[i] == 0){
            for(int j = i; j < size-1; j++){
                array[j] = array[j+1];
            }
            size --; 
            break;
        }
    } 

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    } cout << endl;


    int k;
    cin >> k;
    for(int i = size; i > k; i--){
    array[i] = array[i-1];
    }
    array[k+1] = 100;
    size ++; 

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }

    return 0;
}
