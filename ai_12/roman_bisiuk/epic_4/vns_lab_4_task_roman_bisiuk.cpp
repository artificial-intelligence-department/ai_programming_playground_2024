#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printFromK(const vector<int>& arr, int k, bool forward)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int index = forward ? (k + i) % n : (n + k - i) % n; 
        cout << arr[index] << " ";
    }
    cout << endl;
}

void deleteMax(vector<int>& arr)
{
    int maxEl = *max_element(arr.begin(), arr.end());
    arr.erase(remove(arr.begin(), arr.end(), maxEl), arr.end());
}

int main()
{
    vector<int> elements = {3, 5, 1, 5, 3, 4, 5, 9}; 
    int k = 2; 

    cout << "Елементи від k-го вліво:\n";
    printFromK(elements, k, false); 

    deleteMax(elements); 

    cout << "Елементи від k-го вправо:\n";
    printFromK(elements, k, true); 

    return 0;
}
