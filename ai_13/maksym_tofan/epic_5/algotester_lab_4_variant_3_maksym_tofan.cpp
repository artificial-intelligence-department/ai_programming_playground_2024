#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

   
    vector<int> group0, group1, group2;


    for (int num : arr) {
        if (num % 3 == 0) {
            group0.push_back(num);
        } else if (num % 3 == 1) {
            group1.push_back(num);
        } else {
            group2.push_back(num);
        }
    }

   
    sort(group0.begin(), group0.end());  
    sort(group1.rbegin(), group1.rend()); 
    sort(group2.begin(), group2.end());  

   
    vector<int> result;
    result.insert(result.end(), group0.begin(), group0.end());
    result.insert(result.end(), group1.begin(), group1.end());
    result.insert(result.end(), group2.begin(), group2.end());

   
    set<int> unique_result(result.begin(), result.end());

    
    cout << unique_result.size() << endl;
    for (int num : unique_result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
