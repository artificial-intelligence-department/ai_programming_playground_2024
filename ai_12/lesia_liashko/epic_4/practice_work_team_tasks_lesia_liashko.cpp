#include <iostream>
#include <string>

using namespace std;

bool isPallindrome(int numbers) {
 if (numbers < 0) {
        return false;  
    }

    int original = numbers;  
    int reversed = 0;

    while (numbers > 0) {
        int digit = numbers % 10;         
        reversed = reversed * 10 + digit;  
        numbers /= 10;                    
    }

    
    return original == reversed;
}
bool isPallindrome ( const string &str, int start, int end){
 if(start < end)
    {
        if (str[start] != str[end])
            return 0;
        return isPallindrome(str, start + 1, end - 1);
    }
    else
        return 1;
}

int main (){
    int numbers;

 cout << "Enter a set of numbers" << endl;
 cin >> numbers;
 cout << (isPallindrome (numbers)? "It's a pallindrome": "No") << endl;

    string str;
    int start = 0, end = str.length() - 1;

 cout << "Enter a word" << endl;
 cin >> str;
 cout << (isPallindrome (str, start, end)? "It's a pallindrome": "No") << endl;

} 