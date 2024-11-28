#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// кількість приголосних літер у рядку
int countPrigolosni(const string &line) {
    int count = 0;
    for (char ch : line) {
        if (isalpha(ch)) {
            char lowerCh = tolower(ch);
            if (lowerCh != 'a' && lowerCh != 'e' && lowerCh != 'i' && lowerCh != 'o' && lowerCh != 'u') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ofstream file1("F1.txt");
    if (!file1) {
        cerr << "Помилка створення файлу F1!" << endl;
        return 1;
    }
    
    file1 << "Apple is red.\n";
    file1 << "Banana is yellow.\n";
    file1 << "Avocado is green.\n";
    file1 << "Cherry is red.\n";
    file1 << "Apricot is orange.\n";
    file1 << "Peach is sweet.\n";
    file1 << "Almonds are healthy.\n";
    file1 << "Grapes are purple.\n";
    file1 << "Ants are tiny.\n";
    file1 << "Blueberry is blue.\n";
    file1.close();
    
    int N1, N2;
    cout << "Введіть номер першого рядка для копіювання (від 1): ";
    cin >> N1;
    cout << "Введіть номер останнього рядка для копіювання (до 10): ";
    cin >> N2;
    
    if (N1 < 1 || N2 < 1 || N1 > 10 || N2 > 10 || N1 > N2) {
        cerr << "Невірно введені номери рядків!" << endl;
        return 1;
    }
    
    ifstream file1_in("F1.txt");
    ofstream file2("F2.txt");
    if (!file1_in || !file2) {
        cerr << "Помилка відкриття файлів!" << endl;
        return 1;
    }
    
    int lineNum = 0;
    string line;
    
    while (getline(file1_in, line)) {
        lineNum++;
        if (lineNum >= N1 && lineNum <= N2 && !line.empty() && line[0] == 'A') {
            file2 << line << endl;
        }
    }
    
    file1_in.close();
    file2.close();
    
    // найбільша кількість приголосних у файлі F2
    ifstream file2_in("F2.txt");
    if (!file2_in) {
        cerr << "Помилка відкриття файлу F2!" << endl;
        return 1;
    }
    
    int maxConsonants = 0, maxLineNum = 0, currentLineNum = 0;
    while (getline(file2_in, line)) {
        currentLineNum++;
        int consonants = countPrigolosni(line);
        if (consonants > maxConsonants) {
            maxConsonants = consonants;
            maxLineNum = currentLineNum;
        }
    }
    
    file2_in.close();
    
    cout << "Номер рядка з найбільшою кількістю приголосних у файлі F2: " << maxLineNum << endl;
    
    return 0;
}
