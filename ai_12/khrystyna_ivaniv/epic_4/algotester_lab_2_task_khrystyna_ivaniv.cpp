#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int array[N];

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    int left = 0;
    int right = N - 1;

    for (int i = 0; i < N; i++)
    {

        if (left == right)
        {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Collision";
            break;
        }
        if (left + 1 == right)
        {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Stopped";
            break;
        }

        if (left > right)
        {
            cout << left + 1 << " " << right + 1 << endl;
            cout << "Miss";
            break;
        }
        left += array[left];
        right -= array[right];
    }

    return 0;
}