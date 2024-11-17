#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string* all_drinks = new string[n + m]; 
    string drink;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> drink;
        all_drinks[count++] = drink;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> drink;
        all_drinks[count++] = drink;
    }
    
    int unique_count = 0;
    bool is_unique;
    
    for (int i = 0; i < count; i++) {
        is_unique = true;

        for (int j = 0; j < i; j++) {
            if (all_drinks[i] == all_drinks[j]) {
                is_unique = false;
                break;
            }
        }

        if (is_unique) {
            unique_count++;
        }
    }
    
    cout << unique_count << endl;

    delete[] all_drinks;

    return 0;
}
