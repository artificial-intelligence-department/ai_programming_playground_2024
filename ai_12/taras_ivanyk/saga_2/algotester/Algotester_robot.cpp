#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int count_x = 0;
    int count_y = 0;
    getline(cin, s);
    for(char c : s){
        if (c != 'U' && c!= 'R'){
            cout << "Error, you enter the wrong command!" << endl;
        } else{
            if(c == 'U') count_y++;
            else if(c == 'R') count_x++;
        }
    }
    int x, y;
    cin >> x >> y;

    if(count_y >= y && count_x >= x){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}