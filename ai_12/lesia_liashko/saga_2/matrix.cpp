#include <iostream>

using namespace std;


int main (){
    int n,k;
cin >> n >> k;
int matrix[n][k];
for (int i = 0; i < n; i++){
    for (int j = 0; j<k; j++){
        cin >> matrix[i][j];
    }
}
int matrixmax[k];
int matrixmin[k];
int matrixmaxn[n];
int matrixminn[n];
//зробити поворот матриці на 90 градусів 

for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << "90:"<< matrix [n-j-1][i] << endl;
            }
}
//max element
for (int j =0; j < k; j++){
int max = matrix[0][j];
for (int i=1; i < n; i++){
    if (matrix[i][j] > max){
     max = matrix[i][j];
    }
}
matrixmax[j] = max; 
}

for (int j = 0; j < k; j++){ 
cout << matrixmax[j]<< endl;
}

//min element
for (int j =0; j < k; j++){
int min = matrix[0][j];
for (int i=1; i < n; i++){
    if (matrix[i][j] < min){
     min = matrix[i][j];
    }
}
matrixmin[j] = min; 
}

for (int j = 0; j < k; j++){ 
cout << matrixmin[j]<< endl;
}

//max element row
for (int i =0; i < n; i++){
int max = matrix[i][0];
for (int j=1; j < k; j++){
    if (matrix[i][j] > max){
     max = matrix[i][j];
    }
}
matrixmaxn[i] = max; 
}

for (int i = 0; i < n; i++){ 
cout << matrixmaxn[i]<< endl;
}

//minelement row
for (int i =0; i < n; i++){
int min = matrix[i][0];
for (int j=1; j < k; j++){
    if (matrix[i][j] <  min){
     min = matrix[i][j];
    }
}
matrixminn[i] = min; 
}

for (int i = 0; i < n; i++){ 
cout << matrixminn[i]<< endl;
}
//вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
for (int j=k-1; j>=0; --j){
    for (int i=n-1; i >= 0; --i){
        cout << "showing:" << matrix[i][j] << " "<< endl;
    }
}
cout << endl;

//вивести матрицю з нижнього правого кута з ліва на право, з верху вниз 
for (int i=n-1; i >= 0; --i){
    for (int j=k-1; j>=0; --j){
        cout << "showing2:" << matrix[i][j] << " "<< endl;
    }
}
//обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
 for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k - i - 1; ++j) { // Проходимо верхній трикутник
            swap(matrix[i][j], matrix[n - j - 1][n - k - 1]);
        }
    }

for (int i=0; i <n; i++){
    for (int j=0; j<k; j++){
        cout << matrix[i][j] << " " << endl;
    }
}
//перевірити чи матриця симетрична 
 int matrixs[k][n];
 int result;
 for (int i =0; i < n; i++){
    for (int j = 0; j < k; j++){
       
        if (matrix[i][j] == matrixs[j][i]){
            result += 0;
        } else {
            result += 1;
    }
 }
 
}if (result == 0){
    cout << "yes";
 }else {
    cout << "no";
 }
 //Пошук конкретного елемента в матриці
int e;
cout << "e is.." << endl;
cin >> e;
bool result1;
for (int i =0; i < n; i++){
    for (int j = 0; j < k; j++){
        if (matrix[i][j]==e){
            cout << "element"<< i<<j;
            result1 = true;
        break;
        }
if (!result1){cout << "0";

    }}}
  //Пошук суми всіх елементів
  cout << endl;
  int sum;
  for (int i =0; i < n; i++){
    for (int j = 0; j < k; j++){
        sum += matrix[i][j];
    }
    }
    cout << sum;
    float average = sum/(n*k);
    cout << endl;
    cout << average;
    //Пошук діагональних елементів
    cout << endl;
for (int i =0; i < n; i++){
        cout << matrix[i][n-i-1];
    }}
    
