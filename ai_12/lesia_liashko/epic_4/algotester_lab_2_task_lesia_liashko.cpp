#include <iostream>
#include <climits>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    int r[100000]; 
    for (int i = 0; i < N; i++) 
    {
        cin >> r[i];
    }

    if (N == 1) 
    {
        cout << 0 << endl;
        return 0;
    }

    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN;

    for (int i = 0; i < N; i++) 
    {
        if (r[i] < min1) 
        {
            min2 = min1;
            min1 = r[i];
        } 
        else if (r[i] < min2)
        {
            min2 = r[i];
        }

        if (r[i] > max1) 
        {
            max2 = max1;
            max1 = r[i];
        } 
        else if (r[i] > max2) 
        {
            max2 = r[i];
        }
    }

    int option1 = max1 - min2;
    int option2 = max2 - min1;
    int m = min(option1, option2);

    cout << m << endl;

    return 0;
}
