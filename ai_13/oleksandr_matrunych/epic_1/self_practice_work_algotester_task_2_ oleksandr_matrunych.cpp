#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<pair<int, int>> lengths(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lengths[i].first;
        lengths[i].second = i + 1;  
    }
    
    sort(lengths.begin(), lengths.end());
    int x = 1;
    for (int i = 0; i < n;  i++, x++) {
        cout << "The company number " << x <<" is " << lengths[i].second << " one\n";
    }
    
    return 0;
}
