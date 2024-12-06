// Надрукувати всі слова, які співпадають з її першим словом.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    char delimiter = ' ';
    istringstream iss(input);
    string word;
    vector<string> words;
    vector<int> idxs;

    while (getline(iss, word, delimiter)) {
        words.push_back(word);
    }

    int idx = 0;
    for (string w_now : words)
    {   
        if ((w_now == words[0]) && (idx != 0))
        {
            cout << w_now << endl;
        }
        ++idx;
    }

    return 0;
}