#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long int element = 0;
    
    long long int n = 0;
    cin >> n;

    vector<long long int> inputs;

    for (long long int c = 0; c < n; c++) {
        cin >> element;
        inputs.push_back(element);
    }
    
    sort(inputs.begin(), inputs.end());

    long long int sum = 0;

    for (long long int i = 0; i < n; i++)
    {
        sum += (inputs.at(i) - 1);
    }
    
    cout << sum;
}