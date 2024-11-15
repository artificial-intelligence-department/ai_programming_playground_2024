#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <cstdarg>

using namespace std;


double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double square(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x3, y3, x2, y2);
    
    double p = (a + b + c)/2.0;
    
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

double square1(int num_cords, ...) {
    if (num_cords < 3) {
        cerr << "Not enough points to form a polygon" << endl;
        return 0;
    }

    va_list args;
    va_start(args, num_cords);

    vector<int> cords;
    for (int i = 0; i < num_cords; i++) {
         int x = va_arg(args, int);
         cords.push_back(x);
    }
    va_end(args);

    vector<pair<double, double>> points;
    for (int i = 0; i < num_cords/2; i++) {
        double x = cords[i];
        double y = cords[i + 1];
        points.emplace_back(x, y);
    }

    int n = points.size();
    double max_diagonal = 0;
    pair<int, int> max_diagonal_points = {0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = distance(points[i].first, points[i].second, points[j].first, points[j].second);
            if (d > max_diagonal) {
                max_diagonal = d;
                max_diagonal_points = {i, j};
            }
        }
    }

    double max_area = 0;
    int a = max_diagonal_points.first;
    int b = max_diagonal_points.second;

    for (int i = 0; i < n; i++) {
        if (i != a && i != b) {
            double area = square(points[a].first, points[a].second,
                                       points[b].first, points[b].second,
                                       points[i].first, points[i].second);
            if (area > max_area) {
                max_area = area;
            }
        }
    }

    return max_area;
}

int main() {
    
    vector<pair<double, double>> points = {{0, 0}, {5, 0}, {3, 4}, {6, 6}};
    
    cout << "Edge length: " << distance(0.0, 0.0, 5.0, 0.0) << endl;
    cout << "Area of a triangle: " << square(0, 0, 5, 0, 3, 4) << endl;
    cout << "Area of the triangle with the longest diagonal: " << square1(8, 0, 0, 5, 0, 3, 4, 6, 6) << endl;

    return 0;
}
