#include <iostream>
#include <string>

using namespace std;

int main() {
    int k; // минимальное количество непересекающихся вхождений
    string s; // сообщение
    
    // Ввод данных
    cin >> k;
    cin >> s;

    string targ = "TOILET"; 
    int N = targ.length();
    int count = 0; 

    // Ищем непересекающиеся вхождения "TOILET"
    for (size_t i = 0; i <= s.length() - N; ) {
        if (s.substr(i, N) == targ) {
            count++;
            i += N; 
        } else {
            i++; 
        }
        
        
        if (count >= k) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
