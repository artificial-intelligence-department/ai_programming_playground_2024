#include <iostream>

using namespace std;

int main(){
    int m, n;
    cin >> n >> m;

    if ((n * m) % 2 == 0){
        cout << "Dragon";
    }
    else{
        cout << "Imp";
    }
    return 0;
}