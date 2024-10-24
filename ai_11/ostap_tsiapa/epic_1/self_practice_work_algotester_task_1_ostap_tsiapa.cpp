#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
int n;
cin >> n;
vector <int> a(n);
for (int i = 0; i < n; ++i) {
    cin >> a[i];
}

vector<int> b(n, 1);
for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j ) {
        if (a[i] > a[j] && b[i] < b[j] + 1) {
            b[i] = b[j] + 1;
        }
    }
} 

int maxb = *max_element(b.begin(), b.end());
cout << maxb << endl;

}