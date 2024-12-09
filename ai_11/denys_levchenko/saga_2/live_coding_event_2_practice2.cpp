#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void creatematrix(double matrix[5][5]){
    srand(time(0));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] = rand() % 5;
        }
    }
}

void printmatrix(double matrix[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }

}

void findmaxelementinrow(double matrix[5][5]){
    double max[5];
    for(int row = 0; row < 5; row++){
        max[row] = matrix[row][0];
        for(int j = 0; j < 5; j++){
            if(matrix[row][j] > max[row]){
                max[row] = matrix[row][j];
            }
        }
    cout << "Max element in row " << row+1 << " is " << max[row] << endl;
    }
}

void findminelementinrow(double matrix[5][5]){
    double min[5];
    for(int row = 0; row < 5; row++){
        min[row] = matrix[row][0];
        for(int j = 0; j < 5; j++){
            if(matrix[row][j] < min[row]){
                min[row] = matrix[row][j];
            }
        }
    cout << "Min element in row " << row+1 << " is " << min[row] << endl;
    }
}

void findmaxelementinstovbec(double matrix[5][5]){
    double max[5];
    for(int stovbec = 0; stovbec < 5; stovbec++){
        max[stovbec] = matrix[0][stovbec];
        for(int j = 0; j < 5; j++){
            if(matrix[j][stovbec] > max[stovbec]){
                max[stovbec] = matrix[j][stovbec];
            }
        }
    cout << "Max element in stovbec " << stovbec+1 << " is " << max[stovbec] << endl;
    }
}

void findminelementinstovbec(double matrix[5][5]){
    double min[5];
    for(int stovbec = 0; stovbec < 5; stovbec++){
        min[stovbec] = matrix[0][stovbec];
        for(int j = 0; j < 5; j++){
            if(matrix[j][stovbec] < min[stovbec]){
                min[stovbec] = matrix[j][stovbec];
            }
        }
    cout << "Min element in stovbec " << stovbec+1 << " is " << min[stovbec] << endl;
    }
}


void task2(double matrix[5][5]) {
    double resultMatrix[5][5];
    int row = 0;
    for(int j = 4; j >= 0; j--) {
        if(j % 2 == 0) {
            for(int k = 4; k >= 0; k--) {
                resultMatrix[row][4 - j] = matrix[k][j];
                row++;
            }
        } else {
            for(int k = 0; k < 5; k++) {
                resultMatrix[row][4 - j] = matrix[k][j];
                row++;
            }
        }
        row = 0;
    }

    double transposedMatrix[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            transposedMatrix[j][i] = resultMatrix[i][j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << transposedMatrix[j][i] << " ";
        }
        cout << endl;
    }
} 
void task3(double matrix[5][5]){
        for(int j = 4; j >= 0; j--){
            if(j%2 == 0){
                for(int k = 4; k >= 0; k--){
                    cout << matrix[j][k] << " ";
                }
                cout << endl;
            }

            else{
                for(int k = 0; k < 5; k++){
                    cout << matrix[j][k] << " ";
                }
                cout << endl;   
            }            
    }
}

int main(){
    double matrix[5][5];
    cout << "Matrix: " << endl;
    creatematrix(matrix);
    printmatrix(matrix);
    cout << endl;
    findmaxelementinrow(matrix);
    cout << endl;
    findminelementinrow(matrix);
    cout << endl;
    findmaxelementinstovbec(matrix);
    cout << endl;
    findminelementinstovbec(matrix);
    cout << endl << "Matrix from task2: " << endl;
    task2(matrix);
    cout << endl << "Matrix from task3: " << endl;
    task3(matrix);
}