#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    if ((n*m) % 2 == 0)
    {
        cout << "Dragon";
    }
    else{cout << "Imp";}
}


