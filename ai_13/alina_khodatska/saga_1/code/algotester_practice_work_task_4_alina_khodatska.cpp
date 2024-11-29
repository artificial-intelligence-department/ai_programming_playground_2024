#include <iostream>
#include <vector>
#include <queue> 

int main() {
    int n;
    std::cin >> n;

    std::vector<int> infected(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> infected[i];
    }

    std::queue<int> q;
    std::vector<int> time(n, -1);

    for (int i = 0; i < n; ++i) {
        if (infected[i] == 1) {
            q.push(i);
            time[i] = 0;
        }
    }

    int max_time = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = -1; i <= 1; i += 2) {
            int neighbor = (current + i + n) % n;
            if (time[neighbor] == -1) {
                time[neighbor] = time[current] + 1;
                max_time = std::max(max_time, time[neighbor]);
                q.push(neighbor);
            }
        }
    }

    std::cout << max_time << std::endl;
    return 0;
}
