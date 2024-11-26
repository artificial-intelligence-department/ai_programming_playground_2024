#include <iostream>
#include <cstring> 
using namespace std;

void compressString(const char* s, char* compressed) {
    int n = strlen(s); 
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        char currentChar = s[i];
        int count = 1;  

        while (i + 1 < n && s[i + 1] == currentChar) {
            ++count; 
            ++i; 
        }

        compressed[pos++] = currentChar;

        if (count > 1) {
            char countStr[10]; 
            sprintf(countStr, "%d", count);

            for (int j = 0; countStr[j] != '\0'; ++j) {
                compressed[pos++] = countStr[j];
            }
        }
    }

    compressed[pos] = '\0';
}

int main() {
    char s[100001]; 
    cin >> s;

    char compressed[200001]; 

    compressString(s, compressed);

    cout << compressed << endl;

    return 0;
}
