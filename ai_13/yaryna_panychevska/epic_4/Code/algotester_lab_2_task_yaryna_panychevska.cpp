#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size_arr;
    cin >> size_arr; 

    vector<int> arr(size_arr);
    for (int i = 0; i < size_arr; i++)
    {
        cin >> arr[i]; 
    }

    int a, b, c; 
    cin >> a >> b >> c;

  arr.erase(remove(arr.begin(), arr.end(), a), arr.end());
  arr.erase(remove(arr.begin(), arr.end(), b), arr.end());
  arr.erase(remove(arr.begin(), arr.end(), c), arr.end());
  
    vector<int> new_arr;
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        new_arr.push_back(arr[i] + arr[i + 1]);
    }

    cout << new_arr.size() << endl;

    for (int val : new_arr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
