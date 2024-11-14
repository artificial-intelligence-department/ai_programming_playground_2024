#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double n, a;
    cin >> n;

    a = 1/(pow(2,n))+1/(pow(3,n));

    cout << setprecision(4) << fixed << "a= "<< a << endl;

}