#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    string lucky;
    cin >> n;

    for (char luckynum : n) {
        if (luckynum == '4' || luckynum == '7') {
            lucky += luckynum;
        }
    }

    if (lucky.empty()) {
        cout << "No luck" << endl;
    } else {
        cout << lucky << endl;
    }

    return 0;
}// https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40847#mySolutions