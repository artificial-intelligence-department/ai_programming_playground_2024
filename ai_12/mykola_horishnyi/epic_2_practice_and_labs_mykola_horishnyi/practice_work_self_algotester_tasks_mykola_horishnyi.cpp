#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter matrix size (first n, m): ";
    cin >> n >> m;

    unordered_map<int, int> freg;
    cout << "Enter elements of matrix ( " << m << " elements in every " << n << " rows): " << endl;


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int num;
            cin >> num;
            freg[num]++; 
        }
    }

 
    vector<int> result;

    for (const auto& entry : freg)
    {
        if (entry.second == 2)
        {
            result.push_back(entry.first);  
        }
    }


    cout << "How many numbers have pairs: " << result.size() << endl;
    cout << "Full numbers: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
