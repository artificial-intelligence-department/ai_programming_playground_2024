#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

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

double function_2(double arr[5][5]){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; i < 5; ++j){
            arr[i][j] = x;
        }
    }
    for (int i = 0; i < 5; ++i){
        for (int j = 0; i < 5; ++j){
            arr[i][j] = (arr[i][j] + 85 + i + j) * rand(1, 100);
        }
    }

    for (int i = 0; i < 5; ++i){
        for (int j = 0; i < 5; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    double x = function_1();

}