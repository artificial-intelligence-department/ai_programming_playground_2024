#include <iostream>
#include <string> // для string та length

using namespace std;

int main(){
    string s;
    cin >> s;

    bool lit[26] = {false}; // ініціалізація масиву, зі значенням false для кожного елемента
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        int index = c - 'A';
        if (lit[index] == false)
        {
            lit[index] = true;
            result++ ;
        }
        
    }
    
    cout << result << endl;

    return 0;
}