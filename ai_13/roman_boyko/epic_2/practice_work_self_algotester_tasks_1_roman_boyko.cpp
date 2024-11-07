#include <iostream>

using namespace std;

int main(){
    long long k, sum;
    cin>>k;
    int arr[k];
    for(int i = 0; i < k; i++){
        cin>>arr[i];
        if(arr[i]>0){
            sum+=arr[i]-1;
        }
    }
    cout<<sum<<endl;
}