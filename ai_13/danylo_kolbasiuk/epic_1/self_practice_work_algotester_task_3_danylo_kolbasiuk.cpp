#include <iostream>

using namespace std;

int main()
{
    int n, temp1;
    cin >> n;
    int* a= new int[n];
    for (int i=0; i<n; i++) {
        cin >> temp1;
        a[i] = temp1;
    }
    for (int i=0; i<n-1; i++) {
        if (((a[i+1])-(a[i]))<2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}