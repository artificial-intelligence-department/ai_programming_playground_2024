#include <iostream>
#include <string>
using namespace std;

int main() {
    string String, cString;
    cin >> String;
    for (int i = 0; i < String.size(); i++) {
        int sum = 1;
        while (i + 1 < String.size() && String[i] == String[i + 1]) {
            sum++;
            i++;
        }
        cString += String[i];
        if (sum > 1) {
            cString += to_string(sum);
        }
    }
    cout << cString << endl;
    return 0;
}