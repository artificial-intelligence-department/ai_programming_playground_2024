#include <iostream>
#include <string>
using namespace std;

string determineWinner(int a, int b, int c) {
    int sumResult = a + b + c;

    int concatResult = stoi(to_string(a) + to_string(b) + to_string(c));

    if (sumResult > concatResult) {
        return "Andriy";
    if (sumResult < concatResult) {
        return "Oleg";
    } else {
        return "Draw";
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << determineWinner(a, b, c) << endl;

    return 0;
} // https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40812#mySolutions