#include <iostream>
#include <bits/stdc++.h> // для операції max_element
using namespace std;

int main() {
    long long h[4], d[4], minh=10e13, maxh=-1;
    bool error=0, no=0;
    
    for(int i=0; i<4; i++) {
        cin >> h[i];
        maxh = max(maxh, h[i]);
        minh = min(minh, h[i]);
    }
    
    for(int i=0; i<4; i++) {
        cin >> d[i];
        if(d[i]>h[i]) {
            error=1;
        }
    }


    for(int i=0; i<4; i++) {
        h[i] = h[i] - d[i];
        maxh = *max_element (h, h+4);
        minh = *min_element (h, h+4);
        if(maxh >= minh*2) {
            no=1;
        }
    }

    if(error){
        cout << "ERROR";
    } else {
        if(no || (!( h[0]==h[1] && h[1]==h[2] && h[2]==h[3] ))){
            cout << "NO";
        } else {cout << "YES";}
    }

    return 0;
}