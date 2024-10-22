#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    unsigned long long legs[4];
    bool FAIL = false;

    for (int i = 0; i < 4; i++){
        cin >> legs[i];
    }

    int n = sizeof(legs) / sizeof(legs[0]);

    for (int i = 0; i < 4; i++){
        unsigned long long cut;
        cin >> cut;
        if (cut > legs[i]){
            cout << "ERROR";
            return 0;
        }
        legs[i] -= cut;
        if (*max_element(legs, legs + n) >= legs[i] * 2){
            FAIL = true;
        }
    }   

    if (FAIL){
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}