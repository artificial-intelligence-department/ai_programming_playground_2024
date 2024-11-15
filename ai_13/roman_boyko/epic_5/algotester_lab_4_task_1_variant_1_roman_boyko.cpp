#include <iostream>
#include <algorithm>
using namespace std;
void differenceOf2Arrays(int arr1[], int arr2[], int size1, int size2);
void intersectionOf2Arrays(int arr1[], int arr2[], int size1, int size2);
bool isPresent(int arr[], int size, int elem);
void unionOf2Arrays(int arr1[], int arr2[], int size1, int size2);
void symmetricDifferenceOf2Arrays(int arr1[], int arr2[], int size1, int size2);
void removeDublicates(int arr[], int &size);
int main()
{
    int N, M;
    cin >> N;
    int arr1[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr1[i];
    }
    cin >> M;
    int arr2[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }

    removeDublicates(arr1, N);
    removeDublicates(arr2, M);
    differenceOf2Arrays(arr1, arr2, N, M);
    differenceOf2Arrays(arr2, arr1, M, N);
    intersectionOf2Arrays(arr1, arr2, N, M);
    unionOf2Arrays(arr1, arr2, N, M);
    symmetricDifferenceOf2Arrays(arr1, arr2, N, M);
}
void differenceOf2Arrays(int arr1[], int arr2[], int size1, int size2)
{
    int dif[size1];
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        bool find = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                find = true;
                break;
            }
        }
        if (!find)
        {
            dif[k] = arr1[i];
            k++;
        }
    }
    sort(dif, dif + k);
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << dif[i] << " ";
    }
    cout << "\n\n";
}
void intersectionOf2Arrays(int arr1[], int arr2[], int size1, int size2)
{
    int inters[size1];
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        bool find = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                find = true;
                break;
            }
        }
        if (find)
        {
            inters[k] = arr1[i];
            k++;
        }
    }
    sort(inters, inters + k);
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << inters[i] << " ";
    }
    cout << "\n\n";
}
bool isPresent(int arr[], int size, int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (elem == arr[i])
        {
            return true;
        }
    }
    return false;
}
void unionOf2Arrays(int arr1[], int arr2[], int size1, int size2)
{
    int uni[size1 + size2];
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        if (!isPresent(uni, k, arr1[i]))
        {
            uni[k] = arr1[i];
            k++;
        }
    }
    for (int i = 0; i < size2; i++)
    {
        if (!isPresent(uni, k, arr2[i]))
        {
            uni[k] = arr2[i];
            k++;
        }
    }
    sort(uni, uni + k);
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << uni[i] << " ";
    }
    cout << "\n\n";
}
void symmetricDifferenceOf2Arrays(int arr1[], int arr2[], int size1, int size2)
{
    int dif[size1 + size2];
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        bool find = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                find = true;
                break;
            }
        }
        if (!find)
        {
            dif[k] = arr1[i];
            k++;
        }
    }
    for (int i = 0; i < size2; i++)
    {
        bool find = false;
        for (int j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                find = true;
                break;
            }
        }
        if (!find)
        {
            dif[k] = arr2[i];
            k++;
        }
    }
    sort(dif, dif + k);
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << dif[i] << " ";
    }
    cout << "\n\n";
}
void removeDublicates(int arr[], int &size)
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