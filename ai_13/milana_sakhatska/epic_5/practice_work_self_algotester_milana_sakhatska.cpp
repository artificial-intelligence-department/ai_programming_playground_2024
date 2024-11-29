#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<string, int> word_count;
    set<char> char_set;
    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_count[word]++;
    }

    for (const auto& entry : word_count) 
    {
        if (entry.second >= k) 
        {
            char_set.insert(entry.first.begin(), entry.first.end());
        }
    }

    vector<char> chars(char_set.begin(), char_set.end());
    sort(chars.rbegin(), chars.rend());
    if (chars.empty())
    {
        cout << "Empty!";
        return 0;
    }

    cout << chars.size() << endl;
    for (char c : chars)
    {
        cout << c << " ";
    }
}
