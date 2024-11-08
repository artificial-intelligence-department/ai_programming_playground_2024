#include <iostream>
using namespace std;

int main(){

long long H, M; //змінні, які будуть зберігати початкову кількість мани та хітпоінтів
long long h, m; //змінні, які будуть зберігати кількість мани та хітпоінтів, яка буде відніматися за хід
bool m_h = false;

cout << "Введіть початкову кількість хітпоінтів та мани відповідно: ";
cin >> H >> M;

    for (int i = 0; i < 3; i++)
    {
        cin >> h >> m;
        if (h > 0 && m > 0)
        {
            m_h = true;
            continue;
        }
        H -= h;
        M -= m;
    }

        if (H > 0 && M > 0 && !m_h)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

return 0;
}
