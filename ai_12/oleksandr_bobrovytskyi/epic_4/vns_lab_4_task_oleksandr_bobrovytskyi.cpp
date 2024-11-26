#include<bits/stdc++.h>

using namespace std;

int main()
{
    int temp = 0;
    int NumberOfElements = rand() % 101;
    vector<int> IntArray(NumberOfElements);

    for(int i = 0; i < NumberOfElements; i++)
    {
        temp = rand() % 101;
        IntArray[i] = temp;
    } 

    cout << "Array before changes : " << endl;

    for(int i = 0; i < NumberOfElements; i++)
    {
        cout << IntArray[i] << " ";
    }

    IntArray.resize(NumberOfElements - 5);

    cout << endl;

    for(int i = 0; i < 3; i++)
    {
        IntArray.insert(IntArray.begin(), (IntArray[i + 1] + 2));
    }

    cout << "\nArray after changes : " << endl;

    for(int i = 0; i < IntArray.size(); i++)
    {
        cout << IntArray[i] << " ";
    }

    return 0;
}