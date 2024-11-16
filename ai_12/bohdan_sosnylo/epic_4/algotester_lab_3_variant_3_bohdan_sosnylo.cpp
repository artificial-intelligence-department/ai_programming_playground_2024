#include <iostream>
#include <string>
using namespace std;

int main(){

int m = 1;
char k;
string s;
cin >> s;

string s1,p1,p2;
int i = 1;
while(true){
   
    if (s[i] == s[i-1]){
        ++m;
    }
    else{
        if(m != 1){
            p1 = s[i-1]; 
            s1.append(p1);
            p2 = to_string(m);
            s1.append(p2);
            }
        else{
            p1 = s[i-1];
            s1.append(p1);
            } 

    m = 1;
    }
    if(i == s.size()){
        break;
    }
    ++i;
    
}

for(int i = 0;i<s1.size();i++){
    cout <<s1[i];
}

    return 0;
}