#include <iostream>
using namespace std;
int main() {
    long long arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        if (arr[i] <= 0)
        {
            cout << "ERROR";
            return 0;
        }
        if (i != 0)
        {
            if (arr [i - 1] < arr [i])
            {
                cout << "LOSS";
                return 0;
            }
        }
    }
    cout << "WIN";
     return 0;
}