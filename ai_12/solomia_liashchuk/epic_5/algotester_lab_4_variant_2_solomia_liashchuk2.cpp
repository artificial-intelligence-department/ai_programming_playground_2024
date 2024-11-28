#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& arr) //сортування вставками
{
    int N = arr.size();
     for(int i = 1; i < N; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

vector<int> removeDuplicates(vector<int>& arr) //видалення дублікатів
{
    vector<int> uniqueArr;
    for(int i = 0; i < arr.size(); i++)
    {
        if(i == 0 || arr[i] != arr[i - 1])
        {
            uniqueArr.push_back(arr[i]);
        }
    }
    return uniqueArr;
}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr);
    arr = removeDuplicates(arr);

    vector<int> mod0, mod1, mod2;
    for(int x : arr)
    {
        if(x % 3 == 0)
        {
            mod0.push_back(x);
        }
        else if(x % 3 == 1)
        {
            mod1.push_back(x);
        }
        else
        {
            mod2.push_back(x);
        }
    }

    insertionSort(mod0); 
    insertionSort(mod1); 
    insertionSort(mod2); 

    for(int i = 0; i < mod1.size() / 2; i++)
    {
        int temp = mod1[i];
        mod1[i] = mod1[mod1.size() - 1 - i];
        mod1[mod1.size() - 1 - i] = temp;
    }

    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    cout << result.size() << endl;
    for (int i : result)
    {
        cout << i << " ";
    }
    
    return 0;
}