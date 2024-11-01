#include <iostream>

using namespace std;

int main() {
    long long a[5];
    cin >> a[0];
    if (a[0] <= 0) 
    {
        cout << "ERROR" << endl;
        return 0;
    }
    
    cin >> a[1];
    if (a[1] <= 0) 
    {
        cout << "ERROR" << endl;
        return 0;
    }
    if (a[1] > a[0]) 
    {
        cout << "LOSS" << endl;
        return 0;
    }

    cin >> a[2];
    if (a[2] <= 0) 
    {
        cout << "ERROR" << endl;
        return 0;
    }
    if (a[2] > a[1]) 
    {
        cout << "LOSS" << endl;
        return 0;
    }

    cin >> a[3];
    if (a[3] <= 0 ) 
    {
        cout << "ERROR" << endl;
        return 0;
    }
    if (a[3] > a[2]) 
    {
        cout << "LOSS" << endl;
        return 0;
    }

    cin >> a[4];
    if (a[4] <= 0 ) 
    {
        cout << "ERROR" << endl;
        return 0;
    }
    if (a[4] > a[3]) 
    {
        cout << "LOSS" << endl;
        return 0;
    }


    cout << "WIN" << endl;
    return 0;
}
