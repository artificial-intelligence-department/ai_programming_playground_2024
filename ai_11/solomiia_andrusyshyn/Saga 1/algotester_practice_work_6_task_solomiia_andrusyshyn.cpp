#include <iostream>
#include <cmath> 
#include <iomanip> 
using namespace std;

int main() 
{
    int n;
    double r; 

    cin >> n >> r;

    if (n < 1 || n > 100 || r < 1 || r > 100) {
        cout << "Error" << endl;
        return 0;
    }

    double r_n = r / sqrt(n);

    cout << fixed << setprecision(4) << r_n << endl;

    return 0;
}

