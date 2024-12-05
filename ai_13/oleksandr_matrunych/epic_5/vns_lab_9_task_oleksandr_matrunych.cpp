#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isConsonant(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z') && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int main() {
    // Створюємо файл F1 та записуємо в нього цей текст
    ofstream file1("F1.txt");
    file1 << "This is the first line." << endl;
    file1 << "Second line here." << endl;
    file1 << "Third line in the file." << endl;
    file1 << "Fourth line of text." << endl;
    file1 << "Fifth line of the document." << endl;
    file1 << "Sixth line comes here." << endl;
    file1 << "Seventh line has more text." << endl;
    file1 << "Eighth line is here." << endl;
    file1 << "Ninth line starts now." << endl;
    file1 << "Tenth and final line." << endl;
    file1.close();

    // Відкриваємо файли F1 і F2
    ifstream file1Read("F1.txt");
    ofstream file2("F2.txt");

    int N, K;
    cout << "Enter the starting line number (N): ";
    cin >> N;
    cout << "Enter the ending line number (K): ";
    cin >> K;

    string line;
    int currentLine = 1;

    // Тут копіюю текст F1 до F2
    while (getline(file1Read, line)) {
        if (currentLine >= N && currentLine <= K) {
            file2 << line << endl;
        }
        currentLine++;
    }
    file1Read.close();
    file2.close();

    // Кількість приголосних 
    ifstream file2Read("F2.txt");
    int consonantCount = 0;

    while (getline(file2Read, line)) {
        for (char c : line) {
            if (isConsonant(c)) {
                consonantCount++;
            }
        }
    }

    file2Read.close();
    cout << "The number of consonants in F2.txt is: " << consonantCount << endl;

    return 0;
}
