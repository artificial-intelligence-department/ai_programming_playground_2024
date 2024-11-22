#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    getline(cin, S);
    int dlin = S.length();
    string result;

    for (int i = 0; i < dlin; i++) {
        int counter = 1;

        while (i + 1 < dlin && S[i] == S[i + 1]) {
            counter++;
            i++;
        }

        result.push_back(S[i]); 

        if (counter > 1) {
            result += to_string(counter);
        }
    }

    cout << result;
}
