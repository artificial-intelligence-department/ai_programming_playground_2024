#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    int a[N];
    for (int i; i<N; i++)
    {
        cin >> a[i];
    }

    sort(a, a + N);
    auto last = unique(a, a + N);
    int size = last - a;
    std::rotate(a, a + K%size, a + size);
    cout << size << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << a[i] << " ";
    }
}