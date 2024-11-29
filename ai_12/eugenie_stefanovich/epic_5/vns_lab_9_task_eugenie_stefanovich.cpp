#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string F1 = "F1.txt";
    string F2 = "F2.txt";

    
    ofstream fileF1(F1 ); 
    fileF1 << "AB CD F3\n";
    fileF1 << "123\n";
    fileF1 << "A1 B2 C3\n";
    fileF1 << "Hello\n";
    fileF1 << "American \n";
    fileF1 << "Ananas\n";
    fileF1 << "pig 3\n";
    fileF1 << "Albatros 3\n";
    fileF1 << "Megamo3g\n";
    fileF1 << "Diamant\n";
    fileF1.close(); 

  
    ifstream rF1(F1);
    if (!rF1.is_open()){
        cout << "Не вдалося відкрити файл  F1!" << endl;
        exit(0);
    }
    
    int N1, N2;
    cout << "Введіть номери рядків N1 та N2 (від 1 до 10): ";
    cin >> N1 >> N2;

   

    
    ofstream fileF2(F2);
    if (!fileF2.is_open()) {
        cout << "Не вдалося відкрити файл F2" << endl;
        exit(0);
    }

   
    string line;
    int lineNumber = 0;
    while (getline(rF1, line)) {
        lineNumber++;

       
        if (lineNumber < N1 || lineNumber > N2) continue;

       
        if (!line.empty() && line[0] == 'A' && line.back() == '3') {
            fileF2 << line << endl;
            cout << line << endl;
        }
    }
    rF1.close();
    fileF2.close();

    
    ifstream rF2(F2);
    if (!rF2.is_open()) {
        cout << "Не вдалося відкрити файл F2 " << endl;
        exit(0);
    }

   
    if (getline(rF2, line)) {
        int slovvstrok = 0;
        stringstream slov(line); 
        string word;
        while (slov >> word) {   
            slovvstrok++;
        }

        cout << "Кількість слів у першому рядку файлу F2: " << slovvstrok << endl;
    } else {
        cout << "Файл F2 пуст." << endl;
    }

    rF2.close();
    return 0;
}
