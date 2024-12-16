#include <iostream>

using namespace std;

int main() {
    long long  a1, a2, a3, a4, a5;
    cin >> a1;
    if (a1 <= 0) {
        cout << "ERROR" << endl;
        return 0; 
    }

    cin >> a2;
    if (a2 <= 0) {
        cout << "ERROR" << endl;
        return 0;  
    }
    if(a2>a1){
        cout<<"LOSS";
        return 0;
    }

    cin >> a3;
    if (a3 <= 0) {
        cout << "ERROR" << endl;
        return 0;  
    }
    if(a3>a2){
        cout<<"LOSS";
        return 0;
    }

    cin >> a4;
    if (a4 <= 0) {
        cout << "ERROR" << endl;
        return 0; 
    }
    if(a4>a3){
        cout<<"LOSS";
        return 0;
    }

    cin >> a5;
    if (a5 <= 0) {
        cout << "ERROR" << endl;
        return 0;
    }
    if(a5>a4){
        cout<<"LOSS";
        return 0;
    }
    cout << "WIN";
    return 0;
}