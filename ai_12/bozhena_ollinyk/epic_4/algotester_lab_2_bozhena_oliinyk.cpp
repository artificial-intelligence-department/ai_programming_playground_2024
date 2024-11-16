
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N, m;
    cin >> N;

    if (N <= 2) {
        cout << 0;
        return 0;
    }

    int* r = new int[N]; 

    for (int i = 0; i < N; i++)
    {
        cin >> r[i];
    }

    int min = INT_MAX, max = INT_MIN;
    bool doubleMin = false, doubleMax = false;

    for (int i = 0; i < N; i++)
    {
        if (r[i] < min)
        {
            min = r[i];
            doubleMin = false;
        }
        else if (r[i] == min)
        {
            doubleMin = true;
        }

        if (r[i] > max)
        {
            max = r[i];
            doubleMax = false; 
        }
        else if (r[i] == max)
        {
            doubleMax = true; 
        }
    }

    int nextMin = INT_MAX, nextMax = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (r[i] > min && r[i] < nextMin)
        {
            nextMin = r[i];
        }
        if (r[i] < max && r[i] > nextMax)
        {
            nextMax = r[i];
        }
    }

    if (doubleMin)
    {
        nextMin = min;
    }
    if (doubleMax)
    {
        nextMax = max;
    }

    int diffMax = nextMax - min;
    int diffMin = max - nextMin;

    if (diffMin <= diffMax)
    {
        m = max - nextMin;
    }
    else
    {
        m = nextMax - min;
    }

    cout << m << endl;

    delete[] r; 
    return 0;
}
