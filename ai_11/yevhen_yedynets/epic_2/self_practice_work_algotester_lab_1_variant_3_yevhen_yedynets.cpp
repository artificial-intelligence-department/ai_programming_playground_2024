#include<iostream>

using namespace std;

int main(){
    long long p, c;

    cin >> p;
    if (p <= 0) {
        cout << "ERROR";
        return 0;
    }

    for (short i=0; i<4; i++){
        cin >> c;
        if (c <= 0){
            cout << "ERROR";
            return 0;
        }
        if (p < c){
            cout << "LOSS";
            return 0;
        }
        p = c;
    }

    cout << "WIN";

    return 0;
}