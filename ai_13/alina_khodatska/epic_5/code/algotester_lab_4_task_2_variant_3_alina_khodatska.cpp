#include <iostream>
#include <vector>
#include <algorithm>

// Сортування за зростанням
void sort0(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end()); 
}

// Сортування за спаданням
void sort1(std::vector<int>& arr) {
    std::sort(arr.rbegin(), arr.rend());  
}

// Перевірка на унікальність
bool isUnique(const std::vector<int>& arr, int num) {
    return std::find(arr.begin(), arr.end(), num) == arr.end();
}

int main() {
    int N;
    std::cin >> N;

	std::vector<int> arr(N); // Масив чисел розміром N для зберігання введених чисел
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

	std::vector<int> part0, part1, part2; // Масиви для зберігання чисел за залишком 0, 1, 2

    // Розділяємо масив за залишком при діленні на 3
    for (int num : arr) {
        if (num % 3 == 0) part0.push_back(num);
        else if (num % 3 == 1) part1.push_back(num);
        else part2.push_back(num);
    }

    // Сортуємо частини
    sort0(part0);
    sort1(part1);
    sort0(part2);

    // Об'єднуємо масиви
    std::vector<int> result;
    result.insert(result.end(), part0.begin(), part0.end());
    result.insert(result.end(), part1.begin(), part1.end());
    result.insert(result.end(), part2.begin(), part2.end());

    // Видаляємо дублікати
    std::vector<int> unique_result;
    for (int num : result) {
        if (isUnique(unique_result, num)) {
            unique_result.push_back(num);
        }
    }

    // Виводимо результат
    std::cout << unique_result.size() << "\n";
    for (int num : unique_result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
