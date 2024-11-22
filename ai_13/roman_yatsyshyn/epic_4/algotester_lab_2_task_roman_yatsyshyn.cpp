#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stdarg.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int element = 0;
    int dif = 1e6;
    // int differ = 0;
    
    int n = 0;
    cin >> n;

    vector<int> inputs;

    for (int c = 0; c < n; c++) {
        cin >> element;
        inputs.push_back(element);
    }
    
    sort(inputs.begin(), inputs.end());

    if (n != 1)
    {

        // delete first element
        int current_element1 = inputs.at(0);
        inputs.erase(inputs.begin() + 0);
        int abc1 = abs(inputs.at(0)-inputs.at(n-2));

        inputs.insert(inputs.begin() + 0, current_element1);

        // delete last element
        inputs.erase(inputs.begin() + (n-1));
        int abc2 = abs(inputs.at(0)-inputs.at(n-2));

        if (abc1 < abc2)
        {
            cout << abc1;
        }
        else{
            cout << abc2;
        }
    }
    else{
        cout << "0";
    }
}