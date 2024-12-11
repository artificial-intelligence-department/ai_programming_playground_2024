#include<iostream>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    if(N < 1 || N > 100 || M < 1 || M > 100)
    {
        return 1;
    }

    if((N * M) % 2 == 0)
    {
        cout << "Dragon";
    }
    else
    {
        cout << "Imp";
    }

    return 0;
}