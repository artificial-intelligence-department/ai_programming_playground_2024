#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N, num;
    cin >> N;
    vector<int> vec;
    vector<int> vec0;
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] % 3 == 0)
        {
            vec0.push_back(vec[i]);
        }
        else if (vec[i] % 3 == 1)
        {
            vec1.push_back(vec[i]);
        }
        else if (vec[i] % 3 == 2)
        {
            vec2.push_back(vec[i]);
        }
    }
    sort(vec0.begin(), vec0.end());
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    reverse(vec1.begin(), vec1.end());
    vector<int> res;
    res.insert(res.end(), vec0.begin(), vec0.end());
    res.insert(res.end(), vec1.begin(), vec1.end());
    res.insert(res.end(), vec2.begin(), vec2.end());
    auto l = unique(res.begin(), res.end());
    res.erase(l, res.end());
    cout << res.size() << endl;
    for (int num : res)
    {
        cout << num << " ";
    }
}