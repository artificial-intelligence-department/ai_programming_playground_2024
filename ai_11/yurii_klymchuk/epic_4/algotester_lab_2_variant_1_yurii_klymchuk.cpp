#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //розмір дороги
    int N;
    cin >> N;
    
    //сторюємо вектор і вводимо значення відстані
    vector<int> r;
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        r.push_back(value);
    }
    
    //знаходимо максимальний та мінімальний елементи
    auto minimal = min_element(r.begin(), r.end());
    auto maximal = max_element(r.begin(), r.end());

    //створюємо ветор у якому видаляємо максимальний елемент і знаходимо відстань
    vector <int> copy_1 = r;
    auto it_1 = find(copy_1.begin(), copy_1.end(), *maximal);
    copy_1.erase(it_1);
    
    auto min_1 = min_element(copy_1.begin(), copy_1.end());
    auto max_1 = max_element(copy_1.begin(), copy_1.end());
    int difference_1 = *max_1 - *min_1;

    //створюємо ветор у якому видаляємо мінімальний елемент і знаходимо відставнь
    vector <int> copy_2 = r;
    auto it_2 = find(copy_2.begin(), copy_2.end(), *minimal);
    copy_2.erase(it_2);
    
    auto min_2 = min_element(copy_2.begin(), copy_2.end());
    auto max_2 = max_element(copy_2.begin(), copy_2.end());
    int difference_2 = *max_2 - *min_2;
    
    //порівнюємо два елементи і виводимо менший
    cout << min(difference_1, difference_2);
    return 0;
}