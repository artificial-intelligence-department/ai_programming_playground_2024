#include <bits/stdc++.h>
using namespace std;
void sortdigits(vector <string> &words){
    vector <int> digits;
    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        for(char c : word){
            if(isdigit(c)){
                digits.push_back(c);
            }
        }
        sort(digits.rbegin(), digits.rend());
        int index = 0;
        for (char &c : word){
            if(isdigit(c)){
                c = digits[index];
                index++;
            }        
        }
        words[i] = word;
        digits.clear();
    }
}
int main(){
    char s[256];
    gets(s);
    string input (s);
    vector <char> temp;
    int j = 0;
    vector <string> words;
    bool ifSpace = false;
    for(int i = 0; i < input.length(); i++){
        if (input[i] != ' '){
            temp.push_back(input[i]);
            ifSpace = true;
            continue;
        }
        if(ifSpace){
            string tempstr(temp.begin(), temp.end());
            words.push_back(tempstr);
            j++;
            temp.clear();
            ifSpace = false;
        }
    }
    if(temp.size() != 0){
        string tempstr(temp.begin(), temp.end());
        words.push_back(tempstr);
        temp.clear();
    }


    sortdigits(words);
    for(string d : words){
        cout << d << " ";
    }
    return 0;
}