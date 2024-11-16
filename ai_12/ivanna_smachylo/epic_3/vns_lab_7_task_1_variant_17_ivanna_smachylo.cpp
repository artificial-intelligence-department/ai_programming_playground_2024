#include <iostream>
#include <string>

using namespace std;

int average(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

int main()
{
    int intArr[] = {1, 2, 3, 4, 5};

    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Average of int array: " << average(intArr, intSize) << "\n";

    return 0;
}
