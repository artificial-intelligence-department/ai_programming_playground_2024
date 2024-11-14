#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int num;
    vector<int> unique_El;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        unique_El.push_back(num);
    }
    sort(unique_El.begin(), unique_El.end());
    unique_El.erase(unique(unique_El.begin(), unique_El.end()), unique_El.end());
    int size = unique_El.size();
    if (size > 0)
    {
        K = K % size;
        rotate(unique_El.begin(), unique_El.begin() + K, unique_El.end());
    }
    cout << unique_El.size() << endl;
    for (int e : unique_El)
    {
        cout << e << " ";
    }
}
