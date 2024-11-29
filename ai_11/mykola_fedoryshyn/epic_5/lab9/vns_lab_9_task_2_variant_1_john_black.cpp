#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int vovels_count[10] = {0,0,0,0,0,0,0,0,0,0};

    ofstream file1("F1.txt");
    if (!file1.is_open()) {
        cerr << "Не вдалося відкрити файл F1 для запису!" << endl;
        return 1;
    }
    vector<string> lines = {
        "This is the first line.", 
        "The second line with the letter A.",
        "The third line with the letter A.",
        "Fourth line.",
        "The fifth line.",
        "The sixth line with the letter A.",
        "The seventh line with the letter A.",
        "Eighth line.",
        "Ninth line.",
        "The tenth line with the letter A."
    };

    for (const string &line : lines) {
        file1 << line << endl;
    }
    file1.close();
    int N1, N2;
    cout << "Введіть номер початкового рядка (N1): ";
    cin >> N1;
    cout << "Введіть номер кінцевого рядка (N2): ";
    cin >> N2;

    if (N1 > N2 || N1 < 1 || N2 > lines.size()) {
        cerr << "Некоректні значення N1 або N2!" << endl;
        return 1;
    }

    ifstream inFile("F1.txt");
    ofstream outFile("F2.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Не вдалося відкрити файл для читання або запису!" << endl;
        return 1;
    }
    string line;
    int lineNumber = 0;
    while (getline(inFile, line)) {
        lineNumber++;
        if (lineNumber >= N1 && lineNumber <= N2 && line.find('A') == string::npos && line.find('a') == string::npos) {
            outFile << line << endl;
        }
    }

    char letter;
    for(int lineNumber = 0; lineNumber < 10; lineNumber++)
        for(int i = 0; i<lines[lineNumber].length(); i++){
            letter = lines[lineNumber][i];
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
                letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U'){
                vovels_count[lineNumber] ++;
            }
    }
    int max = vovels_count[0];
    for(int j = 0; j<10; j++){
        if(vovels_count[j] > max) max = vovels_count[j];
    }  
    for(int j = 0; j<10; j++){
        if(vovels_count[j] == max){
            std::cout << "\nНайбільше голосних в " << j+1 << " рядку";
            break;
        }
    }         
    inFile.close();
    outFile.close();

    cout << "\nОбробка завершена. Перевірте файл F2.txt." << endl;
    return 0;
}
