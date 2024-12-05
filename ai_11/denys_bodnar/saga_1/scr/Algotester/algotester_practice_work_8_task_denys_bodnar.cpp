#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int n;
    vector<int> arr;

    while (cin >> n){
        arr.push_back(n);
    }

    sort(arr.begin(), arr.end());

    for (size_t i = 0; i < arr.size(); i++){
        if(i > 0) cout << " ";
        cout << arr[i];
    }

    return 0;
}