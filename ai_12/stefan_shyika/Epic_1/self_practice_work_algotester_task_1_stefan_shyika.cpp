#include<iostream>
#include<string>

using namespace std;

int main(){
    string result = "";
    cin >> result;
    int len = result.size();
    int counter = 0;
    for(int i = 0; i < len; i++){
        if(result[i] == '4' || result[i] == '7'){
            counter++;
        }
    }
    cout << counter;
}