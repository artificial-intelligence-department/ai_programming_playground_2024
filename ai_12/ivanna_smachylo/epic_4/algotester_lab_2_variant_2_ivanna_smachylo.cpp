#include <iostream>

using namespace std;

void elemDelete(int*& arr, int& size, int k, int m, int f)
{
    int sizeNew = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] != k && arr[i] != m && arr[i] != f)
        {
            sizeNew++;
        }
    }

    int* arrNew = new int[sizeNew];
    int indexNew = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] != k && arr[i] != m && arr[i] != f)
        {
            arrNew[indexNew++] = arr[i];
        }
    }

    delete[] arr;
    arr = arrNew;
    size = sizeNew;
}

int* sumElem(const int* arr, int size)
{
    if(size <= 1) return nullptr;

    int* sumArr = new int[size - 1];
    for(int i = 1; i < size; i++)
    {
        sumArr[i - 1] = arr[i - 1] + arr[i];
    }
    return sumArr;
}

void arrayPrint(const int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int N;
    cin >> N;

    int* arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int k, m, f;
    cin >> k >> m >> f;

    elemDelete(arr, N, k, m, f);

    int* sumArr = sumElem(arr, N);

    if(sumArr == nullptr)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << N - 1 << "\n";
        arrayPrint(sumArr, N - 1);
        delete[] sumArr;
    }

    delete[] arr; 

    return 0;
}