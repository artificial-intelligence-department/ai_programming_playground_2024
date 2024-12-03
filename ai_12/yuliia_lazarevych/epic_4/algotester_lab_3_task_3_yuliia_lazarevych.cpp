#include <iostream>
#include <string>
#include <vector>

using namespace std;

//використовую структуру для зберігання символу та кількості його входжень
struct CharCount {
    char character;
    int count;
};

//використовую функцію для компресії стрічки
string compressString(const string& s) {
    vector<CharCount> compressed; //використовую динамічний масив для зберігання структури CharCount

    //ітерую через стрічку
    for (size_t i = 0; i < s.length(); ++i) {
        if (compressed.empty() || compressed.back().character != s[i]) {
            compressed.push_back({s[i], 1});
        } else {
            compressed.back().count++;
        }
    }

    string result;
    for (const auto& entry : compressed) {
        result += entry.character;
        if (entry.count > 1) {
            result += to_string(entry.count);
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    string compressed = compressString(s);
    cout << compressed << endl;
    return 0;
}
