#include <iostream>
#include <cmath> // для sqrt

using namespace std;

int main(){
    int n;
    double r;
    cin >> n >> r;

    double result = r/ sqrt(n);

    cout << result << endl;
    return 0;

}