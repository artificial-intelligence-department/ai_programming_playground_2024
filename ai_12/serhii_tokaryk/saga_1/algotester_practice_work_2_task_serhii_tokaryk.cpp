#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int girls_count = 0;

    for (int i = 0; i < n && girls_count < k; i++) {
        int cost_for_two_tickets = 2 * a[i];  
        if (z >= cost_for_two_tickets) {
            z -= cost_for_two_tickets;
            girls_count++;
        } else {
            break; 
        }
    }

    cout << girls_count << endl;

    return 0;
}
