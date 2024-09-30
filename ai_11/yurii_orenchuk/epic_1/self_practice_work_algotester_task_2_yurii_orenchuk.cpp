#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int grid = n * m;
    if (grid % 2 == 0){
        cout << "Dragon";
    }
    else{
        cout << "Imp";
    }

    return 0;
}