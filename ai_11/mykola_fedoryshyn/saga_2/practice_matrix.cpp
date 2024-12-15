#include<iostream>
#include <vector>
#include <climits>
using namespace std;

/*
перше з чого я б почав це робота з матрицями до прикладу (5*5)
+ знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат
+ знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат
+ знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат
+ знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат
+ обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
+ зробити поворот матриці на 90 градусів 
+ далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
*/

void Print(int matrix[5][5]);
void Print(int matrix[5][5], int i);
void Print_arr(vector<int> matrix);
void Print_t(int matrix[5][5]);
void Print_90(int matrix[5][5]);

vector<int> Max_colum(int matrix[5][5]);
vector<int> Min_colum(int matrix[5][5]);
vector<int> Min_colum(int matrix[5][5], int i, vector<int> result);

vector<int> Min_row(int matrix[5][5]);
vector<int> Max_row(int matrix[5][5]);

void Trans(int matrix[5][6]);
int main(){
    int matrix[5][5] = {
    {16,22,31,25,35},
    {65,12,83,94,10},
    {14,42,13,21,15},
    {16,17,18,19,40},
    {27,12,233,24,25}};

    int matrix2[5][6] = {
    {16,22,31,25,35,1},
    {65,12,83,94,10,2},
    {14,42,13,21,15,3},
    {16,17,18,19,40,4},
    {27,12,233,24,25,5} };

    vector<int> max_colum = Max_colum(matrix);
    vector<int> min_colum = Min_colum(matrix);
    vector<int> a(5, INT_MAX);
    vector<int> min_colum_recursive = Min_colum(matrix, 0, a);

    vector<int> max_row = Max_row(matrix);
    vector<int> min_row = Min_row(matrix);


    Print(matrix,0);
    cout<<"Max_colum: "<<endl;
    Print_arr(max_colum);

    cout<<"Min_colum: "<<endl;
    Print_arr(min_colum);
    cout<<"Min_colum_recursive: "<<endl;
    Print_arr(min_colum_recursive);

    cout<<"Max_row: "<<endl;
    Print_arr(max_row);

    cout<<"Min_row: "<<endl;
    Print_arr(min_row);

    cout<<"Mirrored matrix: "<<endl;
    Print_t(matrix);
    
    cout<<"90_turn: "<<endl;
    Print_90(matrix);

    cout<<"Trans: "<<endl;
    Trans(matrix2);
    return 0;
}

void Print(int matrix[5][5]){
    for( int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout << matrix[i][j] << "\t";
        }
    cout << endl;
    }
}
void Print(int matrix[5][5], int i){
    if(i == 5) return;

    for(int j = 0; j<5; j++){
        cout << matrix[i][j] << "\t";
    }
    cout << endl;
    i++;
    Print(matrix, i);
}

void Print_arr(vector<int> matrix){
    for( int i = 0; i<5; i++){
        cout << matrix[i] << " ";
    }
    cout<<endl;
}
void Print_t(int matrix[5][5]){
    for( int j = 0; j<5; j++){
        for(int i = 0; i<5; i++){
            cout << matrix[i][j] << "\t";
        }
    cout << endl;
    }
}
void Print_90(int matrix[5][5]){
    for(int j = 4; j>=0; j--){
        for(int i = 0; i<5; i++){
            cout << matrix[i][j] << "\t";
        }
    cout << endl;
    }
}


vector<int> Max_colum(int matrix[5][5]){
    vector<int> result(5, INT_MIN);
    for( int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(matrix[j][i] > result[i]){
                result[i] = matrix[j][i];
            }
        }
    }
    return result;
}
vector<int> Min_colum(int matrix[5][5]){
    vector<int> result(5, INT_MAX);
    for( int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(matrix[j][i] < result[i]){
                result[i] = matrix[j][i];
            }
        }
    }
    return result;
}
vector<int> Min_colum(int matrix[5][5], int i, vector<int> result){
    if(i == 5) return result;
    else{
        for(int j = 0; j<5; j++){
            if(matrix[j][i] < result[i]){
                result[i] = matrix[j][i];
            }
        }

        return Min_colum(matrix, i+1, result);
    }
}

vector<int> Min_row(int matrix[5][5]){
    vector<int>result(5, INT_MAX);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j<5; j++){
            if( matrix[i][j] < result[i]){
                result[i] = matrix[i][j];
            }
        }
    }
    return result;
}
vector<int> Max_row(int matrix[5][5]){
    vector<int>result(5, INT_MIN);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j<5; j++){
            if( matrix[i][j] > result[i]){
                result[i] = matrix[i][j];
            }
        }
    }
    return result;
}

void Trans(int matrix[5][6]){
    for( int j = 0; j<6; j++){
        for(int i = 0; i<5; i++){
           //matrix[j][i] = matrix[i][j];
            cout << matrix[i][j] << "\t";
            
        }
    cout << endl;
    }
}    
