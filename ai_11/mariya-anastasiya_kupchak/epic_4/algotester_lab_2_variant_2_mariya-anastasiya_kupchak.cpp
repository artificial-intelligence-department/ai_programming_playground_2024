#include <iostream>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    int *r = new int[N];
    for (int i = 0; i < N; ++i) 
    {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    int Nnew = 0;
    for (int i = 0; i < N; ++i) 
    {
        if (r[i] != a && r[i] != b && r[i] != c) 
        {
            r[Nnew] = r[i];
            Nnew++;
        }
    }

    int *sumr = new int[N];
    int num_sumr = 0;
    for (int i = 0; i < Nnew - 1; ++i) 
    {
        sumr[i] = r[i] + r[i + 1];
        num_sumr++;
    }

    cout << num_sumr << endl;
    for (int i = 0; i < Nnew - 1; ++i) 
    {
        cout << sumr[i] << " ";
    }
    cout << endl;

    delete r;
    r = 0;
    delete sumr;
    sumr = 0;

    return 0;

}