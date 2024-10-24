#include <iostream>
using namespace std;

int main()
{
    long long a1,a2,a3,a4,a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    long long A[5] = {a1,a2,a3,a4,a5};

    bool lose = false;
    bool win = true;
    
    for (int i = 1; i < 5; ++i){
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

    else if (win)
    {
        cout << "WIN";
        return 0;
    }
    
    return 0;
}