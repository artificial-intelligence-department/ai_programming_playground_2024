#include <iostream>
#include <cmath>

int main() {
    double a, b, R;
    std::cout << "Enter the circle center coordinates (a, b): ";
    std::cin >> a >> b;
    std::cout << "Enter the circle radius R: ";
    std::cin >> R;

    double points[5][2];
    std::cout << "Enter the coordinates of 5 points (x, y):\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Point " << i + 1 << " (x, y): ";
        std::cin >> points[i][0] >> points[i][1];
    }

    std::cout << "\nResults:\n";
    for (int i = 0; i < 5; ++i) {
        double x = points[i][0];
        double y = points[i][1];
        double distanceSquared = (x - a) * (x - a) + (y - b) * (y - b);

        if (distanceSquared <= R * R) {
            std::cout << "Point " << i + 1 << " (" << x << ", " << y << ") is inside the circle.\n";
        } else {
            std::cout << "Point " << i + 1 << " (" << x << ", " << y << ") is outside the circle.\n";
        }
    }

    return 0;
}
