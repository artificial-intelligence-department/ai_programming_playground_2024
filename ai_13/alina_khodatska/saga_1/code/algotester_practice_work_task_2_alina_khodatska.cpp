#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int minutes = (n + 59) / 60;

    int cost = 11;

    if (minutes <= 7) {
        cost += minutes * 9;
    }
    else {
        cost += 7 * 9;
        cost += (minutes - 7) * 5;
    }

    std::cout << cost << std::endl;

    return 0;
}
