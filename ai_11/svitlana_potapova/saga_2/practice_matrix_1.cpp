#include <iostream> 
using namespace std;

void printMatrix(int matrix[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
} 

int* maxElCols(int matrix[5][5]){
    int* res = new int[5];
    for(int j=0; j<5; j++){
        int maxEl = matrix[0][j];
        for(int i=0; i<5; i++){
                if(matrix[i][j]>maxEl){
                    maxEl = matrix[i][j];
                }
        }
        res[j] = maxEl;
    }
    return res;
}

int* minElCols(int matrix[5][5]){
    int* res = new int[5];
    for(int j=0; j<5; j++){
        int minEl = matrix[0][j];
        for(int i=0; i<5; i++){
                if(matrix[i][j]<minEl){
                    minEl = matrix[i][j];
                }
        }
        res[j] = minEl;
    }
    return res;
}

int* maxElRows(int matrix[5][5]){
    int* res = new int[5];
    for(int i=0; i<5; i++){
        int maxEl = matrix[i][0];
        for(int j=0; j<5; j++){
                if(matrix[i][j]>maxEl){
                    maxEl = matrix[i][j];
                }
        }
        res[i] = maxEl;
    }
    return res;
}

int* minElRows(int matrix[5][5]){
    int* res = new int[5];
    for(int i=0; i<5; i++){
        int minEl = matrix[i][0];
        for(int j=0; j<5; j++){
                if(matrix[i][j]<minEl){
                    minEl = matrix[i][j];
                }
        }
        res[i] = minEl;
    }
    return res;
}

void print1(int matrix[5][5]){
    for(int j=4; j>=0; j--){
        if(j%2==0){
            for(int i=4; i>=0; i--){
                cout << matrix[i][j] << " ";
            }
        }
        else{
            for(int i=0; i<5; i++){
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void mirror(int matrix[5][5]){
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    printMatrix(matrix);
}

void print2(int matrix[5][5]){
    for(int i=4; i>=0; i--){
        if(i%2==0){
            for(int j=4; j>=0; j--){
                cout << matrix[i][j] << " ";
            }
        }
        else{
            for(int j=0; j<5; j++){
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSym(int matrix[5][5]){
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(matrix[i][j]!=matrix[j][i]){
                return false;
            }
        }
    }
    return true;
}

void turn90(int matrix[5][5]){
    cout << "До: " << endl;
    printMatrix(matrix);
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5/2; j++){
            swap(matrix[i][j], matrix[i][4-j]);
        }
    }
    cout << "Після: " << endl;
    printMatrix(matrix);
}


void printArray(int* arr){
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void tr(int matrix[5][6]){
    int res[6][5];
    cout << "До:" << endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            res[j][i] = matrix[i][j];
        }
    }

    cout << endl << "Псіля:" << endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matrix[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matrix[i][j] = rand()%50;
        }
    }

    cout << "Матриця 5х5: " << endl;
    printMatrix(matrix);

    cout << "Найбільші елементи у кожному стовпці: " << endl;
    printArray(maxElCols(matrix));

    cout << "Найменші елементи у кожному стовпці: " << endl;
    printArray(minElCols(matrix));

    cout << "Найбільші елементи у кожному рядку: " << endl;
    printArray(maxElRows(matrix));

    cout << "Найменші елементи у кожному рядку: " << endl;
    printArray(minElRows(matrix));
    
    cout << "Виведення матриці з нижнього правого кута вверх і вниз по стовпцям: " << endl;
    print1(matrix);

    cout << "Виведення матриці з нижнього правого кута справа наліво знизу вверх: " << endl;
    print2(matrix);

    cout << "Обернення значень матриці відносно головної діагоналі: " << endl;
    mirror(matrix);

    cout << "Перевірка чи є матриця симетричною: " << endl;
    int test[5][5] = {{1,0,0,0,5}, 
                      {0,1,2,0,0}, 
                      {0,2,1,0,8}, 
                      {0,0,0,1,0}, 
                      {5,0,8,0,1}};
    printMatrix(test);
    if(isSym(test)){
        cout << "Матриця симетрична" << endl;
    }
    else{
        cout << "Матриця не симетрична" << endl;
    }

    cout << endl << "Обернення матриці на 90 градусів: " << endl;
    turn90(matrix);

    int test2[5][6] = {{1,2,4,0,5,6}, 
                       {4,1,2,0,0,2}, 
                       {5,3,1,1,8,0}, 
                       {9,7,0,1,0,3}, 
                       {1,0,2,2,1,1}};

    cout << "Транспонування матриці 5х6: " << endl;
    tr(test2);

    return 0;

}