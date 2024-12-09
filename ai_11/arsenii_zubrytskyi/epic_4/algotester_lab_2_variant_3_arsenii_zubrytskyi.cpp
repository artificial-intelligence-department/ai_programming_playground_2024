#include <iostream>
#include <vector>
using namespace std;

// Функція для симуляції руху дронів
pair<pair<int, int>, string> simulateDrones(const vector<int>& arr, int n) {
    int left = 1;
    int right = n;  

    while (true) {
        // Перевірка до взльоту
        if (left == right) return {{left, right}, "Collision"};
        if (left + 1 == right) return {{left, right}, "Stopped"};
        if (left > right) return {{left, right}, "Miss"};

        // Взліт дронів
        left += arr[left - 1];  // Швидкість лівого дрона
        right -= arr[right - 1]; // Швидкість правого дрона

        // Перевірка після взльоту
        if (left == right) return {{left, right}, "Collision"};
        if (left + 1 == right) return {{left, right}, "Stopped"};
        if (left > right) return {{left, right}, "Miss"};
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto result = simulateDrones(arr, n);

    cout << result.first.first << " " << result.first.second << endl;
    cout << result.second << endl;

    return 0;
}
