// #include <iostream>
// #include <cstdlib>
// #include <iomanip>
// #include <ctime>
// #include <string>




  





// double** task1Mtr(double ** tempMatr){
   
    
    

//  for(size_t i = 0; i < 5; i++){
//     tempMatr[i] = new double[5];
//     for(size_t j =0; j<5; j++){
//         tempMatr[i][j] = (rand()%190);
//        std::cout <<  tempMatr[i][j] << " ";
//     }
//     std::cout << std::endl;
//  }
    





//     return tempMatr;
// }

// void task1(double ** tempMatr, double* tempArr, int tempMax){
    
//     for(size_t i = 0; i < 5; i++){
//         for(size_t j = 0; j < 5; j++){
//           if(tempMatr[j][i] > tempMax){
//             tempMax = tempMatr[j][i];
//           } 
          
//         } 
        
//         tempArr[i] = tempMax;
//     }

//     for(size_t i = 0; i < 5; i++){
//         std::cout << tempArr[i] << " ";
       
//     }
//     std::cout << std::endl;
    
//     delete[] tempArr; 
//     tempArr = nullptr;


    
// }

// void task2(double ** tempMatr){

//     double**resultMatrix = new double*[5];
//     int row = 0;
    
//     for (int i = 0; i < 5; i++) {
//         resultMatrix[i] = new double[5];
//     }

    
    
    
//     for (int j = 4; j >= 0; j--) {
//         if (j % 2 == 0) {
//             for (int k = 4; k >= 0; k--) {
//                 resultMatrix[row][4-j] = tempMatr[k][j];
//                 std::cout << tempMatr[k][j] << " ";

//             }
//         } else {
//             for (int k = 0; k < 5; k++) {
//                 resultMatrix[row][4-j] = tempMatr[k][j];
//                 std::cout << tempMatr[k][j] << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
    
//     std::cout << std::endl;
    
//     for(int i = 0; i < 5; i++) {
//         for(int j = 0; j < 5; j++) {
//             resultMatrix[j][i] = resultMatrix[i][j];
//             std::cout << resultMatrix[i][j] << " ";

//         }
//        std::cout << std::endl;
//     }


    
// }



// int main(){
//      srand(time(0));


//      double **matr = new double*[5];
//      double *arr = new double[5];
//     int max = -1;
    
//     task1Mtr(matr);

//     std::cout << std::endl;

//     task1(matr,arr, max );

//     std::cout << std::endl;

//     task2(matr);







   
//     return 0;
// }

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

void task1Mtr(double tempMatr[5][5]) {
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            tempMatr[i][j] = (rand() % 190);
            std::cout << tempMatr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void task1(double tempMatr[5][5], double tempArr[5]) {
    for (size_t i = 0; i < 5; i++) {
        int tempMax = -1;
        for (size_t j = 0; j < 5; j++) {
            if (tempMatr[j][i] > tempMax) {
                tempMax = tempMatr[j][i];
            }
        }
        tempArr[i] = tempMax;
    }

    for (size_t i = 0; i < 5; i++) {
        std::cout << tempArr[i] << " ";
    }
    std::cout << std::endl;
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
            std::cout << transposedMatrix[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(time(0));

    double matr[5][5];
    double arr[5];

    std::cout << "Матриця:\n";
    task1Mtr(matr);

    std::cout << "\nМаксимуми по стовпцях:\n";
    task1(matr, arr);

    std::cout << "\nРезультат task2:\n";
    task2(matr);

    return 0;
}
