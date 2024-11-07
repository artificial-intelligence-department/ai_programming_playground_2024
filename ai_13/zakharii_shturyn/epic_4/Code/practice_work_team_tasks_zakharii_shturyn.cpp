#include <iostream>
using namespace std;

bool IsPalindrome(const string& line, int start, int end) {
    bool tmp = 1;   //за замовчуванняям тру
    if(start < end) {
        if(line[start] == line[end]) {
            tmp = IsPalindrome(line,start + 1, end - 1);
        } else {
            tmp = false;
        }
    }
    return tmp;
}

bool IsPalindrome(int& test_int) {
    bool tmp = 1;
    string test = to_string(test_int);
    tmp = IsPalindrome(test, 0, test.length() - 1);

    return tmp;
}

void Print(bool& res) {
    if(res) {
        cout << "Palindrome!" << endl;
    } else{
        cout << "Not palindrome..." << endl;
    }
}

int main() {

    cout << "Input data type:\n1)String\n2)Int\n";
    int opt;
    cin >> opt;
    switch(opt)
    {
    case 1: {
        string test;
        cin >> test;
        bool res = IsPalindrome(test, 0, test.length() - 1);
        Print(res);
        break;
    }

    case 2: {
        int test;
        cin >> test;
        IsPalindrome(test);
        bool res = IsPalindrome(test);
        Print(res);
        break;
    }
    
    default:{
        break;
    }
    }

    return 0;
}