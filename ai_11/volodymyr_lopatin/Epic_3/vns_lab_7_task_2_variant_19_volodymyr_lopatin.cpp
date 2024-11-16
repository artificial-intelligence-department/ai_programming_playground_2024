/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace numbops {
    int minElem(int numb[], int n) {
        int min = numb[0];
    
        for (int i = 1; i < n; ++i) {
            if (numb[i] < min) {
                min = numb[i];
            }
        }
        return min;
    }
}

namespace strops {
    string minElem(string txt) {
        stringstream sw(txt);
        string word;
        string minWord;
    
        if (sw >> minWord) {
            while (sw >> word) {
                if (word.length() < minWord.length()) {
                    minWord = word;
                }
            }
        }
        return minWord;
    }
}

int main() {
    int numb[] = {-23, 34, 3, 0, 145, -56};
    int n = 6;
    string txt = "Can you pass me salt shaker, please";
    
    cout << "Мінімальне число: " << numbops::minElem(numb, n) << endl;
    cout << "Мінімальне слово: " << strops::minElem(txt) << endl;
    
    return 0;
}*/


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int minElemNumbers(int numb[], int n) {
    int min = numb[0];
    
    for (int i = 1; i < n; ++i) {
        if (numb[i] < min) {
            min = numb[i];
        }
    }
    return min;
}

string minElemString(string txt) {
    stringstream sw(txt);
    string word;
    string minWord;
    
    if (sw >> minWord) {
        while (sw >> word) {
            if (word.length() < minWord.length()) {
                minWord = word;
            }
        }
    }
    return minWord;
}

int main() {
    int numb[] = {-23, 34, 3, 0, 145, -56};
    int n = 6;
    string txt = "Can you pass me salt shaker, please";
    
    cout << "Мінімальне число: " << minElemNumbers(numb, n) << endl;
    cout << "Мінімальне слово: " << minElemString(txt) << endl;
    
    return 0;
}

