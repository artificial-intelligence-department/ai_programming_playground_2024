#include <iostream>
#include <algorithm>
using namespace std;
void deleteDublicates(int arr[], int &size);
void reversedArray(int arr[], int size, int index);
int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a, a + N);
    deleteDublicates(a, N);
    cout << N << endl;
    reversedArray(a, N, K);
}
void deleteDublicates(int arr[], int &size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            arr[k] = arr[i];
            k++;
        }
    }
    size = k;
}
void reversedArray(int arr[], int size, int index)
{
    int k = 0;
    int newArr[size];
    for (int i = index; i < size; i++)
    {
        newArr[k] = arr[i];
        k++;
    }
    for (int i = 0; i < index; i++)
    {
        newArr[k] = arr[i];
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        cout << newArr[i] << " ";
    }
}