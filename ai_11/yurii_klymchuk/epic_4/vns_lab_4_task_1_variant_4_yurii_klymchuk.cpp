#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    //створюємо і виводимо наш вектор рандомних чисел
    vector<int> array = {30, -84, -19, 90, 68, -29, 73, 2, 3, -22, 86, -60, -23, -35, 56, 80, 83, 62, -48, 94};
    int size = array.size();
    cout << "Original array: " << endl;
    for(int i = 0; i < size; i++){
        if(i == (size-1)){
            cout << array[i] << "." << endl;
        }
        else{
            cout << array[i] << ", ";
        }
    }

    //створюємо новий вектор куди записуємо всі елементи індекси яких ділиться на 3
    vector<int> modified_array = array;
    for(int i = 0; i < size; i++){
        if(i%3 == 0){
            int element = array.at(i);
            auto it = find(modified_array.begin(), modified_array.end(), element);
            modified_array.erase(it);
        }
    }
    
    //вставляємо після від'ємних елементів нові числа
    int size_1 = modified_array.size();
    for(int i = 0; i < size_1; i++){
        if(modified_array[i] < 0 && i != 0){
            modified_array.insert(modified_array.begin()+(i+1), abs(modified_array[i-1]+1));
        }
    }

    //виводимо наш кінцевий масив
    int size_2 = modified_array.size();
    cout << "Modified array: " << endl;
    for(int i = 0; i < size_2; i++){
        if(i == (size_2-1)){
            cout << modified_array[i] << ".";
        }
        else{
            cout << modified_array[i] << ", ";
        }
    } 
    return 0;
}