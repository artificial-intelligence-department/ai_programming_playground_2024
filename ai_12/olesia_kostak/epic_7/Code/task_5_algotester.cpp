#include <iostream>
using namespace std;

int main()
{

    long long A[5];
    for(int i = 0; i < 5; i++)
        std::cin >> A[i];

    bool lose = false;
    bool win = true;
    
    for (int i = 1; i < 5; i++)
    {
        if (A[i] <= 0 )
        {
            cout << "ERROR";
            return 0;
        }
        if(A[i-1] < A[i])
        {
            lose = true;
            break;
        }

        else if (A[i-1] < A[i])
        {
            win = false;
            break;
        }
    }

    

    if(lose)
    {
        cout << "LOSS";
        return 0;
    }

    cout << "WIN";
    return 0;
}

