#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char text[256];
    cin.getline(text, 256);

    int maxLength = 0, currentLength = 0;
    for (int i = 0; text[i] != '.'; i++) {
        if (text[i] != ' ') {
            currentLength++;
        } else if (currentLength > 0) {
            maxLength = max(maxLength, currentLength);
            currentLength = 0;
        }
    }

    maxLength = max(maxLength, currentLength);

    cout << maxLength << endl;

    return 0;
}
