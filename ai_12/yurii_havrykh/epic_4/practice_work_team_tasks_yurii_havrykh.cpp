#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int left, int right){
    bool isPal=true;
    if(left+1<right){
        isPal=isPalindrome(str,left+1, right-1);
    }
    if ( (isPal) && (str[left]==str[right]) ) return true;
    return false;
}

vector<int> divide(int num){
    vector<int> a;
    while(num>0){
        a.push_back(num%10);
        num/=10;
    }
    return a;
}
bool isPalindrome(vector<int> &a, int left, int right){
    bool isPal=true;
    if(left+1<right){
        isPal=isPalindrome(a,left+1, right-1);
    }
    if ( (isPal) && (a[left]==a[right]) ) return true;
    return false;
}

int main(){
    string str;
    cout<<"String:";
    cin>>str;
    int num;
    cout<<"Number:";
    cin>>num;
    vector<int>a = divide(num);
    cout<<"Is string palindrome? "<< (isPalindrome(str,0,str.size()-1) ? "Yes" : "No" )<<endl;
    cout<<"Is number palindrome? "<< (isPalindrome(a,0,a.size()-1) ? "Yes" : "No" )<<endl;
}