#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    int count = 0;
    int min_value = INT_MAX;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int current;
        cin >> current;
        
        if (current <= min_value) {
            count++;
        }
        
        min_value = min(min_value, current);
    }
    
    cout << count << endl;
}
