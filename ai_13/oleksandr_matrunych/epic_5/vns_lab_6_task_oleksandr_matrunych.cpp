#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    const int MAX_LENGTH = 256;
    char input[MAX_LENGTH];

    cout << "Enter a string (max 255 characters): ";
    cin.getline(input, MAX_LENGTH);

    if (strlen(input) == 0 || input[strlen(input) - 1] != '.') {
        cerr << "Error: The string must end with a period!" << endl;
        return 1;
    }

    int start = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (!isalpha(input[i]) || input[i + 1] == '\0') {
            int end = (input[i + 1] == '\0' && isalpha(input[i])) ? i + 1 : i;
            sort(input + start, input + end);
            start = i + 1;
        }
    }

    cout << "Sorted string: " << input << endl;
    return 0;
}
