#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, q;
    cin >> a;

    int numbers[a][a];
    int numbers_possible[a + 1];

    for (int i = 1; i <= a; i++){
        numbers_possible[i] = i;
    }

    for (int i = 0; i < a; i++){
        string row;
        cin >> row;
        for (int j = 0; j < a; j++){
            numbers[i][j] = row[j] - '0';
        }
    }

    cin >> q;
    int coordinates[q][2];
        
    for (int i = 0; i < q; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
        coordinates[i][0]--;
        coordinates[i][1]--;
    }
    
    for (int i = 0; i < q; i++){
        int row = coordinates[i][0];
        int col = coordinates[i][1];
            
        if (numbers[row][col] == 0){
            int copy_numbers_possible[a + 1];
            for (int j = 1; j <= a; j++){
                copy_numbers_possible[j] = numbers_possible[j];
            }
            
            for (int j = 0; j < a; j++){
                if (numbers[row][j] > 0){
                    copy_numbers_possible[numbers[row][j]] = 0;
                }
                if (numbers[j][col] > 0){
                    copy_numbers_possible[numbers[j][col]] = 0;
                }
            }
                
            
            int count = 0;
            for (int j = 1; j <= a; j++){
                if (copy_numbers_possible[j] != 0) {
                    count++;
                }
            }
                
            cout << count << endl;
            for (int j = 1; j <= a; j++){
                if (copy_numbers_possible[j] != 0){
                    cout << copy_numbers_possible[j] << " ";
                }
            }
            cout << endl << endl;
        }else{
            cout << "1" << endl;
            cout << numbers[row][col] << endl << endl;
        }
    }

    return 0;
}
