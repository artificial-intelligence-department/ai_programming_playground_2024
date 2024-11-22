#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <algorithm> 
using namespace std;

int main()
{
    srand(time(0)); 

    int n = 5;
    vector<int> arr(n);


    for (int& num : arr)
    {
        num = rand() % 11 - 5;
    }


    cout << "Start masssive : ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;


    arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());

    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i] % 2 == 0) 
        { 
            arr.insert(arr.begin() + i + 1, arr[i - 1] + 2); 
            break;  
        }
    }

    cout << "New massive ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;





    return 0;
}











