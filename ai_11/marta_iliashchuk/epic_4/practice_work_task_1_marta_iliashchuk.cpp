#include <iostream>
using namespace std;

bool isPalindrome(const string& str, int start, int end){
    return (str[start] == str[end]);
    return isPalindrome(str, start + 1, end - 1);
}
bool isPalindrome(int number){
    int reversed = 0;
    int revised_number = number;
    while (revised_number != 0) {
        reversed = reversed * 10 + revised_number % 10;
        revised_number /= 10;  //integer!
    }
    return (reversed == number);

}
int main(){
    string str;
    int number;

    cin>>str;

    if(isPalindrome(str, 0, str.size() - 1)){
        cout<<"Palindrome."<<endl;
    }

    cin>>number;

    if(isPalindrome(number)){
        cout<<"Palindrome."<<endl;
    }
    
    return 0;
}