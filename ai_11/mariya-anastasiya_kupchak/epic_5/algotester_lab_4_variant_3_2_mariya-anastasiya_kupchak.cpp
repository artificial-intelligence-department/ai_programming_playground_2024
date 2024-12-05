#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int low, int high, bool descending = false) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) 
        {
            if ((descending && arr[j] > pivot) || (!descending && arr[j] < pivot)) 
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1, descending);
        quickSort(arr, pi + 1, high, descending);
    }
}

void removeDuplicates(vector<int>& arr) 
{
    int n = arr.size();
    if (n == 0) return;

    vector<int> uniqueArr;
    uniqueArr.push_back(arr[0]);
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] != arr[i - 1]) 
        {
            uniqueArr.push_back(arr[i]);
        }
    }
    arr = uniqueArr;
}

int main() 
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    vector<int> mod0, mod1, mod2;
    for (int num : arr) 
    {
        if (num % 3 == 0)
        {
            mod0.push_back(num);
        }
        else if (num % 3 == 1)
        {
            mod1.push_back(num);
        }
        else
        {
            mod2.push_back(num);
        }
    }

    quickSort(mod0, 0, mod0.size() - 1);
    quickSort(mod1, 0, mod1.size() - 1, true);
    quickSort(mod2, 0, mod2.size() - 1);

    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    removeDuplicates(result);

    cout << result.size() << endl;
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
