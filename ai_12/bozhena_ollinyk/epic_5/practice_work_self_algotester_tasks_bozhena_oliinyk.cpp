#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int* numbers = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n);

    int* uniqueNumbers = new int[n];
    int newSize = 0;
    unordered_set<int> seen;

    for (int i = 0; i < n; i++)
    {
        if (seen.find(numbers[i]) == seen.end())
        {
            seen.insert(numbers[i]);
            uniqueNumbers[newSize++] = numbers[i];
        }
    }

    k %= newSize;
    int* rotatedNumbers = new int[newSize];
    for (int i = 0; i < newSize; i++)
    {
        rotatedNumbers[i] = uniqueNumbers[(i + k) % newSize];
    }

    cout << newSize << endl;
    for (int i = 0; i < newSize; i++)
    {
        cout << rotatedNumbers[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    delete[] uniqueNumbers;
    delete[] rotatedNumbers;

    return 0;
}
