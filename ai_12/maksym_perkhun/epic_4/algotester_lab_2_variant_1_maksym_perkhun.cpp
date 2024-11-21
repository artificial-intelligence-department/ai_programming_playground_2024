#include <iostream>
using namespace std;
int main(){
    int n, m1, m2;
    cin >> n;
    if(n == 1){
        cout << "0";
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    m1 = arr[n - 1] - arr[1];
    m2 = arr[n - 2] - arr[0];
    cout << min(m1, m2);
    return 0;
}