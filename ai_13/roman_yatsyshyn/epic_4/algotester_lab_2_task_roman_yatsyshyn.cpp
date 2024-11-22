#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stdarg.h>
#include <vector>

using namespace std;

int func(int n, int i, int dif_old, vector<int> inputs){
    int differ = 0;

    while (i < n)    
    {
        int current_element = inputs.at(i);

        inputs.erase(inputs.begin() + i);

        for (int a = 0; a < n-1; a++)
        {   
            for (int b = 0; b < n-1; b++)
            {
                if (abs(inputs.at(a)-inputs.at(b)) > differ)
                {
                    differ = abs(inputs.at(a)-inputs.at(b));
                }
            }
        }

        inputs.insert(inputs.begin() + i, current_element);

        if (differ < dif_old) {dif_old = differ;}

        int recursive = func(n, ++i, dif_old, inputs);
        return recursive;
    }

    return dif_old;    
}

int main(){
    int element = 0;
    
    int n = 0;
    cin >> n;

    vector<int> inputs;

    for (int c = 0; c < n; c++) {
        cin >> element;
        inputs.push_back(element);
    }    

    int i = 0;
    int dif_old = 1e6;
    int dif = func(n, i, dif_old, inputs);

    cout << dif;

    return 0;
}