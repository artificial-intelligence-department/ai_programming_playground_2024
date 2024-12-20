// Факторіал
#include <iostream>
using namespace std;

int CountZeros(long long n)
{
    int count = 0;
    
    while (n >= 5) 
    {
        n /= 5; 
        count += n;
    }
    
    return count;
}

int main()
{
    long long n;
    cin >> n;
    cout << CountZeros(n) << endl;

    return 0;
}
