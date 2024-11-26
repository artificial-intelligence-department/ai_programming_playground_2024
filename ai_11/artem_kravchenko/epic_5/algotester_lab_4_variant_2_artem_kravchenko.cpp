#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (find(a.begin(), a.end(), x) == a.end())
        {
            a.push_back(x);
        }
        
    }
    sort(a.begin(), a.end());

    K %= a.size();
    rotate(a.begin(), a.begin() + K, a.end());

    cout << a.size() << endl;
    for ( int i : a)
    {
        cout << i << " ";
    }
    
    
    return 0;
}