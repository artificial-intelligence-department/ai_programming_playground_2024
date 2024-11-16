#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Check_Palindrome(const string& words) {
    int length = words.length();
    for (int i = 0; i < length / 2; i++) {
        if (words[i] != words[length - i - 1]) {
            return false;
        }
    }
    return true; 
}

int main()
{
    string User_input;
    string WORD;
    vector <string> words;
    while (true) {
        cout << "Enter a word: ";
        cin >> WORD;
        words.push_back(WORD);

        if (Check_Palindrome(WORD))
        {
            cout << WORD << " is a palindrome." << endl;
        }
        else {
            cout << WORD << " is not a palindrome. " << endl;
        }

        cout << "Type (exit) if you want to end. If not, type any letter " << endl;
        cin >> User_input;

        if (User_input == "Exit" || User_input == "exit")
        {
            return 0;
        }
    }
}