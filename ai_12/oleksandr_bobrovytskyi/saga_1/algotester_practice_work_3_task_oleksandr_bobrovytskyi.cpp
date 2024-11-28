#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string palindrome, half, middle;

    cin >> n;
    if(n > 1000 || n < 1)
    {
        return 1;
    }
    
    vector<char> letters(n);
    for(int i = 0; i < n; i++)
    {
        cin >> letters[i];
    }

    unordered_map<char, int> frequency;
    for(char c : letters)
    {
        frequency[c]++;
    }

    for(auto [letter, number] : frequency)
    {
        if(middle.empty() && number % 2 != 0)
        {
            middle = letter;
        }

        if(number > 1)
        {
            half += string(number / 2, letter);
        }
    }
    
    palindrome = half + middle;
    reverse(half.begin(), half.end());
    palindrome += half;

    cout << palindrome;

    return 0;
}