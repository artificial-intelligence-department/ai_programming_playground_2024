#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long int element = 0;
    
    int n = 0;
    cin >> n;

    vector<long long int> inputs;
    for (int c = 0; c < n; c++) {
        cin >> element;
        inputs.push_back(element);
    }
    sort(inputs.begin(), inputs.end());

    double sum = 0;
    double mid = 0;

    for (int i = 0; i < n; i++)
    {   
        sum += inputs.at(i);
    }
    mid = sum/(double)n;
    double closest_to_mid = 1e9;
    int closest_idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (abs(double(inputs[i]) - mid) < closest_to_mid){
            closest_to_mid = abs(double(inputs[i]) - mid);
            closest_idx = i;
        }
    }

    int sum_result = 0;

    for (int i = 0; i < closest_idx; i++)
    {
        sum_result += inputs[i+1] - inputs[i];

        for (int j = 0; j <= i; j++)            
        {
            inputs[i-j] = inputs[i+1];
        }
    }

    for (int i = n-1; i > closest_idx; i--)
    {
            sum_result += inputs[i] - inputs[i-1];

            for (int j = 0; j <= (n-i); j++)            
            {
                inputs[i+j] = inputs[i-1];
            }
    }
    
    cout << sum_result << endl;
}