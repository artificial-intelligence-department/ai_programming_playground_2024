#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void collectData();
void enterUserDataInFile(string userIdent, double userDistance, string userMeasurementSystem);

int main() {
    bool correctInput;

    do { // 8. do while цикл
        correctInput = true;

        string choise;
        cout << "Аvailable features:\n";
        cout << "1. Create order\n\n";
        cout << "Enter your choise: ";
        cin >> choise;
        
        if (choise == "1") {  // 5. Умовні оператори та розгалуження
            collectData();

        } else correctInput = false;

    } while (!correctInput);

    return 0;
}

void collectData() {
    string userName;
    cout << "\nEnter your name: ";
    cin >> userName;

    char* symbols = new char[userName.length()]; // 6. Одновимірний масив
    for (int i = 0; i < userName.length(); i++) { // 10. for цикл
        symbols[i] = userName[i];
    }

    for (int i = 0; i < userName.length() - 1; ++i) {
        for (int j = 0; j < userName.length() - i - 1; ++j) {
            if (symbols[j] > symbols[j + 1]) {
                int temp = symbols[j];
                symbols[j] = symbols[j + 1];
                symbols[j + 1] = temp;
            }
        }
    }

    int* userIdent = new int[userName.length()];

    for (int i = 0; i < userName.length(); i++) {
        userIdent[i] = (symbols[i] * 0.4);
    }

    string userIdentStr = "";
    for (int i = 0; i < userName.length(); i++) {
        userIdentStr += to_string(userIdent[i]);
    } 


    double userDistance;
    cout << "Enter distance: ";
    cin >> userDistance;

    string userMeasurementSystem;
    cout << "Enter measurement system: ";
    cin >> userMeasurementSystem;

    enterUserDataInFile(userIdentStr, userDistance, userMeasurementSystem);

    delete[] symbols;
    delete[] userIdent;
}

void enterUserDataInFile(string userIdent, double userDistance, string userMeasurementSystem) {
    ifstream file("users_data.txt");

    int rowsNum = 0;
    int userRowNum = -1;
    string row;

    while (getline(file, row)) {
        if (row.find(userIdent)) {
            userRowNum = rowsNum + 1;}
        cout << row << endl;
        rowsNum++;
    }

    file.close();
    ifstream file1("users_data.txt");

    if (userRowNum == -1) {
        string* lines = new string[++rowsNum];
        for (int i = 0; i < rowsNum - 1; i++) {
             getline(file1, lines[i]);
        }
        delete[] lines;
    }

    
    file1.close();
}

/**
 * Ви отримали своє перше завдання на новій роботі програмістом у
 * міжнародній логістичній компанії, що здійснює доставку між відділеннями.
 * Раніше офіси компанії працювали незалежно і лише в межах однієї країни,
 * але компанія запустила послугу "Комбінована доставка" і тепер розрахунок вартості
 * відбувається згідно тарифікації, що зберігається у файлах.
 * Все б нічого, але офіси використовують 3 різні системи вимірювання відстані:
 * - імперська (британська миля) == 1 609.344 метра; // mi
 * - миля США (US survey mile) == 1 609.347 метра; // mi_US
 * - метрична система виміру == 1 метр. // m
 *
 * Розробити програму для розрахунку вартості доставки,
 * яка буде використовувати ідентифікатор користувача та накопичувати відстані.
 * Компанія встановила наступні бонуси:
 * Якщо відстань відправлення є паліндромом, то користувач отримує +200 км бонусів.
 * Кожні накопичені 100км це 1$ знижки. Після використання накопичена відстань зменшується.
 * При обрахунку вартості запропонувати користувачу скористатись конвертацією накопичених бонусів.


 * Для формування ідентифікатора користувача використати наступний розрахунок:
    1. Відсортувати буĸви вашого імені за зростанням.
    2. Створити одновимірний масив на основі цілочисельного(int) значення
    символів (ASCII Value) помноженого на 0.4.
    Результат записати.
 */
