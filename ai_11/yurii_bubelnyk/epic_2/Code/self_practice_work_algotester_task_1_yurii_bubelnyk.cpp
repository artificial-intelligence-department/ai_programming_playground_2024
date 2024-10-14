#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int total_cells = N * M;
    
    
    if (total_cells % 2 == 1) {
        cout << "Imp" << endl;
    } else {
        cout << "Dragon" << endl;
    }
    
    return 0;
}
