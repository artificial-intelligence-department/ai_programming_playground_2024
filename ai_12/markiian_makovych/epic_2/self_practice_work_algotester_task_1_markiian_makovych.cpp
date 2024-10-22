#include <iostream>

using namespace std;

int main()
{
    int gift;
    cin >> gift;
    int num = 0;
    int arr[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

    for (int i = 8; i >= 0; i--)
    {
        if ((gift - arr[i]) > 0)
        {
            do
            {
                gift = gift - arr[i];
                num++;
            } while ((gift - arr[i]) >= 0);
        }
        else if ((gift - arr[i]) == 0)
        {
            gift = gift - arr[i];
            num++;
        };
    };

    cout << num << endl;
    return 0;
}
