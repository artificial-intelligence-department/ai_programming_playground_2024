#include <iostream>
#include <algorithm>

using namespace std;

const int option = 70; // Цілочисельна константа

float function_1(){
    float a, b; // Дійсна змінна
    int c, d, e; // Цілочисельна змінна
    double f; // Дійсна з подвійною точністю змінна
    cin >> a >> b >> c >> d >> e >> f;
    double arr1[6] = {a, b, c, d, e, f}; // Одновимірний масив
    sort(arr1[0], arr1[5]);
    float min_sum = arr1[0] + arr1[1] + arr1[2];
    float max_sum= arr1[3] + arr1[4] + arr1[5];
    float y;
    if (max_sum > (min_sum * 2)) { // Умовний оператор
        y = max_sum * min_sum;
    }
    if (max_sum > (min_sum * 3)){
        y = max_sum * min_sum;
    }
    if (max_sum > (min_sum * 4)){
        y = max_sum + min_sum;
    }
    float x = y/option; 
    cout << x << endl;
    return x;
}

float **function_2(float& x){ //вказівник
    float **arr2 = new float *[5]; // Двовимірний масив
    for(int i = 0; i < 5; i++){ // Цикл for
        for( int j = 0; j < 5; j++){
            arr2[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            float new_x = (x + option + j - i) * (rand()%100+1);
            arr2[i][j] = new_x;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << arr2[i][j];
        }
    }
    return arr2;
}

float *function_3(float **tower){
    float *arr3 = new float[5];
    float *arr4 = new float[5];
    float small;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            
        }
    }
}

int main(){
    float x = function_1();
    float  **tower = function_2(x);


    return 0;
}