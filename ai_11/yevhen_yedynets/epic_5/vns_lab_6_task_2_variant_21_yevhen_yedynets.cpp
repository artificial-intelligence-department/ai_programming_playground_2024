#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    if (!input.empty() && input.back() == '.')
        input.pop_back();
    else {
        cout << "Рядок має закінчуватися крапкою." << endl;
        return 0;
    }

    stringstream ss(input);
    vector<string> words, result;
    string word;

    while (ss >> word)
        words.push_back(word);

    for (size_t i = 0; i < words.size(); ++i)
        if (i % 2 == 0)
            result.push_back(words[i]);

    string output;
    for (size_t i = 0; i < result.size(); ++i) {
        output += result[i];
        if (i != result.size() - 1)
            output += " ";
    }

    cout << output << "." << endl;

    return 0;
}
