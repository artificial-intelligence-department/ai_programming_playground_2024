/*Задано масив a із n цілих чисел. Потрібно відповісти на m запитів, кожен з яких одного із двох типів:
1. знайти суму елементів масиву на проміжку від l до r включно,
2. додати число d до i-го елементу масиву.*/

#include <iostream>
#include <vector>

void first(const std::vector<int>& prefix_sum){
    int l, r;
    std::cin >> l >> r;
    int sum = prefix_sum[r] - prefix_sum[l-1];
    std::cout << sum << "\n";
}

int main(){
    int n, m, request;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    std::vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }
    for (int j = 0; j < m; j++) {
        std::cin >> request;
        if (request == 1) {
            first(prefix_sum);
        } else {
            int i, d;
            std::cin >> i >> d;
            a[i-1] += d;
            for (int k = i; k <= n; k++) {
                prefix_sum[k] += d;
            }
        }
    }
    return 0;
}
