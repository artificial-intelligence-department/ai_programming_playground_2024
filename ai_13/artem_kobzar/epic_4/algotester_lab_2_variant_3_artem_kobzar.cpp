#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout<<"Enter the amount of elements in array: ";
    cin>>n;
    vector<int>arr(n+1);
    cout<<"Enter elements in array: ";
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    int left_drone = 1;
    int right_drone = n;

    while (true)
    {
        if (left_drone == right_drone)
        {
            cout << left_drone<< " " << right_drone<< endl;
            cout << "Collision" << endl;
            break;
        }

        if (left_drone > right_drone)
        {
            cout << left_drone << " " << right_drone << endl;
            cout << "Miss" << endl;
            break;
        }

        if (left_drone == right_drone - 1)
        {
            cout << left_drone<< " " << right_drone << endl;
            cout << "Stopped" << endl;
            break;
        }
        left_drone = left_drone + arr[left_drone];
        right_drone = right_drone - arr[right_drone];

    }

    return 0;
}