#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

//функція перевіряє, чи містить рядок слово, що починається на певну букву
bool containsWordStartingWith(const string& line, char letter) {
    istringstream stream(line);
    string word;
    while (stream >> word) {
        if (!word.empty() && word[0] == letter) {
            return true;
        }
    }
    return false;
}

//функція знаходить найкоротше слово у файлі
string findShortestWordInFile(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу " << filename << endl;
        return "";
    }

    string line, word, shortestWord;
    size_t shortestLength = numeric_limits<size_t>::max();

    while (getline(file, line)) {
        istringstream stream(line);
        while (stream >> word) {
            if (word.length() < shortestLength) {
                shortestLength = word.length();
                shortestWord = word;
            }
        }
    }

    file.close();
    return shortestWord;
}

int main() {
    const char* file1 = "F1.txt";
    const char* file2 = "F2.txt";
    char targetLetter = 'A'; //'цільова' літера

    //створюємо текстовий файл F1
    ofstream f1(file1);
    if (!f1) {
        cerr << "Помилка створення файлу " << file1 << endl;
        return 1;
    }
    f1 << "Apple banana cherry\n";
    f1 << "Apricot melon peach\n";
    f1 << "Grapes pineapple mango\n";
    f1 << "Plum orange pear\n";
    f1 << "Strawberry blueberry\n";
    f1 << "Avocado kiwi lychee\n";
    f1 << "Tomato cucumber carrot\n";
    f1 << "Watermelon papaya sashahvostic\n";
    f1 << "Cherry raspberry fig\n";
    f1 << "Pear pomegranate grapefruit\n";
    f1.close();

    //копіюємо рядки у файл F2
    ifstream input(file1);
    ofstream output(file2);
    if (!input || !output) {
        cerr << "Помилка відкриття файлу для копіювання!" << endl;
        return 1;
    }

    string line;
    while (getline(input, line)) {
        if (!containsWordStartingWith(line, targetLetter)) {
            output << line << endl;
        }
    }

    input.close();
    output.close();

    //шукаємо найкоротше слово у файлі F2
    string shortestWord = findShortestWordInFile(file2);
    if (!shortestWord.empty()) {
        cout << "Найкоротше слово у файлі " << file2 << ": " << shortestWord << endl;
    } else {
        cout << "Файл " << file2 << " порожній або не містить слів!" << endl;
    }

    return 0;
}
