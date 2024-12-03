#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

double x;
double tower[5][5];

double function_1(){
    double arr[6];
    double a, b;
    int c, d, e;
    float f;
    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;
    arr[5] = f;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);

    double sum_max = arr[0] + arr[1] + arr[2];
    double sum_min = arr[4] + arr[5] + arr[6];

    double result_1;

    if (sum_max > (sum_min * 2)){
        result_1 = sum_max*sum_min;
    }

    else if (sum_max > (sum_min * 3))
    {
        result_1 = sum_max / sum_min;
    }
    
    else if (sum_max > (sum_min * 4)){
        result_1 = sum_max + sum_min;    
    }

    double x = result_1 / 85.0;
    return x;
}

double function_2(){
    double arr[5][5];

    for (int i = 0; i < 5; ++i){
        for (int j = 0; i < 5; ++j){
            arr[i][j] = x;
        }
    }
    for (int i = 0; i < 5; ++i){
        for (int j = 0; i < 5; ++j){
            arr[i][j] = (arr[i][j] + 85 + i + j) * rand() % 100 +1;
        }
    }

    for (int i = 0; i < 5; ++i){
        for (int j = 0; i < 5; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return arr[5][5];
}

double function_3(){

    double arr_algo_1[5][5] = tower[5][5];

    // algorithm 1
    int c = sizeof(arr_algo_1[0]) / sizeof(arr_algo_1[0][0]);
    int r = sizeof(arr_algo_1) / sizeof(arr_algo_1[0]);

    for (int i = 0; i < r; i++) 
    {
        // Loop for column of matrix
        for (int j = 0; j < c; j++) 
        {
            // Loop for comparison and swapping
            for (int k = 0; k < c - j - 1; k++) 
            {
                if (arr_algo_1[k][i] > arr_algo_1[k][i + 1]) 
                {
                    // Swapping of elements
                    swap(arr_algo_1[k][i], arr_algo_1[k][i + 1]);
                }
            }
        }
    }

    double arr_3[5];
    arr_3[0] = arr_algo_1[0][0];
    arr_3[1] = arr_algo_1[0][1];
    arr_3[2] = arr_algo_1[0][2];
    arr_3[3] = arr_algo_1[0][3];
    arr_3[4] = arr_algo_1[0][4];

    // algorithm 2
 
    double arr_algo_2[5][5] = tower[5][5];

    double arr_2_1[5];
    double arr_2_2[5];
    double arr_2_3[5];
    double arr_2_4[5];
    double arr_2_5[5];

    for (int i = 0; i < 5; i++){
        arr_2_1[i] = arr_algo_2[i][0];
    }

    for (int i = 0; i < 5; i++){
        arr_2_2[i] = arr_algo_2[i][1];
    }

    for (int i = 0; i < 5; i++){
        arr_2_3[i] = arr_algo_2[i][2];
    }

    for (int i = 0; i < 5; i++){
        arr_2_4[i] = arr_algo_2[i][3];
    }

    for (int i = 0; i < 5; i++){
        arr_2_5[i] = arr_algo_2[i][4];
    }

    int n = sizeof(arr_2_1) / sizeof(arr_2_1[0]);
    sort(arr_2_1, arr_2_1 + n);
    sort(arr_2_2, arr_2_2 + n);
    sort(arr_2_3, arr_2_3 + n);
    sort(arr_2_4, arr_2_4 + n);
    sort(arr_2_5, arr_2_5 + n);

    double arr_result[5];
    arr_result[0] = arr_2_1[0];
    arr_result[1] = arr_2_2[0];
    arr_result[2] = arr_2_3[0];
    arr_result[3] = arr_2_4[0];
    arr_result[4] = arr_2_5[0];
 


    return 0;
}

int main(){
    x = function_1();
    tower[5][5] = function_2();
    function_3();

}