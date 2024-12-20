#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void printMatrix(int matrix[5][5]){
    cout << "Оригінальна згенерована матриця: " << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void elementsMatrix(int matrix[5][5]){
    cout << "Максимальні елементи кожного стовпця: " << endl;
    for (int i = 0; i < 5; i++)
    {
        int maxEl = 0;
        for (int j = 0; j < 5; j++)
        {
            if(matrix[j][i] > maxEl) maxEl = matrix[j][i];
        }
        cout << maxEl << " ";
    }
    cout << endl;

    cout << "Мінімальні елементи кожного стовпця: " << endl;
    for (int i = 0; i < 5; i++)
    {
        int minEl = 101;
        for (int j = 0; j < 5; j++)
        {
            if(matrix[j][i] < minEl) minEl = matrix[j][i];
        }
        cout << minEl << " ";  
    }

    cout << endl;
    cout << endl;
}

void perevertish(int matrix[5][5]){
        cout << "Перевернута 1: " << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Перевернута 2: " << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

void symCheck(int matrix[5][5]){
     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(matrix[i][j] != matrix[j][i]) break;
        }
        
    }
    cout << "Матриця не симетрична!";
    cout << endl;
    cout << endl;
}

void transMatrix(int newMatrix[5][6], int transposedM[6][5]){
    cout << "Нова матриця: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            newMatrix[i][j] = rand() % 100;
            cout << newMatrix[i][j] << " ";
        }
    cout << endl;
    }

    cout << "Транспонована матриця: " << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            transposedM[i][j] = newMatrix[j][i];
            cout << transposedM[i][j] << " ";
        }
        cout << endl;
    }
}

void findEl(int matrix[5][5]){
    int input;
    cout << "Введіть елемент: ";
    cin >> input;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(matrix[i][j] == input) cout << " Елемент " << input << " Знаходиться в " << i + 1 << " рядку і " << j + 1 << " стовпці" << endl;
        }
    }
    cout << endl;
}

void sumOfAllElements(int matrix[5][5]){
    int sum = 0;
    double arfm;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += matrix[i][j];
            arfm = static_cast<double>(sum)/25;

        }
    }
    cout << "Сумма всіх елементів матриці: " << sum << endl;
    cout << "Середнє арифметичне: " << fixed << setprecision(2) << arfm << endl;
    cout << endl;
}

void diagonalElements(int matrix[5][5]){
    cout << "Елементи головної діагоналі: ";
    for (int i = 0; i < 5; i++)
    {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    cout << "Елементи бічної діагоналі: ";
    for (int i = 0; i < 5; i++){
        int j = 4 - i;
        cout << matrix[i][j] << " ";
    }
    cout << endl;
    cout << endl;
} 

void biggestLine(int matrix[5][5]){
    int maxLine;
    int lineN;
    
    for (int i = 0; i < 5; i++)
    {
        int lineCounter = 0;
        for (int j = 0; j < 5; j++)
        {
            lineCounter += matrix[i][j];
        }

        if(lineCounter > maxLine){
            maxLine = lineCounter;
            lineN = i;
        }
    }
    cout << "Найбільший рядок " << lineN + 1 << " має сумму: " << maxLine;
    cout << endl;
}

int main(){
    int matrix[5][5];
    int lowest[5], highest[5];
    int newMatrix[5][6];
    int transposedM[6][5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = rand() % 100;
        }
        
    }

    printMatrix(matrix);
    elementsMatrix(matrix);
    // perevertish(matrix);
    // symCheck(matrix);
    // transMatrix(newMatrix, transposedM);
    findEl(matrix);
    sumOfAllElements(matrix);
    diagonalElements(matrix);
    biggestLine(matrix);
    
    return 0;
}