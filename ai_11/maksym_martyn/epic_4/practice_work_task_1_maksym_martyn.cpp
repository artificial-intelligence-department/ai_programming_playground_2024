#include <iostream>
#include <string>
using namespace std;

bool isPalindrome (const string &str){
  int start = 0;
  int end = str.length()-1;
  while (start<end)
  {
    if (str[start]!=str[end])
    {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

bool isPalindrome (int num){
  string forNum = to_string(num);
  return isPalindrome(forNum);
}

void Print (bool &result){
  if(result){
    cout << "Is Palindrome";
  } else {
    cout << "Is not Palindrome";
  }
}

int main(){
  int option;
  string str;
  bool result;
  int num;
  
  cout << "Enter option: 1 - for string , 2 - for number\n";
  cin >> option;

  switch (option)
  {
  case 1:
    cin >> str;
    result = isPalindrome(str);
    Print(result);
    break;
  case 2: 
    cin >> num;
    result = isPalindrome(num);
    Print(result);
    break;
  default:
  cerr << "Not correct option";
    break;
  }
  return 0;
}