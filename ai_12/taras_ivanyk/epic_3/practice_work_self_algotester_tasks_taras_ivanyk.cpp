#include <iostream>
#include <map>
#include <string>
#include <sstream> //for stringstream (дає змогу обробляти рядок і вибирати з нього окремі букви)
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line); //stringstream проходить по кожній букві окремо
    vector<char> cards;
    string letter;

    while (ss >> letter) {    // [ss >> letter] записує кожне слово з рядка в змінну letter
        if (letter.length() == 1 && isalpha(letter[0])) {
            cards.push_back(tolower(letter[0])); // Додаємо літери в нижньому регістрі
        }
    }

    if (cards.size() > n) {
        cout << "Error: Too many letters entered!" << endl;
        return 1;
    }

    map<char, int> freq; // map для алфавітного порядку
    for (char c : cards) {
        freq[c]++; // збільшуємо лічильник кожен раз як зустрічається одна й та сама буква
    }

    string half = "", middle = "";

    for (auto &pair : freq) {
        char letter = pair.first;
        int count = pair.second;

        half += string(count / 2, letter);

        if (count % 2 != 0 && middle.empty()) { //якщо непарна к-сть, то додаємо символ для середини
            middle = letter; 
        }
    }
    string palindrome = half + middle + string(half.rbegin(), half.rend());
    cout << palindrome << endl;

    return 0;
}
