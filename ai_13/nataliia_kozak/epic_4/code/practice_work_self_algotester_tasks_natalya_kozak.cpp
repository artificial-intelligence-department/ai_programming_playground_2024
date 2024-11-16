#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    int k = 0;
    char s0;
    int count;
    cin >> s;
    for(char s0:s){
        if(s0 == ' '){
            continue;
        }
        count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s0){
                count += 1;
                s[i] = ' ';
            }
        }
        if(count % 2 != 0){
            k += 1;
        }

    }
    if(k<=1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;

}