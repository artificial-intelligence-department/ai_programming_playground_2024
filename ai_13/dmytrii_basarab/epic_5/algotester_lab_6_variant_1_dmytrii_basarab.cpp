#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    int M, K;
    cin >> M >> K;
    map<string, int> WordCount;
    for(int i = 0; i < M; i++) {
        string Word;
        cin >> Word;
        transform(Word.begin(), Word.end(), Word.begin(), ::tolower);//шоб всі букви були маленькі там в умові просили
        WordCount[Word]++;//слово передається як ключ якшо ключа ше нема то утворює пару [word, 0] а якшо вже є то ++ до значення 
    }

        set<char, greater<char>>UniqChar;      //сет, щоб букви не повторювались
    for(auto& [word/*ключ*/, count] : WordCount) {
        if(count >= K) {
            UniqChar.insert(word.begin(), word.end());//insert кожну буквц від початку до кінця
        }
    }

    if(UniqChar.size() > 0) {
        cout << UniqChar.size() << endl;
        for(char elm : UniqChar) {//сет має букви вже відсортовані + без повторок
            cout << elm << " ";
        }

    } else {
        cout << "Empty!";
    }

    return 0;
}