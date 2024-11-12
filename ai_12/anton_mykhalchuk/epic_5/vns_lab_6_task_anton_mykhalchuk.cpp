#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isPalindrome(const string &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    if (!input.empty() && input.back() == '.') {
        input.pop_back();
    }

    istringstream iss(input);
    vector<string> words;
    string word;
    

    while (iss >> word) {
        words.push_back(word);
    }


    cout << "Palindromes: ";
    for (int i = 0; i < words.size(); i++) {
        if (isPalindrome(words[i], 0, words[i].length() - 1))
        {
            cout << words[i] << " ";
        }

    }
    return 0;
}