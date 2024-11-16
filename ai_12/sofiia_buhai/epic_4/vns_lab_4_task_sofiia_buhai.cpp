#include <iostream>
#include <bits/stdc++.h>

int main(){
    int n=10, min, sum=0, middle;
    int arr[n];

    // 1) Сформувати одновимірний масив цілих чисел, використовуючи генератор випадкових чисел.
    srand((unsigned) time(NULL));
    for(int i=0; i<n; i++){
        arr[i] = rand()%300;
    }

    // 2) Роздрукувати отриманий масив.
    for(int i=0; i<n; i++){
        std::cout << arr[i] << " ";
    }

    // 3) Знищити з масиву всі елементи, які збігаються з його мінімальним значенням.
    min = *std::min_element(arr, arr+n);
    for(int i=0; i<n; i++){
        if(arr[i]==min){
            for(int j=i; j<n-1; j++){
                arr[j]=arr[j+1];
            }
            n--;
        }
    }

    // 4) Додати на початок масиву 3 елементи зі значенням, яке дорівнює середньому арифметичному масиву.
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    middle = sum/n;
    n+=3;

    for(int i=(n-1); i>2; i--){
        arr[i]=arr[i-3];
    }
    arr[0]=middle;
    arr[1]=middle;
    arr[2]=middle;

    // 5) Роздрукувати отриманий масив
    std::cout << "\n";
    for(int i=0; i<n; i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}