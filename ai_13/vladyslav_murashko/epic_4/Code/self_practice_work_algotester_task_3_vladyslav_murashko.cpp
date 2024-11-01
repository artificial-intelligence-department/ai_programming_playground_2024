#include <iostream>
#include <vector>
using namespace std;

// lab 3v2
int main()
{
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (auto &el : arr1)
    {
        cin >> el;
    }

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (auto &el : arr2)
    {
        cin >> el;
    }

    int repeatCount = 0;

    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < n2; j++)
        {
            if(arr1[i]==arr2[j]){
                repeatCount++;
                break;
            }
        }
    }

    cout << repeatCount << endl << n1+n2-repeatCount;

    return 0;
}