#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cave(N);

    
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    
    for (int j = 0; j < M; ++j) {
        int bottom = N; 

        // Обробляємо стовпець зверху вниз
        for (int i = N - 1; i >= 0; --i) {
            if (cave[i][j] == 'X') {
                bottom = i; 
            } else if (cave[i][j] == 'S') {
                
                cave[i][j] = 'O';      
                cave[--bottom][j] = 'S'; 
            }
        }
    }

    
    for (int i = 0; i < N; ++i) {
        cout << cave[i] << endl;
    }

    return 0;
}
