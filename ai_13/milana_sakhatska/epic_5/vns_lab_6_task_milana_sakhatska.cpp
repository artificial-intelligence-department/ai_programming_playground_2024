#include <iostream>
#include <cstring>
using namespace std;

bool is_palindrome(const char* word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; ++i) {
        if (word[i] != word[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void find_palindromes(char str[]) {
    char* token = strtok(str, " "); 
    while (token != NULL) {
        if (is_palindrome(token)) {
            cout << token << endl; 
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char s[256];
    
    cout << "Введіть рядок: ";
    cin.getline(s, 256);
    
    cout << "Паліндроми в рядку:" << endl;
    find_palindromes(s);
    
    return 0;
}
