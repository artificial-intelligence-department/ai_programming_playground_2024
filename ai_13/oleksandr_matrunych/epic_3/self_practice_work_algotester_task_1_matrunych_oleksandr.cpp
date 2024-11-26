#include <iostream>
#include <string>
using namespace std;

string compressString(const string& S) {
    string compressed = "";
    int count = 1;

    for (size_t i = 1; i <= S.length(); i++) {
        if (i < S.length() && S[i] == S[i - 1]) {
            count++;
        } else {
            compressed += S[i - 1];
            if (count > 1) {
                compressed += to_string(count);
            }
            count = 1;
        }
    }

    return compressed;
}

int main() {
    string S;
    cin >> S;

    string Scompressed = compressString(S);
    cout << Scompressed << endl;
    return 0;
}
