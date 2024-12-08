#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cash[]={500,200,100,50,20,10,5,2,1};
    int count=0;
    for(int i=0; i<9; i++){
        count += n / cash[i];
        n %= cash[i];
    }
    cout << count;
    return 0;
}

