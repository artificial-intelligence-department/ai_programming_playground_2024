#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
void reverseWord (string &s , size_t wordStart , size_t wordEnd){
  while (wordStart < wordEnd){
    swap (s[wordStart], s[wordEnd]);
    wordStart++;
    wordEnd--;
  }
}

int main (){
  string s;
  cout << "Enter text (only less than 255 and end with '.' ) :";
  getline(cin,s);

  size_t len = s.length();
  size_t wordStart = 0;

  for (size_t i = 0 ; i <= len;i++){
    if (i == len || s[i] == '.' || s[i] == ' '){
      if(i > wordStart){
      reverseWord (s, wordStart, i-1);
      }
      wordStart = i+1;
    }
  }
  cout << "Result: " << s << endl;
  return 0;
}