#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int min_zenuk,max_marichka;
int arr[n];
int arr1[m];

for(int i = 0;i<n;i++){
    cin>>arr[i];
}

for(int i = 0;i<m;i++){
    cin>>arr1[i];
}

sort(arr, arr + n);
sort(arr1, arr1 + m);

cout<<arr[0]+arr1[0];

return 0;
}