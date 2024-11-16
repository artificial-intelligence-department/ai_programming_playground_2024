#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 101;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int k;
    cout << "\nEnter index of element to remove: ";
    cin >> k;
    if (k >= 0 && k <= n)
    {
        for (int i = k; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int newArr[n * 2];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        newArr[l] = arr[i];
        l += 1;
        if (arr[i] % 2 == 0)
        {
            newArr[l++] = 0;
        }
    }
    cout << "New array is\n";
    for (int i = 0; i < l; i++)
    {
        cout << newArr[i] << " ";
    }
}