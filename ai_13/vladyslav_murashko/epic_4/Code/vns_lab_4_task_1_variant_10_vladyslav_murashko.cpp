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

    cout << "\nInitial array: \n\n";
    for (int &el : arr)
    {
        cout << el << " ";
    }

    arr.erase(arr.begin(), arr.begin() + 5);

    for (int i = 0; i < 3; i++)
    {
        arr.push_back(rand());
    }
    
    cout << "\n\nResulting array: \n\n";
    for (int &el : arr)
    {
        cout << el << " ";
    }
    cout << "\n\n";
    return 0;
}