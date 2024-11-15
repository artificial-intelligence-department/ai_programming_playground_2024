#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double distance(double x1, double y1, double x2, double y2);
double area(double x1, double y1, double x2, double y2, double x3, double y3);
bool belong(double xM, double yM, double x1, double y1, double x2, double y2, double x3, double y3);
bool isPointInPolygon(double xM, double yM, const vector<double>& vertices);

int main() {
    double xM = 1;
    double yM = 1;
    vector<double> vertices = {0, 3, 1, 2, 5, 2.2};

    if (vertices.size() == 6) {  
        if (belong(xM, yM, vertices[0], vertices[1], vertices[2], vertices[3], vertices[4], vertices[5])) {
            cout << "Точка M належить трикутнику." << endl;
        } else {
            cout << "Точка M не належить трикутнику." << endl;
        }
    } else {
        if (isPointInPolygon(xM, yM, vertices)) {
            cout << "Точка M належить багатокутнику." << endl;
        } else {
            cout << "Точка M не належить багатокутнику." << endl;
        }
    }

    return 0;
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool belong(double xM, double yM, double x1, double y1, double x2, double y2, double x3, double y3){
    double ABC = area(x1, y1, x2, y2, x3, y3);
    double MAB = area(xM, yM, x1, y1, x2, y2);
    double MBC = area(xM, yM, x2, y2, x3, y3);
    double MAC = area(xM, yM, x1, y1, x3, y3);

    return fabs(ABC - (MAB + MBC + MAC));
}

bool isPointInPolygon(double xM, double yM, const vector<double>& vertices){
    int n = vertices.size() / 2;
    for (int i = 0; i < n; ++i) {
        double xA = vertices[2 * i];
        double yA = vertices[2 * i + 1];
        double xB = vertices[2 * ((i + 1) % n)]; 
        double yB = vertices[2 * ((i + 1) % n) + 1];
        if (!belong(xM, yM, xA, yA, xB, yB, vertices[0], vertices[1])) {
            return false;
        }
    }
    return true;
}
