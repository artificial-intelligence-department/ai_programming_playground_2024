#include <iostream>
#include <cstring> 
using namespace std;

int findLongestWordLength(const char* s) {
    int maxLength = 0; 
    int currentLength = 0; 

    for (int i = 0; s[i] != '.'; ++i) {
        if (s[i] != ' ') { 
            ++currentLength;
        } else { 
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0; 
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    return maxLength;
}

int main() {
    char s[256]; 
    
    cout << "Enter the string (end with a dot): ";
    cin.getline(s, 256); 

    int longestWordLength = findLongestWordLength(s); 

    cout << "The length of the longest word is: " << longestWordLength << endl;

    return 0;
}
