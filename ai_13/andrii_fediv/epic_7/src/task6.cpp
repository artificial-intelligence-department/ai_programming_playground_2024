#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string checker(int index)// №13 параметри та аргументи функції / для передачі індексу для перевірки на його основі
{
    string answer[] = {"YES", "NO", "ERROR"};
    return answer[index];
}

int main()
{
    vector<vector<long long>> arr(2); // #6 двовимірний масив | для збереження всіх даних компактно
    arr[0] = vector<long long>(4);    // #7 одновимірний масив | для задавання початкового розміру одновиміпному масиву
    arr[1] = vector<long long>(2);
    cin >> arr[0][0] >> arr[0][1] >> arr[0][2] >> arr[0][3];
    int acc = 0;
    int i = 0;
    while (i < 4) // #9 while цикл | для перебору всіх значень
    {
        long long l;
        cin >> l;
        arr[0][i] -= l;
        if (arr[0][i] >= 0)
        {
            arr[1][1] = *max_element(arr[0].begin(), arr[0].end());
            arr[1][0] = *min_element(arr[0].begin(), arr[0].end());

            if (arr[1][1] >= arr[1][0] * 2 || arr[1][0] == 0)
                acc = 1;
            i++;
            continue;// #11 оператори break і continue | для того щоб подальший код не виконувався
        }
        acc = 2;
        break;// #11 оператори break і continue | для того щоб передчасно вийти з циклу
    }

    cout << checker(acc);

    return 0;
}