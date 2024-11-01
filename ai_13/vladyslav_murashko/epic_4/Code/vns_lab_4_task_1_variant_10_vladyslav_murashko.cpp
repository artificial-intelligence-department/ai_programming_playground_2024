#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr(10);
    for (int &el : arr)
    {
        el = rand();
    }

    arr.erase(arr.begin(), arr.begin() + 5);

    for (int i = 0; i < 3; i++)
    {
        arr.push_back(rand());
    }
    
    for (int &el : arr)
    {
        cout << el << " ";
    }
}