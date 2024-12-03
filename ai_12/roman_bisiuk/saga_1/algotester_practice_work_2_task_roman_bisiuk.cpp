#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; 

    int bills[] = {500, 200, 100, 50, 20, 10, 5, 2, 1}; 
    int count = 0;

    for (int i = 0; i < 9; i++) { 
        count += n / bills[i]; 
        n %= bills[i];         

        if (n == 0)                   
            break;
    }

    cout << count << endl; 
    return 0;
}
