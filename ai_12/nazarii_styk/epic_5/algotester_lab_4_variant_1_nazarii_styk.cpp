#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() 
{
    int N, M;

    // Введення першого масиву
    std::cin >> N;
    std::vector<int> array1(N);
    for (int i = 0; i < N; ++i) 
    {
        std::cin >> array1[i];
    }

    // Введення другого масиву
    std::cin >> M;
    std::vector<int> array2(M);
    for (int i = 0; i < M; ++i) 
    {
        std::cin >> array2[i];
    }

    // Сортування обох масивів для правильного виконання операцій STL
    std::sort(array1.begin(), array1.end());
    std::sort(array2.begin(), array2.end());

    std::vector<int> result;

    // 1. Різниця N-M
    std::set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(result));
    std::cout << result.size() << "\n";
    for (int num : result) std::cout << num << " ";
    std::cout << "\n";
    result.clear();

    // 2. Різниця M-N
    std::set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), std::back_inserter(result));
    std::cout << result.size() << "\n";
    for (int num : result) std::cout << num << " ";
    std::cout << "\n";
    result.clear();

    // 3. Перетин
    std::set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(result));
    std::cout << result.size() << "\n";
    for (int num : result) std::cout << num << " ";
    std::cout << "\n";
    result.clear();

    // 4. Об'єднання
    std::set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(result));
    std::cout << result.size() << "\n";
    for (int num : result) std::cout << num << " ";
    std::cout << "\n";
    result.clear();

    // 5. Симетрична різниця
    std::set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(result));
    std::cout << result.size() << "\n";
    for (int num : result) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
// Ваше завдання вивести:
// 1. Різницю N-M
// 2. Різницю M-N
// 3. Їх перетин
// 4. Їх обєднання
// 5. Їх симетричну різницю