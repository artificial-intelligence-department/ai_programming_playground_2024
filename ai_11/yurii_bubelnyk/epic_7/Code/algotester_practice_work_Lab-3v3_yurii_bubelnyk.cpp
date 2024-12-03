#include <iostream>
#include <string> // для string, length, to_string

using namespace std;

int main() {

    string s ,sc; // створення string для запису рядка
    cin >> s;
    if(s.length() < 1 || s.length() > 1e5) return 1; // перевірка меж

    int count = 1;// лічильник для запису кількості повторюваних символів

    for(int i = 0; i < s.length(); i++)
    {
        if(i + 1 < s.length() && s[i] == s[i + 1])
        {
            count++;
        }else{
            sc += s[i]; // додавання символів
            if(count == 1) continue; 
            sc += to_string(count);  // запис числа як символ
            count = 1; 
        }
    }

    cout << sc << endl; // вивід рядка

    return 0;
}
