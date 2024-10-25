#include <iostream>

using namespace std;

bool GameEnd(long long int x, long long int y)
{
    if (y <= 0 && y >= -10e11 && y <= 10e11)
    {
        cout << "ERROR";
        return 0;
    }
    else if (x < y)
    {
        cout << "LOSS";
        return 0;
    }

    return 1;
}

int main()
{
    long long int a,b,c,d,e = 0;
    cin >> a;
    if (!(GameEnd(a, a)))
    {
        return 0;
    }

    cin >> b;
    if (!(GameEnd(a, b)))
    {
        return 0;
    }

    cin >> c;
    if (!(GameEnd(b, c)))
    {
        return 0;
    }
    
    cin >> d;
    if (!(GameEnd(c, d)))
    {
        return 0;
    }

    cin >> e;
    if (!(GameEnd(d, e)))
    {
        return 0;
    }

    cout << "WIN";

    return 0;
}