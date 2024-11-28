#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; // Кількість подач
    cin >> n;
    string results; // Результати подач ('K' або 'V')
    cin >> results;

    int totalK = 0, totalV = 0; // Загальний рахунок по партіях
    int nowK = 0, nowV = 0; // Поточний рахунок у партії

    for (char c : results) {
        if (c == 'K') nowK++; 
        else nowV++;          

        // Перевіряємо, чи закінчилася партія
        if ((nowK >= 11 || nowV >= 11) && abs(nowK - nowV) >= 2) {
            // додаєм в тотал очки хто виграв
            if (nowK > nowV) totalK++;
            else totalV++;

            // Скидаємо рахунок
            nowK = 0;
            nowV = 0;
        }
    }

    //загальний рахунок
    cout << totalK << ":" << totalV << endl;

    // Якщо остання партія не завершена то знизу поточний рахунок
    if (nowK > 0 || nowV > 0) {
        cout << nowK << ":" << nowV << endl;
    }

    return 0;
}
