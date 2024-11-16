#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    sort(array.begin(), array.end());
    auto last = unique(array.begin(), array.end());
    array.erase(last, array.end());
    N = array.size();

    rotate(array.begin(), array.begin() + K % N, array.end());

    cout << N << endl;
    
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
