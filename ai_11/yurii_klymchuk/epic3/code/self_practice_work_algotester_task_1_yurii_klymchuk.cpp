#include <iostream>
#include <vector>
using namespace std;
//Зуби
int main() {
    int n, k;//змінні для кількості зубів і коефіцієнту заточення відповідно
    cin >> n >> k;
    
    vector<int> a(n);//вектор для значення загострення кожного зуба
    int maxLength = 0;
    int currentLength = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= k) {//перевіряємо чи зуб достатньо заточений 
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } 
        else {
            currentLength = 0;
        }
    }
    cout << maxLength << endl;//виводимо кільсть підряд загострених зубів
    
    return 0;
}
