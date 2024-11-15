#include <iostream>
#include <string>

using namespace std;

string compressString(const string& input) {
    string compressed; 
    int length = input.length(); 

    for (int i = 0; i < length; i++) {
        char currentChar = input[i]; 
        int count = 1; 

        while (i + 1 < length && input[i + 1] == currentChar) {
            count++;
            i++; 
        }
        compressed += currentChar;
        if (count > 1) {
            compressed += to_string(count);
        }
    }
    return compressed; 
}

int main() {
    string input;
    cin >> input; 

    string compressed = compressString(input); 
    cout << compressed << endl; 

    return 0;
}