/*
2.  Обчислити значення виразів. Пояснити отримані результати. 
1)  --m - ++n 2)  m*n<n++ 3)  n-- > m++ 
*/

#include "iostream"
using namespace std;
int main(){
    int m, n, first;
    
    cout << "Input m, n: ";
    cin >> m >> n;
    bool second, third;
    first = --m - ++n;//Спочатку унарні оператори а потім віднімання
    printf("1) --m - ++n = %d  (m = %d, n = %d)\n", first, m, n);

    second = m*n < n++;// Спочатку порівняння а потім унарний оператор
    printf("2) m*n<n++ = %hhu  (m = %d, n = %d)\n", second, m, n);

    third = n-- > m++;// Спочатку порівняння а потім унарні оператори
    printf("3) n-- > m++ = %hhu  (m = %d, n = %d)\n", third, m, n);


    return 0;
}