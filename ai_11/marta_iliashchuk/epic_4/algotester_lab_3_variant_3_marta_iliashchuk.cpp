#include <iostream>
using namespace std;

int main(){
    string compressed;
    int count;
    int number;
    string s;
    cin>>s;

    for(int i = 0; i<s.size(); i++){
        count = 1;
        while(s[i] == s[i+1] and i< s.size() - 1){
            count++;
            i++;
        }
        if(count == 1){
            compressed += s[i]; 
        }
        else{
            compressed += s[i] + to_string(count);
        }
    }
    cout<<compressed;

    return 0;

}