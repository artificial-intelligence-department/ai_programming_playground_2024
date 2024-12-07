// по кроку 1:
// перше з чого я б почав це робота з матрицями до прикладу (5*5)
// - знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат ✅
// - знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат ✅
// - знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат ✅
// - знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат ✅
// - вивести матрицю з нижнього правого кута вверх і вниз по стовпцям ✅
// - вивести матрицю з нижнього правого кута з ліва на право, з верху вниз ✅ 
// - обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями) ✅
// - зробити поворот матриці на 90 градусів ✅
// - перевірити чи матриця симетрична ✅
// - далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після ✅

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void FillMatrix(int matrix[][5], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int randomNumber = rand() % 100;
            matrix[i][j] = randomNumber;
        }
    }
}

void PrintMatrix(int matrix[][5], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// - знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат ✅
void FindMaxCols(int matrix[][5], int rows, int columns)
{
    int maxCols[5];

    for (int j = 0; j < columns; j++)
    {
        maxCols[j] = matrix[0][j];
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] > maxCols[j])
            {
                maxCols[j] = matrix[i][j];
            }
        }
    }

    cout << "Найбільші елементи стовпців: " << endl;
    for (int j = 0; j < columns; j++)
    {
        cout << maxCols[j] << " ";
    }
    cout << endl;
}


// - знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат ✅
void FindMinCols(int matrix[][5], int rows, int columns)
{
    int minCols[5];

    for(int j = 0; j < columns; j++)
    {
        minCols[j] = matrix[0][j];
    }

    for(int i = 1; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if (matrix[i][j] < minCols[j])
            {
                minCols[j] = matrix[i][j];
            }
        }
    }

    cout << "Найменші елементи стовпців:" << endl;
    for(int i = 0; i < columns; i++)
    {
        cout << minCols[i] << " ";
    }
    cout << endl;

}


// - знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат ✅
void FindMaxRow(int matrix[][5], int rows, int columns)
{
    int maxRows[rows];

    for (int i = 0; i < rows; i++)
    {
        maxRows[i] = matrix[i][0];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 1; j < columns; j++)
        {
            if(matrix[i][j] > maxRows[i])
            {
                maxRows[i] = matrix[i][j];
            }
        } 
    }

    cout << "Найбільші елементи рядків: " << endl;
    for(int i = 0; i < rows; i++)
    {
        cout << maxRows[i] << " ";
    }
    cout << endl;
}

// - знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат ✅
void FindMinRow(int matrix[][5], int rows, int columns)
{
    int maxRows[rows];

    for (int i = 0; i < rows; i++)
    {
        maxRows[i] = matrix[i][0];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 1; j < columns; j++)
        {
            if(matrix[i][j] < maxRows[i])
            {
                maxRows[i] = matrix[i][j];
            }
        } 
    }

    cout << "Найменші елементи рядків: " << endl;
    for(int i = 0; i < rows; i++)
    {
        cout << maxRows[i] << " ";
    }
    cout << endl;
}


// - вивести матрицю з нижнього правого кута вверх і вниз по стовпцям ✅
void PrintDownRight(int matrix[][5], int rows, int columns)
{
    cout << "Матриця з нижнього правого кута: " << endl;
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j >= 0; j--)
        {
            cout <<  setw(5) << matrix[j][i];
        }
        cout << endl;
    }
}



// - вивести матрицю з нижнього правого кута з ліва на право, з верху вниз ✅ 
void PrintDownRightLeftToRightUpToDown(int matrix[][5], int rows, int columns)
{
    cout << "Матриця з нижнього правого кута з ліва на право, з верху вниз: " << endl;
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j >= 0; j--)
        {
            cout <<  setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}  



// - обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями) ✅
void ReverseMatrix(int matrix[][5], int rows, int columns)
{
    cout << "Обернути значення матриці відносно головної діагоналі: " << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < columns; j++)
        {
            if (i != j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
                        
        } 
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
           cout << setw(5) << matrix[i][j]; 
                        
        }
        cout << endl;
        
    }
    
}

// - зробити поворот матриці на 90 градусів ✅
void TurnMatrix(int matrix[][5], int rows, int columns)
{
    cout << "Поворот матриці на 90 градусів за годинниковою стрілкою: " << endl;

    int rotatedMatrix[5][5];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            rotatedMatrix[j][rows - 1 - i] = matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = rotatedMatrix[i][j];
        }
    }
    PrintMatrix(matrix, rows, columns);
}


// - перевірити чи матриця симетрична ✅
bool IsSymetricMatrix(int matrix[][5], int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for (int j = i + 1; i < columns; i++)
        {
            if (i != j)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    return false;
                }
                
            }
            
        }
    }
    return true;
}

void MakeSymetricMatrix(int matrix[][5], int rows, int columns) // Щоб зробити матрицю симетричною і перевірити функцію
{
    for(int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < columns; j++)
        {
            matrix[i][j] = matrix[j][i];
        }
    }
}


// - далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після ✅
void TrnaspMatrix()
{
    int matrix[5][6];
    cout << "Нова матриці 5 на 6: " << endl;
    // Заповнення
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int randomNumber = rand() % 100;
            matrix[i][j] = randomNumber;
        }
    }
    // виведення
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Танспонована матриця 5 на 6: " << endl;
    // транспонування
    for(int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
}


int main()
{
    const int rows = 5;
    const int clolumns = 5;
    int matrix[rows][clolumns];

    FillMatrix(matrix, rows, clolumns);
    cout << "========= Матриця =========" << endl;
    PrintMatrix(matrix, rows, clolumns);
    cout << endl;
    FindMaxCols(matrix, rows, clolumns);
    cout << endl;
    FindMinCols(matrix, rows, clolumns);
    cout << endl;
    FindMaxRow(matrix, rows, clolumns);
    cout << endl;
    FindMinRow(matrix, rows, clolumns);
    cout << endl;
    PrintDownRight(matrix, rows, clolumns);
    cout << endl;
    PrintDownRightLeftToRightUpToDown(matrix, rows, clolumns);
    cout << endl;
    ReverseMatrix(matrix, rows, clolumns);
    cout << endl;
    TurnMatrix(matrix, rows, clolumns);
    cout << endl;
    if(IsSymetricMatrix(matrix, rows, clolumns))
    {
        cout << "Матриця семитрична!" << endl;
    }
    else
    {
        cout << "Матриця не семитрична!" << endl;
    }
    cout << endl;

    PrintMatrix(matrix, rows, clolumns);
    cout << endl;
    MakeSymetricMatrix(matrix, rows, clolumns);
    PrintMatrix(matrix, rows, clolumns);
    if(IsSymetricMatrix(matrix, rows, clolumns))
    {
        cout << "Матриця семитрична!" << endl;
    }
    else
    {
        cout << "Матриця не семитрична!" << endl;
    }
    cout << endl;

    TrnaspMatrix();
    return 0;
}