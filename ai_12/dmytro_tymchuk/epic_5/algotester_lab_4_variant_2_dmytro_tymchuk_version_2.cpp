#include<iostream>
#include<vector>
using namespace std;

//Виведення масиву
void print_arr (vector<int>& arr)
{
    cout<<arr.size()<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}
//Виведення масиву

//Перестановка елементів з остачею 0 на початок
int duration_0(vector<int>& arr)
{
    int index = 0;
    int change;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 3 == 0)
        {
            change = arr[index];
            arr[index] = arr[i];
            arr[i] = change;

            index++;
        }
    }

    return index;
}
//Перестановка елементів з остачею 0 на початок

//Перестановка елементів  зостачею 1 в середину
int duration_1(vector<int>& arr, int begin_1)
{
    int index = begin_1;
    int change;
    for (int i = begin_1; i < arr.size(); i++)
    {
        if (arr[i] % 3 == 1)
        {
            change = arr[index];
            arr[index] = arr[i];
            arr[i] = change;

            index++;
        }
    }

    return index;
}
//Перестановка елементів  зостачею 1 в середину


//Швидке сортування
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
//Швидке сортування

//Швидке сортування по спаданню
void quick_sort_fall(vector<int>& arr, int first, int last)
{
    int middle = arr[(first + last) / 2];
    int left = first;
    int right = last;
    int change;

    while (left <= right)
    {
        while (arr[right] < middle) right--;
        
        while (arr[left] > middle) left++;

        if (left <= right)
        {
            change = arr[left];
            arr[left] = arr[right];
            arr[right] = change;
            left++;
            right--;
        }
    }
    if (right > first) quick_sort_fall(arr, first, right);
    if (left < last) quick_sort_fall(arr, left, last);
 }
//Швидке сортування по спаданню

//Видалення однакових елементів 
void erase_elements (vector<int>& arr, int& n)
{
    int i = 1;
    while (i < arr.size())
    {
        if (arr[i] == arr[i - 1])
        {
            arr.erase(arr.begin() + i);
            n--;
        }
        else i++;
    }
}
//Видалення однакових елементів 

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    quick_sort(arr, 0, n - 1);
    erase_elements(arr, n);

    int begin_1 = duration_0(arr);
    int begin_2 = duration_1(arr, begin_1);

    quick_sort(arr, 0, begin_1 - 1);
    quick_sort_fall(arr, begin_1, begin_2 - 1);
    quick_sort(arr, begin_2, n - 1);
    
    
    print_arr(arr);
    return 0;
}