#include <iostream>
#include <vector>
#include <array>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> points;
    std::vector<std::vector<std::array<int, 2>>> lines(n - 1);
    int x, y;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        points.push_back({ x, y });
    }
    for (int i = 0; i < n - 1; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            if (lines[i].size() != 0) {
                for (auto& val : lines[i]) {
                    if ((x2 - x1) * val[1] == (y2 - y1) * val[0]) goto jump;
                }
                if (false) {
                jump:
                    continue;
                }
            }
            lines[i].push_back({x2 - x1, y2 - y1});
        }
    }
    int result = 0;
    for (int i = 0; i < n - 1; i++) result += lines[i].size();
    std::cout << result;
    
}

