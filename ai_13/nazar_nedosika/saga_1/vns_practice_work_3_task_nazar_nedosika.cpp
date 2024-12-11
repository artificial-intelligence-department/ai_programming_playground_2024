#include <iostream>
#include <cmath>

using namespace std;

void calculateDictionaryInfo() {
    const int pages = 948; 
    const int wordsPerPage = 30;
    const int lettersPerWord = 5;
    const double letterWidth = 2.0;

    int totalWords = pages * wordsPerPage;

    double totalLength = totalWords * lettersPerWord * letterWidth;

    cout << "Кількість російських слів: " << totalWords << endl;
    cout << "Довжина відрізка російських слів: " << totalLength << " мм" << endl;
}

int main() {
    double R1, R2;
    //Використав оператори введення і виведення для вводу опору і виводу результату
    cout << "Введіть величину першого опору (Ом) > ";
    cin >> R1;
    cout << "Введіть величину другого опору (Ом) > ";
    cin >> R2;

    double totalResistance = R1 + R2;
    cout << "Опір ланцюга: " << totalResistance << " Ом" << endl;

    calculateDictionaryInfo();

    return 0;
}