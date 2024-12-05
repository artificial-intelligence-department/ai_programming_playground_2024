#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void LowerCase(string& str) 
{
    for (char& c : str) 
    {
        c = tolower(c);
    }
}

int main() 
{
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> wordCount;
    vector<string> words(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> words[i];
        LowerCase(words[i]);
        wordCount[words[i]]++; 
    }

    set<char> validLetters;

    for (const auto& [word, count] : wordCount) 
    {
        if (count >= K) 
        {
            for (char c : word) 
            {
                validLetters.insert(c);
            }
        }
    }

    if (validLetters.empty()) 
    {
        cout << "Empty!" << endl;
        return 0;
    }

    vector<char> sortedLetters(validLetters.begin(), validLetters.end());
    sort(sortedLetters.rbegin(), sortedLetters.rend());

    cout << sortedLetters.size() << endl;
    for (size_t i = 0; i < sortedLetters.size(); i++) 
    {
        cout << sortedLetters[i];
        if (i != sortedLetters.size() - 1) 
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
