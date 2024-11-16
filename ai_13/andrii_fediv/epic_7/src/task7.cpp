#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long prev = -1;
    for (int i = 0; i < 5; i++)// #10  for цикл / отримування певної кількості значень від користувача
    {
        long long a;
        cin >> a;
        if(a <= 0){// #5  умовні оператори та розгалуження / для перевірки умови 
            cout << "ERROR";
            return 0;
        } else if (a > prev && prev != -1){// #5  умовні оператори та розгалуження / для перевірки умови якщо перша не справдилась
            cout << "LOSS";
            return 0;
        } 
        prev = a;
    }
    cout << "WIN";


    return 0;
}