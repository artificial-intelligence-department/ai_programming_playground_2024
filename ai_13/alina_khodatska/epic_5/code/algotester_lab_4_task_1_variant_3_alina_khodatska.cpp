#include <iostream>
#include <vector>
#include <algorithm>

bool compare0(int a, int b) {
    return a < b;
}

bool compare1(int a, int b) {
    return a > b;
}

int main() {
    int N;
    std::cin >> N;

	std::vector<int> arr(N);  // Масив чисел розміром N для зберігання введених чисел
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Розділяємо масив на три частини: за залишком 0, 1, 2
    std::vector<int> part0, part1, part2;
    for (int num : arr) {
        if (num % 3 == 0) part0.push_back(num);
        else if (num % 3 == 1) part1.push_back(num);
        else part2.push_back(num);
    }

    // Сортуємо частини
    std::sort(part0.begin(), part0.end(), compare0);  // За зростанням для залишку 0
    std::sort(part1.begin(), part1.end(), compare1);  // За спаданням для залишку 1
    std::sort(part2.begin(), part2.end(), compare0);  // За зростанням для залишку 2

    // Об'єднуємо масиви
    part0.insert(part0.end(), part1.begin(), part1.end());
    part0.insert(part0.end(), part2.begin(), part2.end());

    // Видаляємо дублікати
    part0.erase(std::unique(part0.begin(), part0.end()), part0.end());

    // Виводимо результат
    std::cout << part0.size() << "\n";

	for (int num : part0) { // цикл для виведення чисел масиву
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
