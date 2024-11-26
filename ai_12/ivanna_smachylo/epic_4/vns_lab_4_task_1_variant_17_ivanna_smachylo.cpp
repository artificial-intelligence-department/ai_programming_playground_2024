#include <iostream>
#include <vector>

using namespace std;

//Додавання першого й останнього елемента
void firstAndLast(vector<int>& arr)
{
    if(!arr.empty())
    {
        arr.insert(arr.begin(), arr.back());
        arr.push_back(arr[1]);
    }
}

//Виводимо масив від k елемента проти годинникової сттрілки до k-1
void counter1(const vector<int>& arr, int k)
{
    int n = arr.size();
    int index = k % n;
    cout << "Counterclockwise from index " << k << ": ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[index] << " ";
        index = (index - 1 + n) % n;
    }
    cout << "\n";
}

//Виводимо масив від k елемента за годинниковою стрілкою до k+1
void counter2(const vector<int>& arr, int k)
{
    int n = arr.size();
    int index = k % n;
    cout << "Clockwise from index " << k << ": ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[index] << " ";
        index = (index + 1) % n;
    }
    cout << "\n";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Initial array: ";

    for(int elem : arr)
    {
        cout << elem << " ";
    }
    cout << "\n";

    int K;
    cout << "Enter initial index K: ";
    cin >> K;

    //Додаємо перший і останній елементи
    firstAndLast(arr);
    cout << "Array after adding first and last elements: ";

    for(int elem : arr)
    {
        cout << elem << " ";
    }
    cout << "\n";

    counter1(arr, K);
    counter2(arr, K);

    return 0;
}