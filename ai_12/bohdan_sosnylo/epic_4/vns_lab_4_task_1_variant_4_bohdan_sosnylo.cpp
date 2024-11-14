#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    const int N = 100;  
    int a[N];           
    int n;       

   spw:
    cout << "Введіть реальну довжину масиву (не більше " << N << "): ";
    cin >> n;

    if (n < 1 || n > N) {
        cout << "шось не то, спробуй ше раз" << endl;
        goto spw;
        return 1;
    }

    srand(time(0));  

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 2001 - 1000; // рандомні елементи з проміжку [-1000; 1000] 
    }

    cout << "Оригінальний масив: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int news = 0;
    int a1[N];  

    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {  
            a1[news] = a[i];
            news++;
        }
    }

    int kins = 0;
    int a2[N];  

    for (int i = 0; i < news; i++) {
        a2[kins] = a1[i];
        kins++;

        if (a1[i] < 0) {
            a2[kins] = abs(a1[i] + 1);
            kins++;
        }
    }

    cout << "Оновлений масив: ";
    for (int i = 0; i < kins; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;

    return 0;
}
