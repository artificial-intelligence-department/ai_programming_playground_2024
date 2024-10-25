#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;

    cout << "Write n: " << "\n";
    cin >> n;
    cout << "Write m: " << "\n";
    cin >> m;

    int multiplication = ++n * ++m;
    cout << multiplication << "\n";

    if (m++ < n)
    {
        cout << "Yes, m is less than n" << "\n";
    }
    else
    {
        cout << "No, m is not less than n" << "\n";
    }

    if (n++ > m)
    {
        cout << "Yes, n is more than m" << "\n";
    }
    else
    {
        cout << "No, n is not more than m" << "\n";
    }

    return 0;
}