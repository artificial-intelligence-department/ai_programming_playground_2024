#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    int count = 1;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++){
        if (str[i] == str[i + 1]){
            count++;
        }
        else{
            if (count == 1){
                cout << str[i];
                count = 1;
            }
            else{
                cout << str[i] << count;
                count = 1;
            }
        }
    }
    return 0;
}