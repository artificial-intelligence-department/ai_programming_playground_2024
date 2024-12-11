/*перше з чого я б почав це робота з матрицями до прикладу (5*5)
- знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат
- знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат
- знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат
- знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат
- вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
- вивести матрицю з нижнього правого кута з ліва на право, з верху вниз 
- обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
- зробити поворот матриці на 90 градусів 
- перевірити чи матриця симетрична 
- далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після*/

#include <iostream>
#include <algorithm>

using namespace std;
int main (){
    srand(time(0));
    int matrix [5][5];
    int maxrow[5];
    int currentmax = 0;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = rand() %10 ;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    /*max in rows*/
    for (int j = 0; j < 5; j++){
        currentmax = matrix[0][j];
        for (int i = 0; i < 5; i++){
            if (currentmax < matrix[i][j]){
                currentmax = matrix[i][j];
            }
        }
        maxrow[j] = currentmax;
        cout << maxrow[j] << " ";
    }

    cout << endl;

    
    /*min in rows*/
    for (int j = 0; j < 5; j++){
        currentmax = matrix[0][j];
        for (int i = 0; i < 5; i++){
            if (currentmax > matrix[i][j]){
                currentmax = matrix[i][j];
            }
        }
        maxrow[j] = currentmax;
        cout << maxrow[j] << " ";
    }

    cout << endl;

    int column[5];
    int minvalues[5];
    /*min in rows*/
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 5; i++){
            column[i] = matrix[i][j];
            
        }
        sort(column, column + 5);
        minvalues[j]=column[0];
        if(maxrow[j] == minvalues[j]){
            cout << " Мінімальне значення " << j + 1 << " стовпця співпадає у двох обчисленнях"<< endl;
        }
    }

    cout << endl;

    /*max in lines*/
    for (int i = 0; i < 5; i++){
        currentmax = matrix[i][0];
        for (int j = 0; j < 5; j++){
            if (currentmax < matrix[i][j]){
                currentmax = matrix[i][j];
            }
        }
        maxrow[i] = currentmax;
        cout << maxrow[i] << " ";
    }

    cout << endl;
    
     /*min in lines*/
    for (int i = 0; i < 5; i++){
        currentmax = matrix[i][0];
        for (int j = 0; j < 5; j++){
            if (currentmax > matrix[i][j]){
                currentmax = matrix[i][j];
            }
        }
        maxrow[i] = currentmax;
        cout << maxrow[i] << " ";
    }

    cout << endl;

    int temp = 0;

    cout << "матриця відносно діагоналі" << endl;
    for (int i = 0; i < 5; i++){
        for (int j = i; j < 5; j++){
            temp = matrix[i][j];
            matrix [i][j] = matrix [j][i];
            matrix [j][i] = temp;
        }
        for (int j = 0; j < 5; j++){
            cout << matrix [i][j] << " ";
        }
        cout << endl;
        
    }
    

    cout << endl;
    int matrixx [5][6];
    int transp [6][5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 6; j++){
            matrixx[i][j] = rand() %10 ;
            cout << matrixx[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << " транспонована матриця" << endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 6; j++){
            transp[j][i] = matrixx[i][j];
        }
    }

     for (int i = 0; i < 6; i++){
        for (int j = 0; j < 5; j++){
             cout << transp [i][j] << " ";
        }
        cout << endl;
     }


    cout << endl;

    return 0;
}