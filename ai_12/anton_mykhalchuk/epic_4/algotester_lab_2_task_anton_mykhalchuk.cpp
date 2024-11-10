#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int indexLeft = 0, indexRight = n - 1;

    while (true)
    {
        if (indexRight - indexLeft == 1)
        {
            cout << indexLeft + 1 << ' ' << indexRight + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }
        else if (indexRight - indexLeft == 0)
        {
            cout << indexLeft + 1 << ' ' << indexRight + 1 << endl;
            cout << "Collision" << endl;
            break;
        }
        else if (indexLeft > indexRight)
        {
            cout << indexLeft + 1 << ' ' << indexRight + 1 << endl;
            cout << "Miss" << endl;
            break;
        }

        indexLeft += numbers[indexLeft];
        indexRight -= numbers[indexRight];
    }

    return 0;
}