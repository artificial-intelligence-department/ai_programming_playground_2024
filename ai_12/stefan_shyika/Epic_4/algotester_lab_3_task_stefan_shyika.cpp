#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    getline(cin, S);
    int len = S.length();
    string result;

    for (int i = 0; i < len; i++) {
        int counter = 1;

        while (i + 1 < len && S[i] == S[i + 1]) {
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
