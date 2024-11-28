#include <iostream>
#include <cstdarg>  // Для еліпса і доступу до тих даних
#include <vector>

using namespace std;

/* властивість яка доводе шо то трикутник(3 умови бо не знаєм side.max

 тоді ше треба було новий вектор і сортування посортувати)*/
bool canFormTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void triangle(int k, ...) {
    va_list args;
    va_start(args, k);  

    vector<int> sides;  // переходим до вектора бо з va_ не зручно

    // Збираємо всі параметри в вектор
    for (int i = 0; i < k; i++) {
        int side = va_arg(args, int);  
        sides.push_back(side);
    }

    va_end(args);  // Завершуємо роботу зі списком параметрів

    // складаєм пари по три в завданні писало кожне число з сусідніми
    for (int j = 0; j < k - 2; j++) {
        int a = sides[j];
        int b = sides[j + 1];
        int c = sides[j + 2];

        if (canFormTriangle(a, b, c)) {
            cout << a << " " << b << " " << c << " - yes" << endl;
        } else {
            cout << a << " " << b << " " << c << " - no" << endl;
        }
    }
}   // функція нічо не вертає тому без return

int main() {
        cout << "test 1: " << endl;
    triangle(3, 3, 5, 7);

        cout << "test 2: " << endl;
    triangle(9, 1, 2, 3, 4, 3, 6, 2, 8, 9);

        cout << "test 3: " << endl;
    triangle(11, 1, 2, 3, 4, 3, 6, 2, 8, 9, 6, 3);    

    return 0;
}