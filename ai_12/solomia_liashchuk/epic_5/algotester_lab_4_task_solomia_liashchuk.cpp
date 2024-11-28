#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;

    vector<int> numbers(N);
    for(int i = 0; i < N; ++i) 
    {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    auto search = unique(numbers.begin(), numbers.end());
    numbers.erase(search, numbers.end());
    N = numbers.size();

    rotate(numbers.begin(), numbers.begin() + K % N, numbers.end());

    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}