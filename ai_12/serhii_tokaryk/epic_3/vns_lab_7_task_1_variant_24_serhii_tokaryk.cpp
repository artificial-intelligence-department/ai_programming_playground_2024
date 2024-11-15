#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdarg>

using namespace std;


struct point{
    int x , y;
    point(int x , int y) : x(x) , y(y) { };
};

int length(point& p1, point& p2){
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int square(point& A, point& B, point& C) {
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

double squarenHelper(const vector<point>& points, int i, double currentArea) {
    int n = points.size();
    if (i == n) { 
        return abs(currentArea) / 2.0;
    }

    int j = (i + 1) % n;
    currentArea += points[i].x * points[j].y - points[j].x * points[i].y;
    return squarenHelper(points, i + 1, currentArea);
}

double squaren(int count, ...) {
    va_list argptr;
    va_start(argptr, count);

    vector<point> points;
    for (int i = 0; i < count / 2; i++) {
        int x = va_arg(argptr, int);
        int y = va_arg(argptr, int);
        points.emplace_back(x, y);
    }

    va_end(argptr);

    return squarenHelper(points, 0, 0.0);
}
                                                                                         
int main() {
    point A = {0, 0};
    point B = {3, 0};
    point C = {3, 4};
    
    cout << "Довжина сторони AB: " << length(A, B) << endl;
    cout << "Площа трикутника ABC: " << square(A, B, C) << endl;

    vector<point> polygon = {{0, 0}, {3, 0}, {3, 4}, {0, 4}};
    cout << "Площа багатокутника: " << squaren(8,0,0,3,0,3,4,0,4) << endl;

    return 0;
}