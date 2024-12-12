//- перше з чого я б почав це робота з матрицями до прикладу (5*5)
double** matrixCreate(int size)
{
    double** matrix = new double*[size];

    cout << "Insert the values of the matrix(5x5): ";
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";

    return matrix;
}

//- знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат
double* maxElemInColumn(double** matrix, int size)
{
    cout << "Max elements in columns: " << "\n";
    double* arr = new double[size];

    for(int i = 0; i < size; i++)
    {
        double maxm = matrix[0][i];
        for(int j = 0; j < size; j++)
        {
            if(matrix[j][i] > maxm)
                maxm = matrix[j][i];
        }
        arr[i] = maxm;
        cout << maxm << " ";
    }
    cout << "\n";

    return arr;
}

//- знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат
double* minElemInColumn(double** matrix, int size)
{
    cout << "Min elements in columns: " << "\n";
    double* arr = new double[size];

    for(int i = 0; i < size; i++)
    {
        double minm = matrix[0][i];
        for(int j = 0; j < size; j++)
        {
            if(matrix[j][i] < minm)
                minm = matrix[j][i];
        }
        arr[i] = minm;
        cout << minm << " ";
    }
    cout << "\n";

    return arr;
}

//- знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат
double* maxElemInRow(double** matrix, int size)
{
    cout << "Max elements in rows: " << "\n";
    double* arr = new double[size];

    for (int i = 0; i < size; i++) 
    {
        double maxm = matrix[i][0];
        for (int j = 1; j < size; j++) 
        {
            if (matrix[i][j] > maxm)
                maxm = matrix[i][j];
        }
        arr[i] = maxm;
        cout << maxm << " ";
    }
    cout << "\n";

    return arr;
}

//- знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат
double* minElemInRow(double** matrix, int size)
{
    cout << "Min elements in rows: " << "\n";
    double* arr = new double[size];

    for (int i = 0; i < size; i++) 
    {
        double minm = matrix[i][0];
        for (int j = 1; j < size; j++) 
        {
            if (matrix[i][j] < minm)
                minm = matrix[i][j];
        }
        arr[i] = minm;
        cout << minm << " ";
    }
    cout << "\n";

    return arr;
}

//- вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
double** lowerRightCornerUpAndDownTheColumn(double** matrix, int size)
{
    cout << "Lower right corner up and down the column: " << "\n";
    for(int i= size - 1; i >= 0; i--)
    {   
        if(i % 2 == 0)
        {
            for(int j = size - 1; j >= 0; j--)
            {            
                cout << matrix[j][i] << " ";
            }
        }
        else 
        {
            for(int j = 0; j < size; j++)
            {
                cout << matrix[j][i] << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

    return matrix;
}

//- обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
double** numberSwappedDiagonal(double** matrix, int size)
{
    cout << "Interchange diagonals: " << "\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << "\n ";
    }
    for (int i = 0; i < size; i++)
    {
        double temp = matrix[i][i];
        matrix[i][i] = matrix[i][size - i - 1];
        matrix[i][size - i - 1] = temp;
    }
    cout << "\nMatrix after changing the diagonals : \n ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << "\n ";
    }
    cout << "\n";

    return matrix;
}

//- зробити поворот матриці на 90 градусів 
double** reverseMatrix(double** matrix, int size)
{
    cout << "Reversed matrix: " << "\n";
    //транспонування матриці
    cout << "Матриця обернена відносно головної діагоналі: " << "\n";
    int rotatedMatrix[5][5];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            rotatedMatrix[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    // зробити поворот матриці на 90 градусів
    cout << "Матриця обернена на 90 градусів: " << "\n";
    int rotatedBy90[5][5];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
        rotatedBy90[i][j] = rotatedMatrix[i][4-j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << rotatedBy90[i][j] << " ";
        }
        cout << "\n";
    }
    return matrix;
}

//- перевірити чи матриця симетрична 
double** symmetrical(double** matrix, int size)
{
    double symmetryc = true;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (matrix[i][j] != matrix[j][i]) 
            {
                symmetryc = false;
            }
        }
    }
    if(symmetryc)
    {
        cout << "Matrix is symmetryc!" << "\n";
    }
    else
    {
        cout << "Matrix is nor symmetryc!" << "\n";
    }
    return matrix;
}

