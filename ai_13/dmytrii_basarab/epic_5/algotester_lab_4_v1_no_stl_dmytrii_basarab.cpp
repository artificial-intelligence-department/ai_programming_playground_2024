#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функція для виведення масиву
void output( vector<int>& arr)
{
    sort(arr.begin(), arr.end());      // Спочатку сортуємо масив
    arr.erase(unique(arr.begin(), arr.end()), arr.end());  // Видаляємо дублікати

    cout << arr.size() << endl;
    for (int el : arr)
        cout << el << " ";
    cout << endl;
}

int main() {
    int N_size, M_size;
    cin >> N_size;
    
    vector<int> N(N_size);
    for (int i = 0; i < N_size; i++) {
        cin >> N[i];
    }
    
    cin >> M_size;
    
    vector<int> M(M_size);
    for (int i = 0; i < M_size; i++) {
        cin >> M[i];
    }
    
    // N - M
    vector<int> diff1;
    for (int n : N) {
        bool found = false;
        for (int m : M) {
            if (n == m) {
                found = true;
                break;//елемент з М є в масиві N то не додаєм
            }
        }
        if (found==false) {
            diff1.push_back(n);
        }
    }
    cout << "Різниця n / m: ";
    output(diff1);
    
    //  M - N
    vector<int> diff2;
    for (int m : M) {
        bool found = false;
        for (int n : N) {
            if (m == n) {
                found = true;
            }
        }
        if (found==false) {
            diff2.push_back(m);
        }
    }
    cout << "Різниця m / n: ";
    output(diff2);
    
    // Перетин
    vector<int> peretin;
    for (int n : N) {
        for (int m : M) {
            if (n == m) {//якшо елемент з N є в масиві M то додаєм 
                peretin.push_back(n);
            }
        }
    }
    cout << "перетин: ";
    output(peretin);
    
    // Об’єднання
    vector<int> uni;
    for (int a:N) {
        uni.push_back(a);
    }

    for (int m : M) {
        bool found = false;
        for (int n : N) {
            if (m == n) {
                found = true;
                break; //скіпає однакові значення
            }
        }
            uni.push_back(m);//якшо елементу нема в N то додаєм його до N і буде перетин
    }
    cout << "обєднання: ";
    output(uni);
    
    // Симетрична різниця то обєднання a/b i b/a
    vector<int> sym_diff;
   for (int a : diff1) {
        sym_diff.push_back(a);
    }

    for (int m : diff2) {
        bool found = false;
        for (int n : diff1) {
            if (m == n) {
                found = true;
                break; //скіпає однакові значення
            }
        }
            sym_diff.push_back(m);//якшо елементу нема в N то додаєм його до N і буде перетин
    }
    cout << "симетрична різниця: ";
    output(sym_diff);
    
    return 0;
}