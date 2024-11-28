#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
    return;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int low = 0;
    int high = arr.size() - 1;

    mergeSort(arr, low, high);
    vector<int> uniqueArr;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            uniqueArr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < K; i++)
    {
        uniqueArr.push_back(uniqueArr[0]);
        uniqueArr.erase(uniqueArr.begin());
    }
    cout << uniqueArr.size() << endl;
    for (int i = 0; i < uniqueArr.size(); i++)
    {
        if (i == uniqueArr.size() - 1)
        {
            cout << uniqueArr[i];
            break;
        }
        cout << uniqueArr[i] << " ";
    }

    return 0;
}