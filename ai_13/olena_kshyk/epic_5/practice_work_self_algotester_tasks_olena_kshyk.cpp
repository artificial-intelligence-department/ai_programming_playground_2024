#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

void to_lower_case(string &s)
{
    for (char &c : s)
        c = tolower(c);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<string> words(n);
    unordered_map<string, int> freq;

    for (int i = 0; i < n; i++)
    {
        getline(cin, words[i]);
        to_lower_case(words[i]);
        freq[words[i]]++;
    }

    string result;

    for (const string &word : words)
        if (freq[word] >= k)
            result.append(word);

    if (result.empty())
        cout << "Empty!";
    else
    {
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        reverse(result.begin(), result.end());

        cout << result.size() << endl;
        for (char c : result)
            cout << c << " ";
    }

    return 0;
}
