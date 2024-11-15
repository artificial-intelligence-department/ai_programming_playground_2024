#include <iostream>
#include <string>

using namespace std;

int main(){
    int k;
    string substr = "TOILET";
    string s;
    cin >> k;
    cin.ignore();
    getline(cin, s);

    int len = s.length();
    int counter = 0;
    int position = 0;

    while((position = s.find(substr, position)) != string::npos){
        counter++;
        position += substr.length();
    }

    cout << ((k <= counter) ? "YES" : "NO");
}     