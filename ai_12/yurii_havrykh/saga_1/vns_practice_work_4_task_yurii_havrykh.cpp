#include<bits/stdc++.h>

using namespace std;

int main() {
    int number;
    long long factorial=1;
    cout<<"Number:";
    cin>>number;
    for(int i=2;i<=number;i++){
        factorial*=i;
    }
    cout<<number<<"!= "<<factorial;
}