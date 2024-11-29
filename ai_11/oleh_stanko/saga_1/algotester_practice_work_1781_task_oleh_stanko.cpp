#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

   if (s.find('4') == string::npos && s.find('7') == string::npos) {
        cout << "No luck" << endl;
        return 0; 
    }

    string l;
    
    for (char c : s) {
        if (c == '4' || c == '7') {
            l += c;
        }
    }

    cout << l << endl;
    return 0;
}
