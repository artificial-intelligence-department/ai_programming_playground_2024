#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int x;
    cin >> x;

    vector<bool> isPrime(x + 1, true);

    for (int i = 2; i*i <= x; i++)
    {
        if(isPrime[i])
        {
            for (int j = i*i; j <= x; j += i)
            {
                isPrime[j] = false;
            }
        }
        
    }

    for(int i = 2; i <= x; i++)
    {
        if(isPrime[i])
        {
            printf("[%d] ", i);
        }
    }

    return 0;
}
