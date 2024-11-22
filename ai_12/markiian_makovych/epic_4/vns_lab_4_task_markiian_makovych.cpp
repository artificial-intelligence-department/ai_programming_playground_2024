#include <iostream>

using namespace std;

const int N = 100;
int arr[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int arrSize = 10;
int k = 3;

int main()
{
    int n = 0;
    cout << "Array rotated by (10-k) " << arrSize - k << " positions:\n";
    for (int i = 1; i <= arrSize; i++)
    {
        if (k + i >= arrSize)
        {

            cout << arr[n] << " ";
            n++;
        }
        else
        {
            cout << arr[k + i] << " ";
        }
    }
    cout << endl;
    int newFirst = 15;
    int newLast = 20;
    arrSize += 2;
    arr[arrSize - 1] = newLast;
    for (int i = arrSize - 2; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = newFirst;
    n = 1;
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = arr[i + n];
        n++;
    }
    n = 0;

    cout << "Array rotated by " << (arrSize / 2) - k << " positions and with odd numbers deleted:\n";
    for (int i = 1; i <= arrSize / 2; i++)
    {
        if (k + i >= arrSize / 2)
        {

            cout << arr[n] << " ";
            n++;
        }
        else
        {
            cout << arr[k + i] << " ";
        }
    }

    return 0;
}