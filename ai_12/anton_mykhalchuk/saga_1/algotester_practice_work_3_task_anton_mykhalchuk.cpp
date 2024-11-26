#include <iostream>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m;
    s = n * m;

    if (s % 2) {
        cout << "Imp";
    }
    else {
        cout << "Dragon";
    }
  
    return 0;
}
