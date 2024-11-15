#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int left_drone = 0;
    int right_drone = n - 1;

    while (true)
    {
        if (left_drone == right_drone)
        {
            cout << left_drone + 1 << " " << right_drone + 1 << endl;
            cout << "Collision" << endl;
            break;
        }

        if (left_drone > right_drone)
        {
            cout << left_drone + 1 << " " << right_drone + 1 << endl;
            cout << "Miss" << endl;
            break;
        }

        if (left_drone == right_drone - 1)
        {
            cout << left_drone + 1 << " " << right_drone + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }
        left_drone = left_drone + a[left_drone];
        right_drone = right_drone - a[right_drone];

    }

    return 0;
}