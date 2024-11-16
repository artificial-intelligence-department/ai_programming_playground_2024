 #include <iostream>
#include <cmath>

using namespace std;


double l(double x1, double y1, double x2, double y2) {

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


bool belong(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3) {

    double abc = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);

    double abm = abs((x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2)) / 2.0);

    double acm = abs((x1 * (y - y3) + x3 * (y3 - y1) + x * (y1 - y3)) / 2.0);

    double bcm = abs((x2 * (y - y3) + x3 * (y3 - y2) + x * (y2 - y3)) / 2.0);

    return (abm + acm +bcm == abc);
}


bool p(double x, double y, double vertices[][2], int numVertices) {

    bool inside = false;

    for (int i = 0, j = numVertices - 1; i < numVertices; j = i++) {

        if (((vertices[i][1] > y) != (vertices[j][1] > y)) &&(x < (vertices[j][0] - vertices[i][0]) * (y - vertices[i][1]) / (vertices[j][1] - vertices[i][1]) + vertices[i][0])) {

            inside = !inside;
        }
    }
    return inside;
}

int main() {
   
    double ab = l(1, 1, 4, 1);

    cout << "AB: " << ab<< endl;

    
    bool t = belong(2, 2, 1, 1, 4, 1, 2, 4);

    cout << "M(2, 2) � ABC? " << (t ? "Yes" : "No") << endl;


    double v[][2] = { {0, 0}, {4, 0}, {4, 4}, {0, 4} }; 

    bool P = p(2, 2, v, 4);

    cout << "Does the point M(2, 2) belong to a polygon?? " << (P ? "Yes" : "No") << endl;



    return 0;
}
