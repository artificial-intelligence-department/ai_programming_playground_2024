#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; 
    cin >> n;

    if (n < 1 || n > 100000) 
    {
        cout << "Error" << endl;
        return 1;
    }

    vector<long long> a(n); 
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];

        if (a[i] < 0 || a[i] > 1000000000) 
        {
            cout << "Error" << endl;
            return 1;
        }
    }

    long long max_eaten = 0; 
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            max_eaten += a[i] - 1; 
        }
    }

    cout << max_eaten << endl;
    return 0;
}
