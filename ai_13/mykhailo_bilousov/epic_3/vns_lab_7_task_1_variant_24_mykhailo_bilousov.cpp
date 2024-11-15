#include <iostream>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

#define LEN(a,b) (sqrt(pow((b)[0]-(a)[0],2)+pow((b)[1]-(a)[1],2)))

template<typename T>
T square(array<T,2> a, array<T,2> b, array<T,2> c) { // heron's formula
    T A = LEN(b,c);
    T B = LEN(a,c);
    T C = LEN(a,b);
    T S = (A+B+C)/2;
    T area = sqrt(S*(S-A)*(S-B)*(S-C));
    return area;
}

template<typename T>
T squaren(vector<array<T,2>> points) { // shoelace algorithm
    T area = 0;
    int last = points.size()-1;
    for(int i = 0; i < last; i++) {
        area += points[i][0]*points[i+1][1];
        area -= points[i][1]*points[i+1][0];
    }
    area += points[last][0]*points[0][1];
    area -= points[last][1]*points[0][0];
    return fabs(area/2);
}

int main() {
    vector<array<double,2>> triangle = { // area 4.5
        {0,0}, {0,3}, {3,3}
    };
    vector<array<double,2>> poly = {
        {1.03,1},{0,2.007},{1.7223,4},{2.11,5},{6.2,5.02},{3.15,3},{1,1.35}
    };

    cout << square(triangle[0],triangle[1],triangle[2]) << endl;
    cout << squaren(triangle) << endl;
    cout << squaren(poly) << endl;
}