#include <iostream>
using namespace std;

int main() {
    const long long LIMIT = 1000000000000;
    long long edge1, edge2, edge3, edge4, edge5;

    cin >> edge1 >> edge2 >> edge3 >> edge4 >> edge5;

    if (edge1 <= -LIMIT || edge1 >= LIMIT || 
        edge2 <= -LIMIT || edge2 >= LIMIT ||
        edge3 <= -LIMIT || edge3 >= LIMIT ||
        edge4 <= -LIMIT || edge4 >= LIMIT ||
        edge5 <= -LIMIT || edge5 >= LIMIT) {
        return 0;
    } else {
        if (edge1 <= 0) {
            cout << "ERROR" << endl;
            return 0;
        } else if (edge2 <= 0) {
            cout << "ERROR" << endl;
            return 0;
        } else if (edge2 > edge1) {
            cout << "LOSS" << endl;
            return 0;
        }

        if (edge3 <= 0) {
            cout << "ERROR" << endl;
            return 0;
        } else if (edge3 > edge2) {
            cout << "LOSS" << endl;
            return 0;
        }

        if (edge4 <= 0) {
            cout << "ERROR" << endl;
            return 0;
        } else if (edge4 > edge3) {
            cout << "LOSS" << endl;
            return 0;
        }

        if (edge5 <= 0) {
            cout << "ERROR" << endl;
            return 0;
        } else if (edge5 > edge4) {
            cout << "LOSS" << endl;
            return 0;
        }
    }

    cout << "WIN" << endl;
    return 0;
}









