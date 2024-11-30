#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    string res("");
    string S;
    cin >> S;
    int num = 1;

    for (int i=1;i<=S.length();i++) {
        if(S[i] == S[i-1]) {
            num++;
        }else /*if (S[i] == S[i-1] && S[i]!=S[S.length() - 1])*/ {//ми зара на b
            res+=S[i-1];
            if (num > 1) {
                res += to_string(num); 
                num = 1;
            //} все було добре для двох до оцьої знизу умови
            if ( S[i]==S[S.length() - 1]) {
                num = 1;
                }
            }
        }

    }


cout << res;
return 0;
}



