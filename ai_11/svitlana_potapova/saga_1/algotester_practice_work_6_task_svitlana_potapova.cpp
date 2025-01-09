#include <iostream>
#include <string>
#include <algorithm>  

using namespace std;

int main() {
    int k;
    int amount = 0;
    string s;
    string target = "TOILET";

    cin >> k;
    cin.ignore(); 

    getline(cin, s);

    int found = s.find(target);  
    while (found != string::npos) {
        amount++;
        s.erase(0, found + target.length()); 
        found = s.find(target);
    } 

    if(amount>=k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
