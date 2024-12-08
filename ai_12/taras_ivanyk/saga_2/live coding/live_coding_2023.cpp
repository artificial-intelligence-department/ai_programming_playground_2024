#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <cmath>
using namespace std;

const int pull = 435;
const int col = 10;
const int row = 10;
const string FILE_NAME = "sums.txt";

void create_matrix(int matrix[row][col]){
    
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(i == j) { matrix[i][j] = -1234;} // -1234 = error
            else matrix[i][j] = (i - j) * (j - ((-3.4) / (j - i))) / (1 + pow(j-i, 2)); // VNS_Task_1_fi
        }
    }
}

template<typename T>
void print_matrix(T matrix[row][col]){  // T matrix - so we can work with int/double/float matrix
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cout << setprecision(3) << matrix[i][j] << setw(8) << " ";
        }
        cout << endl;
    }
}

void create_matrix(double matrix[row][col]){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(i == j) { matrix[i][j] = -1234.0;} 
            else matrix[i][j] = (i - j) * (j - ((-3.4) / (j - i))) / (1 + pow(j-i, 2)); 
        }
    }
}

void buble_sort(double matrix[row][col]){
    for(int j = 0; j < col; ++j){
        for(int k = 0; k < row - 1; ++k){
            for(int i = 0; i < row - k - 1; ++i){
                if(matrix[i][j] > matrix[i + 1][j]){
                    swap(matrix[i][j], matrix[i + 1][j]);
                }
            }
        }
    }
}

void sum_of_random_elements(double matrix[row][col], int sums[col]){
    srand(static_cast<unsigned int>(time(nullptr)));  

    for (int j = 0; j < col; ++j) {
        int num_elements = rand() % 2 + 3;  // 3 or 4 elements
        int sum = 0;
        int count = 0;

        for (int i = 0; i < row && count < num_elements; ++i) {
            if (matrix[i][j] != -1234) {  // in my code -1234 means - Error, because in the first matrix with integers we have -1, thet usually means error in smbd code  
                sum += static_cast<int>(matrix[i][j]);  // just integers, not float or double
                count++;
            }
        }
        sums[j] = sum;  
    }
    cout << "\nSums of 3 or 4 random taken elements from each column:\n";
    for (int j = 0; j < col; ++j) {
        cout << "Sum №" << j + 1 << ": " << sums[j] << endl;
    }
}

bool create_file(const int sums[col], const string &filename){
    ofstream file(filename);
    if(!file.is_open()){ 

    cerr << "Error, file was't createn! " << endl;
    return false;
    }

    for(int j = 0; j < col; ++j){
        file << sums[j] << endl;
    }

    file.close();
    return true;
}

int multiplication(const string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error, file wasn't opened! " << endl;
        return 0;
    }
    int value;
    int dobutok = 1;
    bool has_values = false;

    while(file >> value){
        dobutok *= value;
        has_values = true;
    }
    file.close();

    if(!has_values){
        cerr << "Error, the file is empty or contains invalid data" << endl;
        return 0;
    }

    cout << "Dobutok = " << dobutok << endl;
    return dobutok;
}

bool delete_file(const string &filename){
    if(remove(filename.c_str()) != 0){
        cerr << "Error, file wasn't deleted! " << endl;
        return false;
    }
    else cout << "File " << filename << " was succesfully deleted! " << endl;
    return true;
}

void main_function(){
    cout << "Matrix with int: \n";
    int int_matrix[row][col];
    create_matrix(int_matrix);
    print_matrix(int_matrix);
    cout << endl;

    cout << "Matrix with double: \n";
    double double_matrix[row][col];
    create_matrix(double_matrix);
    print_matrix(double_matrix);
    cout << endl;

    cout << "Sort matrix with double: \n";
    buble_sort(double_matrix);
    print_matrix(double_matrix);

    int sums[col];
    sum_of_random_elements(double_matrix, sums);

    if(create_file(sums, FILE_NAME)) cout << "All good) we were written to a file a static array with sums " << endl;
    else cout << " We weren't written anything to a file( " << endl;

    multiplication(FILE_NAME);

    delete_file(FILE_NAME);
}

int main(){

    main_function();
    
    return 0;
}