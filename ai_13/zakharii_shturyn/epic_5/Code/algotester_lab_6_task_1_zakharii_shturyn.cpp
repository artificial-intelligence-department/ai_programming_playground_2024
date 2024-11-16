//посортовані унікальні символи в словах, які повторюються більше К разів 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int main() {

    int Repeats, K;
    cin >> Repeats >> K;
    map<string, int> WordCount;
    for(int i = 0; i < Repeats; i++) {
        string Word;
        cin >> Word;
        transform(Word.begin(), Word.end(), Word.begin(), ::tolower);
        WordCount[Word]++;
    }

    set<char>UniqChar;      //сет, щоб букви не повторювались
    for(auto& [word, count] : WordCount) {
        if(count >= K) {
            UniqChar.insert(word.begin(), word.end());
        }
    }

    if(UniqChar.size() > 0) {
        vector<char> res(UniqChar.begin(), UniqChar.end());     //взяв вектор, бо сети сортувати не можна((
        sort(res.begin(), res.end(), greater<char>());
        cout << res.size() << endl;
        for(char elm : res) {
            cout << elm << " ";
        }

    } else {
        cout << "Empty!";
    }
    
    return 0;
}