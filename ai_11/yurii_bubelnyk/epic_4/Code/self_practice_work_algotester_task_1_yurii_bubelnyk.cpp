#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInVector(const vector<string>& vec, const string& name);
bool isLowercaseLetters(const string& str);

int main() {
    int n, m;
    cin >> n;
    if(n < 0 || n > 777) return 1;
    cin >> m;
    if(m < 0 || m > 777) return 1;
    
    vector<string> uniqueDrinks;

    for (int i = 0; i < n; i++) {
        string drink;
        cin >> drink;
        if(!isLowercaseLetters(drink)) return 1;
        if (!isInVector(uniqueDrinks, drink)) {
            uniqueDrinks.push_back(drink);
        }
    }
    
    for (int i = 0; i < m; i++) {
        string drink;
        cin >> drink;
        if (!isLowercaseLetters(drink)) return 1; // Перевірка на коректність
        if (!isInVector(uniqueDrinks, drink)) {
            uniqueDrinks.push_back(drink);
        }
    }


    cout << uniqueDrinks.size() << endl;

    return 0;
}

bool isInVector(const vector<string>& vec, const string& name) {
    for (const string& existingName : vec) {
        if (existingName == name) {
            return true;
        }
    }
    return false;
}

bool isLowercaseLetters(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch) || !islower(ch)) {
            return false;
        }
    }
    return true;
}


