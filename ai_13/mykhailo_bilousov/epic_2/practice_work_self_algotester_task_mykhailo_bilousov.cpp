// algotester archive 0182 https://algotester.com/en/ArchiveProblem/DisplayWithFile/20075
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_cool = 0, cool = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= k) {
            cool++;
            max_cool = (cool > max_cool) ? cool : max_cool;
        }
        else {
            cool = 0;
        }
    }
    cout << max_cool << endl;
}