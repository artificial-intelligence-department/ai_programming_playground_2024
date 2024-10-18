#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int value_n, inter_result;
    int n = 0;
    cin >> value_n;
    inter_result = value_n;
    int a[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    
    for (int i = 0; i < 9; i++)
    {
        n += inter_result / a[8-i];
        inter_result = inter_result % a[8-i];
    }
    cout << n;
}