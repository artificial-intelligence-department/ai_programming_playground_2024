#include <iostream>
using namespace std;

int main(){
    int num, count=0;
    cin >> num;
    string given[num];

    for( int i=0; i<num; i++){
        string str;
        cin.ignore();
        getline(cin, str);
        for(int j=0; j<str.size(); j++){
            if(str[j] == '#'){
                if(!(str[j-1] == '#')){
                    count++;
                }
            }
        }
    }

    std::cout << count;

    return 0;
}