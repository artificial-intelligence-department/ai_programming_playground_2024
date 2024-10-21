#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    int size = n*m;
    if (size%2 == 0){
        cout << "Dragon"; 
    } 
    else{
        cout << "Imp"; 
    }
    return 0;
}