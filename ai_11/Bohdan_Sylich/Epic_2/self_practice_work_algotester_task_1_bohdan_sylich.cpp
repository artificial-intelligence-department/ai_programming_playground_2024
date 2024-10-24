#include <iostream>

using namespace std;

int main(){
    int mar,sof,petr;
    cin >> mar >> sof >> petr;

    if (mar >= 1 && mar <= 1e9 && sof >= 1 && sof <= 1e9 && petr >= 1 && petr <= 1e9){
        if ((mar + sof) > petr){
            cout << "YES" << endl;
            return 0;
        }
        else {cout << "NO" << endl;
        return 0;}
    }
    else {return 1;}
}