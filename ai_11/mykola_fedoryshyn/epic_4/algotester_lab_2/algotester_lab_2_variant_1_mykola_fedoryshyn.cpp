#include <iostream>
using namespace std;
int main(){
    int size;
    bool max = true, min = true;

    std::cin >> size;
    int list[size];
    for(int i = 0; i < size; i++){
        std::cin >> list[i];
    }
    /*Якщо масив має 1 значення то вивід завжди 0*/
    if(size == 1 || size == 0){
        cout << 0;
        return 0;
    }
    for(int i = 1; i < size; i++){
        int j = i-1, index = list[i];
        for(j; j > -1 && list[j] > index; j--){
            list[j+1] = list[j];
        }
        list[j+1] = index;
    }

    /*Перевірка чи максимальний і мінімальний елементи не повторюються*/
    if(list[size-1] == list[size-2]){
        max = false;
    }
    else if(list[0] == list[1]){
        min = false;
    }

    if(max && min){
        if (list[size-2] - list[0] > list[size-1] - list[1]){
            cout << list[size-1] - list[1];
        }
        else{
            cout << list[size-2] - list[0];
        }
    }
    else if(max){
        cout << list[size-2] - list[0];
    }
    else if(min){
        cout << list[size-1] - list[1];
    }
    else{
        cout << list[size-1] -list[0];
    }

    return 0;
}