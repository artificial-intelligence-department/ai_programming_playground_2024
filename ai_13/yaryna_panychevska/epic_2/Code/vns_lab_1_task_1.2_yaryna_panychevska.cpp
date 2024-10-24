#include <iostream>
using namespace std;
int main()
{
    int n;
    int m;
    cout << "Enter numbers for n and m: " << endl;
    cin >> n >> m;
    int n1 = n++;
    int STEP1 = n1 * m;
    int STEP2 = n1 < m;

    int m1 = m--;
    int STEP3 = m1 > m;

    cout << "current n is " << n1 << " and current m is " << m1 << ", so n * m will be " << STEP1 << endl;
    cout << "current n is " << n << " and current m is " << m1 << ", so n < m will be " << STEP2 << endl;
    cout << "current m is " << m1 << " and current m is " << m << ", so m > m will be " << STEP3 << endl;
    return 0;
}