#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(static_cast<unsigned>(time(0))); 
    int kilkistEl = 0;
    cout << "Введіть кількість елементів в масиві" << endl;
    cin >> kilkistEl;
    if (kilkistEl >= 100) {
        cout << "Помилка: кількість елементів не може перевищувати 100, спробуйте ще раз" << endl;
        cin >> kilkistEl;
    }
    int mainArr[100];
    cout << "Масив: " << endl;
    for (int i = 0; i < kilkistEl; i++){
        mainArr[i] = rand() % 100 + 1;
        cout << mainArr[i] << endl;
    }
    cout << endl;

    for(int i = 0; i < kilkistEl; ) {
        if (mainArr[i] == 0) {
            for (int j = i; j < kilkistEl - 1; j++) {
                mainArr[j] = mainArr[j + 1];
            }
            kilkistEl--;
        } else {
            i++;
        }
    }

    bool key = true;
    for(int i = 0; i < kilkistEl; i++ ){
        if(mainArr[i] % 2 == 0 && key) {
            for(int k = kilkistEl; k > i + 1; k--) {
                mainArr[k] = mainArr[k - 1];
            }
            mainArr[i + 1] = mainArr[i] + 2;
            kilkistEl++;
            key = false;
        }
    }

    cout << "Відредагований масив: " << endl;
    for (int i = 0; i < kilkistEl; i++) {
        cout << mainArr[i] << endl;
    }
    cout << endl;

    return 0;
}
