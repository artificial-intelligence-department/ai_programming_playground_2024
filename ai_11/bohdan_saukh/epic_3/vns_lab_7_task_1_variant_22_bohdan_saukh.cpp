#include <iostream>
#include <cmath>

using namespace std;

#define pi 3.14159265

long double triangle(long double s[]){
    long double p = (s[0]+s[1]+s[2])/2;
    long double area = sqrt(p*(p-s[0])*(p-s[1])*(p-s[2]));
    return (area);
}

long double square(int n) {
    long double ang = 0;
    long double angr = 0;
    
    long double sides[n];
    long double angles[n];
    long double xv[n];
    long double yv[n];
    
    long double gauss1 = 0;
    long double gauss2 = 0;

    for (int i = 0; i < n; i++) {
        cin >> sides[i];
        cin >> angr;
        ang += angr;
        angles[i] = (ang * pi / 180.0);
        angr = 0;
    }

    xv[0] = 0;
    yv[0] = 0;
    
    for (int i = 1; i < n; i++) {
        xv[i] = xv[i-1] + cos(angles[i-1]) * sides[i-1];
        yv[i] = yv[i-1] + sin(angles[i-1]) * sides[i-1];
    }

    for (int i = 1; i < n; i++) {
        gauss1 += xv[i-1] * yv[i];
        gauss2 += yv[i-1] * xv[i];
        if (i == n-1) {
            gauss1 += xv[i] * yv[0];
            gauss2 += yv[i] * xv[0];
        }
    }
    cout << "Area = ";
    
    return (gauss1 - gauss2) / 2;
}

int main() {
    int n;
    long double s[3];
    int choose = 2;
    do{
        cout << "Choose an option: poligon area(0), triangle area(1) or exit(-1)" << endl;
        cin >> choose;
        if(choose == 0){
            cout << "enter the number of sides: " << endl;
            cin >> n;
            cout << "enter the sides and adjacent angles (side angle): " << endl;
            cout << square(n) << endl;
        }
        if(choose == 1){
            cout << "Enter the sides of triangle" << endl;
            for (int i = 0; i < 3; i++){
                cin >> s[i];
            }
            cout << "Area = " << triangle(s) << endl;
        }
    }while (choose != -1);   
    if (choose == -1){
        return 0;
    }    
}