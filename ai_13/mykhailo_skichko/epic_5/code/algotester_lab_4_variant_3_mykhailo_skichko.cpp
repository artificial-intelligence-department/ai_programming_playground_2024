#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> rem0, rem1, rem2;

    for (int num : arr) {
        if (num % 3 == 0) {
            rem0.push_back(num);
        } else if (num % 3 == 1) {
            rem1.push_back(num);
        } else {
            rem2.push_back(num);
        }
    }

    // delete duplicates
    std::set<int> unique_rem0(rem0.begin(), rem0.end());
    rem0.assign(unique_rem0.begin(), unique_rem0.end());

    std::sort(rem1.rbegin(), rem1.rend());

    std::vector<int> filtered_rem2;
    for (int num : rem2) {
        if (num % 2 == 0) {
            filtered_rem2.push_back(num);
        }
    }
    std::sort(filtered_rem2.begin(), filtered_rem2.end());
    rem2 = filtered_rem2;

    std::vector<int> result;
    result.insert(result.end(), rem0.begin(), rem0.end());
    result.insert(result.end(), rem1.begin(), rem1.end());
    result.insert(result.end(), rem2.begin(), rem2.end());

    std::cout << result.size() << std::endl;
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
