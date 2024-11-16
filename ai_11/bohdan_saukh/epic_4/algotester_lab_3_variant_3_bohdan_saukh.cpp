#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    string resault;
    getline(cin, line);
    int count = 1;
    resault.push_back(line[0]);
    for(int i = 1; i < line.length(); i++){
        if(line[i-1] == line[i]){
            count++;
        }
        if(line[i-1] != line[i]){
            if(count > 1){
                resault += to_string(count);
            }
            resault.push_back(line[i]);
            count = 1;
        }
        if(i == line.length() - 1){
            if(count > 1){
                resault += to_string(count);
            }
        }
    }    
    cout << resault;
    return 0;
}