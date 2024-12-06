#include <iostream>
#include <cmath>
#include<vector>
#include<algorithm>
using namespace std; 

int findMedian(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int A = findMedian(a);
    int B = findMedian(b);
    int C = findMedian(c);

    int untruth = 0;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        untruth += abs(A - a[i]) + abs(B - b[i]) + abs(C - c[i]);
    }
    
    cout << untruth;
    return 0;
}
