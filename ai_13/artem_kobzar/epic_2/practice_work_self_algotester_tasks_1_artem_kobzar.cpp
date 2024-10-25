#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;  
    
    vector<int> prices(n);
    
   
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
   
    sort(prices.begin(), prices.end());
    
    int count = 0;  
    for (int i = 0; i < n; i++) {
        if (k >= prices[i]) {  
            k -= prices[i];    
            count++;           
        } else {
            break; 
        }
    }
    

    cout << count << endl;

    return 0;
} 