#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    cout << "a)" << endl;
    int n;
    cin>>n;
    int mas[n];
    int resault = 0;
    for (int i = 0; i<n; i++){
        cin>>mas[i];
        if (mas[i] % 2 != 0){
            resault++;
        }
    }
    cout << "Odd numbers: " << resault << endl;
    
    cin.ignore();

    cout << "b)" << endl;

    string line;
    getline(cin, line);

    int res = 0;
    bool word = false;

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        if (isspace(ch)) {
            word = false;
        } else if (word == false) {
            word = true;
            res++;
        }
    }

    cout<<"Number of words: "<< res;

    return 0;
}