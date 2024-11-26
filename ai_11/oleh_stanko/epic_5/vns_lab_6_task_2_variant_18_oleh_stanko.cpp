#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool starts_with_digit(const string& word) 
{
    return !word.empty() && isdigit(word[0]);
}

void sort_words_starting_with_digit(string& input) {
    stringstream ss(input);
    string words[100]; 
    int count = 0;

    string word;
    while (ss >> word) {
        if (starts_with_digit(word)) {
            words[count++] = word; 
        }
    }

    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = i + 1; j < count; ++j) 
        {
            if (words[i] < words[j]) 
            {
                swap(words[i], words[j]); 
            }
        }
    }

    cout << "Words starting with a digit (sorted in descending order):" << endl;
    for (int i = 0; i < count; ++i) 
    {
        cout << words[i] << " ";
    }
    cout << endl;
}

int main() 
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    sort_words_starting_with_digit(input);
    return 0;
}
