#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main() {

    char s[256];
    cout << "Enter the text: ";
    cin.getline(s, 256);

    int minlen = INT_MAX, curlen = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '.') {
            curlen++;
        }
        else if (curlen > 0) {
            if (curlen < minlen) minlen = curlen;
            curlen = 0;
        }
    }

    if (minlen == INT_MAX) {
        cout << "There are no words in the text." << endl;
    }
    else {
        cout << "The length of the shortest word is: " << minlen << endl;
    }

    return 0;
}
