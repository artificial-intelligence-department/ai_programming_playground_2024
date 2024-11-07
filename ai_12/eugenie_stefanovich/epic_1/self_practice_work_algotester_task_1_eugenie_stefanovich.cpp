#include <iostream>
#include <vector>
using namespace std;

int main() {
   
    int min, n ;
    long  max;
    cin >> n;
    min = 0;
    max = 0;
    vector<int>A(n);

    for(int i = 0;i < n ;i++)
        cin >>A[i] ;

    for(int i = 0;i < n ;i++)
        if(A[i]>0){
             min = A[i] - 1;
             max = max + min;
        }
    cout << max;


    return 0;
}

/* int n , sum , a;
    sum = 0;
    a = 0;
    cin >> n;
    
    

    for(int i = 0;i < n ;i++){
        cin >> a;
        sum = sum + a;
    }
    if( sum - n < 0)
        cout << 0;
    else
        cout<<(sum - n);*/
    