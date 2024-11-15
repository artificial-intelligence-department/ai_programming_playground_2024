#include <iostream>
using namespace std;


int main(){

    int n,i,k,m,t,r;
    char c;
    i=0;
    k = 0;
    m = 0;
    t = 0;
    r = 0;
    cin >> n;
    char per[n];
    while(true){
        
        cin >> c;
        if(c == 'V'){
            ++m;
            per[i] = c;
        }
        if(c == 'K'){
            ++k;
            per[i] = c;
        }
        if(k>= 11 && k>m+1){
            ++t;
            k = 0;
            m = 0;
        }
        if(m>= 11 && m>k+1){
            ++r;
            k = 0;
            m = 0;
        }
        if (i == n-1){
            break;
        }
        ++i;
        }
        
       
    cout << t <<":"<< r <<endl;
    if(k>0 || m>0){
        cout << k<<":"<<m;
    }

    return 0;
}
