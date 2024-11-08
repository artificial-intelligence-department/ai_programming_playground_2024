#include <iostream>
#include <algorithm>
using namespace std;

void dublicates(int *arr, int nums, int dubl)
{
    for (int i = 0; i < nums; i++)
    {
        for (int j = i + 1; j < nums; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " - " << arr[j] << endl;
                dubl++;
                for (int k = j; k < nums - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                break;
            }
            nums--;
            j--;
        }
    }
}

int main()
{
    int N, M, k = 0, l = 0, f = 0;
    cin >> N;
    int arr1[N];
    int *ptr1 = arr1;
    for (int i = 0; i < N; i++)
    {
        cin >> ptr1[i];
    }
    cin >> M;
    int arr2[M];
    int *ptr2 = arr2;
    for (int i = 0; i < M; i++)
    {
        cin >> ptr2[i];
    }

    int N1 = N;
    dublicates(ptr1, N1, f);

    int M1 = M;
    dublicates(ptr2, M1, f);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ptr1[i] == ptr2[j])
            {
                k += 1;
            }
        }
    }

    cout << endl;
    cout << k << endl;
    cout << N1 + M1 - k;
}