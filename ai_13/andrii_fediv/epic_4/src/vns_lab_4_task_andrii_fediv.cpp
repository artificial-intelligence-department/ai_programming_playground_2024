#include <iostream>
#include <sstream>
using namespace std;

void fromK(int arr[], int s[2], int c, bool direction)
{
    int k = c - 1;
    cout << "\nfrom " << k << (direction ? " in left <-- : " : " in right --> : ");
    for (size_t i = 0; i <= s[1] - s[0] ; i++)
    {
        int id = k % (s[1] - s[0] + 1) + s[0];
        if (id < s[0])
            id += (s[1] - s[0] + 1);

        cout << arr[id] << " ";
        direction ? k-- : k++;
    }
}

int main()
{
    int n, N = 100, arr[N];
    bool invalid = true;
    while (invalid)
    {
        cout << "Enter your array length: ";
        cin >> n;
        if (n > N || n <= 0)
        cout:
            "error, please try again";
        else
        {
            invalid = false;
            for (size_t i = 0; i < n; i++)
                cin >> arr[i];
        }
    } 
    int l, sizes[2] = {0, n - 1};
    cout << "Where you wanna start? ";
    cin >> l;
    fromK(arr, sizes, l, true);
    sizes[0] += 1;
    sizes[1] -= 1;
    fromK(arr, sizes, l, false);

    return 0;
}