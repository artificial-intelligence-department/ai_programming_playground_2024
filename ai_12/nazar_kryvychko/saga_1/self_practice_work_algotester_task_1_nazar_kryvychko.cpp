#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int crossProduct(const Point &A, const Point &B, const Point &C) {
    int x1 = B.x - A.x;
    int y1 = B.y - A.y;
    int x2 = C.x - B.x;
    int y2 = C.y - B.y;
    return x1 * y2 - y1 * x2;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);

    // Зчитуємо координати всіх точок маршруту
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int leftTurns = 0, rightTurns = 0;

    // Обчислюємо повороти між кожними трьома послідовними точками
    for (int i = 0; i < n - 2; i++) {
        int cp = crossProduct(points[i], points[i + 1], points[i + 2]);
        if (cp > 0) {
            leftTurns++;
        } else if (cp < 0) {
            rightTurns++;
        }
    }

    cout << leftTurns << " " << rightTurns << endl;

    return 0;
}

