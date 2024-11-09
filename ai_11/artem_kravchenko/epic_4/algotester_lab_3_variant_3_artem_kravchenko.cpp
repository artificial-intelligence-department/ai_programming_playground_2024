#include <iostream>
#include <string>

using namespace std;

string compress (const string& s){
    string result;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i + 1 < n && s[i] == s[i + 1])
        {
            ++count;
            ++i;
        }
         result += s[i];

     if (count > 1)
     {
        result += to_string(count);
     }
    }
    return result; 
     
}

int main(){
    string s;
    cin >> s; 
    string result_c = compress(s);
    cout << result_c << endl;
    return 0;
}