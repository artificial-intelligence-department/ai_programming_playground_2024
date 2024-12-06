// var 13
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    
    cout << "Enter number of fractional numbers ";
    cin >> n;

    double s=0;
    double a[n];
    cout << "Enter fractional numbers \n";
    
    for (int i = 0; i<n; i++)
    {
        cin >> a[i];
        s+=a[i];
    }
 
    cout << "arithmetic mean = " << (s / n);
    return 0;
}