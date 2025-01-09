#include <iostream>
#include <climits>

void function_2(int tower[5][5]) {

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <5; ++j) {
            tower[i][j] = rand() % 100 + 1;
        }
    }
}

void function_3(int tower[5][5], int result[5]) {

    for (int j = 0; j < 5; ++j) {
        for (int j = 0; j <5; ++j) {
            int min1 = INT_MAX;
            for ( int i = 0; i < 5; ++i) {
                if (tower[i][j] < min1) {
                    min1 = tower[i][j];
                }
            }
            result[j] = min1;
        }

for (int j = 0; j < 5; ++j) {
    int min2 = tower[0][j];
    for (int i = 1; i < 5; ++i) {
        if (tower[i][j] < min2) {
            min2 = tower[i][j];
        }
    }

    if (result[j] == min2) {
        std::cout << "Результат для стовпця " << j +1 << "співпали: " << result << std::endl;
    } else {
        std::cout << "Результат для стовпця " << j +1 << "не співпали: " << result << std::endl;
    }
}


    }
}
    int main() {

        int tower[5][5];

        function_2(tower);

        int result[5];

        function_3(tower, result);

        return 0;
    
}

