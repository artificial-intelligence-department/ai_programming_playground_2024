#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0; 
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp; 
    }

    cout << sum - n << endl; 
    return 0;
}
