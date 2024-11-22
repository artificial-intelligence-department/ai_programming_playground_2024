#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string line, line1, line2;
    int changes1 = 0, changes2 = 0;
    getline(cin, line);
    int sizeLine = line.size();
    for(int i = 0; i < sizeLine; i++){
        if(i % 2 == 0){
            line1.push_back('B');
            line2.push_back('Y');
        }
        if(i % 2 == 1){
            line1.push_back('Y');
            line2.push_back('B');
        }
    }
    for(int i = 0; i < sizeLine; i++){
        if(line[i] != line1[i]) changes1++;
        if(line[i] != line2[i]) changes2++;
    }
    cout << min(changes1, changes2);
    return 0;
}