#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){

    int n;
    cin >> n;

    vector<int> list(n, 1);
    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
        cin >> numbers[i];

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++){
            if(numbers[i] < numbers[j]) {
                list[i] = max(list[i], 1 + list[j]);
            }
        }
    }
    
    auto result = max_element(list.begin(), list.end());
    cout << *result;

    return 0;
}