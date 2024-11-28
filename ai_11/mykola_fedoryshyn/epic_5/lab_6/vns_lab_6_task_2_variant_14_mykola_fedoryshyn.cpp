#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;
bool Valid(const string &word)
{
    bool has_letter = false;
    bool has_digit = false;
    for (char c : word)
    {
        if (isalpha(c))
            has_letter = true;
        if (isdigit(c))
            has_digit = true;
        if (has_letter && has_digit)
            return true;
    }

    return false;
}
int main()
{
    string input;
    cout << "Введіть рядок: ";
    getline(cin, input);

    istringstream stream(input);
    string word;
    vector<string> valid_words;

    while (stream >> word)
    {
        if (Valid(word))
        {
            valid_words.push_back(word);
        }
    }
    
    if (valid_words.empty())
    {
        cout << "Жодного слова не знайдено!" << endl;
    }
    else
    {
        for (const string &w : valid_words)
        {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
