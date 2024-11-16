#include<bits/stdc++.h>
using namespace std;

void remove_begin_end(int &n,int* arr){
    for(int i=0;i<n-2;i++){
        arr[i]=arr[i+1];
    }
    n-=2;
}
void print_arr(int n, int k, int* arr){
    k--;
    for(int i=0;i<n;i++){
        cout<<arr[(i+k)%n]<<" ";
    }
    cout<<endl;
}

void print_arr_reverse(int n, int k, int* arr){
    k--;
    for(int i=n;i>0;i--){
        cout<<arr[(i+k)%n]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    print_arr(n,k,arr);
    remove_begin_end(n,arr);
    print_arr_reverse(n,k,arr);
}