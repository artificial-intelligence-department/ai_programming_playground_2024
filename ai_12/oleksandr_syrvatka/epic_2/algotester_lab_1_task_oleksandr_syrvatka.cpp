#include <iostream>

using namespace std;

int main (){
    long long cubes[5];

    for(int i = 0; i<5; i++){
        cin >> cubes[i];
        if (cubes[i] <= 0 ){
            cout << "ERROR";
            return 0;
        }
    }

    for (int i = 1; i<5; i++){
        if (cubes[i - 1] < cubes[i] ){
            cout << "LOSS";
            return 0;
        }

    }
    cout <<"WIN";
    return 0;
}   