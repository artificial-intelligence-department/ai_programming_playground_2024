#include <iostream>
#include <algorithm>
using namespace std;

void deleteElem(int arr[], int &n, int a, int b, int c);
void makeSum(int arr[], int newArr[], int n);

int main()
{
    int N, a, b, c;
    cin >> N;
    int arr[N];

    int *ptr = arr;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> a >> b >> c;
    deleteElem(arr, N, a, b, c);
    if (N <= 1)
    {
        cout << 0;
    }
    else
    {
        int newArr[N];
        makeSum(arr, newArr, N);
        cout << N - 1 << endl;
        for (int i = 0; i < N - 1; i++)
        {
            cout << newArr[i] << " ";
        }
    }
}

void deleteElem(int arr[], int &n, int a, int b, int c)
{
    int newn = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != a && arr[i] != b && arr[i] != c)
        {
            arr[newn++] = arr[i];
        }
    }
    n = newn;
}

void makeSum(int arr[], int newArr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        newArr[i] = arr[i] + arr[i + 1];
    }
}