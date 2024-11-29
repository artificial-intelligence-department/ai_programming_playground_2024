#include <iostream>
#include <string>
using namespace std;


int expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; 
}

int main() {
    int n;
    string s;
    
    cin >> n;  
    cin >> s;  
    
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        maxLength = max(maxLength, max(len1, len2));
    }
    
    cout << maxLength << endl;  
    return 0;
}
