#include <bits/stdc++.h>

using namespace std;

vector<int> CheckAscendingDescending(vector<int> IntArray, int NumRows)
{
    int count = 0;
    int temp = IntArray.size() - 1;
    for (int i = 0; i < temp; i++)
    {
        if (IntArray[i] > IntArray[i + 1])
        {
            count++;
        }
        else if (IntArray[i] < IntArray[i + 1])
        {
            count--;
        }
    }

    if(count == temp)
    {
        cout << "Row " << NumRows + 1 <<" in the array is sorted in the descending order" << endl;
    }
    else if(count == -temp)
    {
        cout << "Row " << NumRows + 1 <<" in the array is sorted in the ascending order" << endl;
    }
    else
    {
        sort(IntArray.begin(), IntArray.end());
        cout << "Row " << NumRows + 1 <<" in the array has been sorted" << endl;
    }

    return IntArray;
}

int main()
{
    int NumRows;
    int NumColumns;

    cout << "Enter the number of rows : ";
    cin >> NumRows;

    cout << "Enter the number of columns : ";
    cin >> NumColumns;

    vector<vector<int>> IntArray(NumRows, vector<int>(NumColumns, 0));

    cout << "Enter the elements of the array" << endl;

    for (int i = 0; i < NumRows; i++)
    {
        for (int j = 0; j < NumColumns; j++)
        {
            cin >> IntArray[i][j];
        }
    }

    for (int i = 0; i < NumRows; i++)
    {
        IntArray[i] = CheckAscendingDescending(IntArray[i], i);
    }

    for (int i = 0; i < NumRows; i++)
    {
        for (int j = 0; j < NumColumns; j++)
        {
            cout <<  IntArray[i][j];
        }
        cout << endl;
    }

    return 0;
}