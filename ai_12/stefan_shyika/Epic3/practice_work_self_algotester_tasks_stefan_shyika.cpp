//algotester 0631 kolobok :)

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <set>

using namespace std;

int main(){
    string song;
    getline (cin, song);

    for(char &c : song){
        c = tolower(c);
    }

    set<string> set;
    string word;
    stringstream strStream(song);

    while(strStream >> word){
        set.insert(word);
    }
    
    int unique = set.size();

    cout << unique;
}