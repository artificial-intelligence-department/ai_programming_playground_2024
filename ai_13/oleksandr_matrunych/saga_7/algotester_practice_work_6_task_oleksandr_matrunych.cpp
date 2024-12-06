#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows, total = 0;
    cin >> rows;
    cin.ignore();

    while (rows--) {
        string input;
        getline(cin, input);

        for (int i = 0; i < input.length(); ++i) {
        if (input[i] == '#' && (i == 0 || input[i - 1] != '#')) {
            total++;
            }}}
    cout << total << endl;
    return 0;
}