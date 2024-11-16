#include <iostream>
#include <string>

using namespace std;

int main(){
    int k;
    string s;

    cin >> k;
    cin >> s;

    string ryadok = "TOILET";
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find(ryadok, pos)) != -1)
    {
        count ++;
        pos += ryadok.length();
    }
    if (count >= k)
    {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}