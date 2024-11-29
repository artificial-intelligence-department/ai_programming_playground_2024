#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> array(N);

    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    auto zero = partition(array.begin(), array.end(), [](int i) { return i % 3 == 0; });
    auto one = partition(zero, array.end(), [](int i) { return i % 3 == 1; });

    sort(array.begin(), zero);                 
    sort(zero, one, greater<int>());           
    sort(one, array.end());                    

    auto end = unique(array.begin(), array.end());
    array.erase(end, array.end());
    
    cout << array.size() << endl;
    for (int x : array) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
