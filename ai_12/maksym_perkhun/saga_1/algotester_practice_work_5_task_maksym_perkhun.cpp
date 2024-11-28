//lab2_v3
#include<iostream>
#include <iostream>
using namespace std;
int main() {
    int n, l = 0, r;
    cin >> n;
    r = n - 1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while(l + 1 < r)
    {
        l+=arr[l];
        r-=arr[r];
    }
    cout << l + 1 << " " << r + 1 << endl;
    if (l == r)
    {
        cout << "Collision";
    }
    else if (l > r)
    {
        cout << "Miss";
    }
    else 
    {
        cout << "Stopped";
    }
     return 0;
}





