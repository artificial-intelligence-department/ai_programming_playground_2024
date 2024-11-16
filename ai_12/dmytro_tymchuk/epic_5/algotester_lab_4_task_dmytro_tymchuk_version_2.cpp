#include<iostream>
#include<vector>
using namespace std;

//швидке сортування
void quick_sort(vector<int>& arr, int first, int last)
{
    int middle = arr[(first + last) / 2];
    int left = first;
    int right = last;
    int change;

    while (left <= right)
    {
        while (arr[right] > middle) right--;
        
        while (arr[left] < middle) left++;

        if (left <= right)
        {
            change = arr[left];
            arr[left] = arr[right];
            arr[right] = change;
            left++;
            right--;
        }
    }
    if (right > first) quick_sort(arr, first, right);
    if (left < last) quick_sort(arr, left, last);
}
//швидке сортування

//видалення однакових елементів 
void erase_elements (vector<int>& arr)
{
    int i = 1;
    while (i < arr.size())
    {
        if (arr[i] == arr[i - 1])
        {
            arr.erase(arr.begin() + i);
        }
        else i++;
    }
}
//видалення однакових елементів 

void arr_transformation(vector<int>& arr, vector<int>& new_arr, int k)
{
    int i = k;
    int size = 0;

    while (size < arr.size())
    {
        if (i < arr.size())
        {
            new_arr[size] = arr[i];
            i++;
            size++;
        }
        else i = 0;
    }
}


int main()
{
    int n, k;
    
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    quick_sort(arr, 0, arr.size() - 1);
    erase_elements(arr);
    vector<int> new_arr(arr.size());

    arr_transformation(arr, new_arr, k % arr.size());

    cout<<new_arr.size()<<endl;
    for (int i = 0; i < new_arr.size(); i++)
    {
        cout<<new_arr[i]<<" ";
    }
    
    return 0;
}