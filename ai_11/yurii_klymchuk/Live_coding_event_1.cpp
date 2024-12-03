#include <iostream>
#include <bits/stdc++.h> 
#include <stdlib.h>
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
    cout << fin;

    return fin;
}

//нове_значення=(поточне_значення+номер_варіанту+індекс_стовбця−індекс_стрічки)∗rand(1,100
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

// float function_3(float** array){

// }
int main() {
    float x = function_1();

    float** tower;
    tower = function_2(x);


    return 0;
}