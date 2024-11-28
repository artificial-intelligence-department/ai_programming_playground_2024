#include <iostream>
#include <cstring> 

using namespace std;

int main() {
    char s[256];

    cout << "Введіть рядок (до 255 символів): ";
    gets(s);
    
    char* longest = nullptr;
    char* shortest = nullptr;
    
    char* word = strtok(s, " ");
    
    while (word != nullptr) {

        int len = strlen(word);
        if (word[len - 1] == '.') {
            word[len - 1] = '\0';
        }
        
        if (longest == nullptr || strlen(word) > strlen(longest)) {
            longest = word;
        }
        if (shortest == nullptr || strlen(word) < strlen(shortest)) {
            shortest = word;
        }
        
        word = strtok(nullptr, " ");
    }
    
    cout << "Найдовше слово: " << longest << endl;
    cout << "Найкоротше слово: " << shortest << endl;

    return 0;
}
