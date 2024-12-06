#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Введіть рядок: ";
    getline(cin, input);

    sort(input.begin(), input.end());

    cout << "Відсортований рядок: " << input << endl;

    return 0;
}