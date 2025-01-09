#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node2
{
    int data;
    Node2 *next;
    Node2 *prev;
};

void addToBeginning(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void addToBeginning2(Node2 *&head, Node2 *&tail, int value)
{
    Node2 *newNode = new Node2();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        head->prev = newNode;
        head = newNode;
    }
}

void addToEnd(Node *head, int value)
{
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    Node *newNode = new Node();
    newNode->data = value;
    current->next = newNode;
}

void addToEnd2(Node2 *&head, Node2 *&tail, int value)
{
    Node2 *newNode = new Node2();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    tail->next = newNode;
    tail = newNode;
}

void addToCenter(Node *&head, int placement, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    if (placement == 0)
    {
        addToBeginning(head, value);
    }
    else
    {
        Node *current = head;
        while (current->data != placement)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void addToCenter2(Node2 *&head, Node2 *&tail, int placement, int value)
{
    Node2 *newNode = new Node2();
    newNode->data = value;
    if (placement == 0)
    {
        addToBeginning2(head, tail, value);
    }
    else
    {
        Node2 *current = head;
        while (current->data != placement)
        {
            current = current->next;
            if (current == nullptr)
            {
                break;
            }
        }
        if (current->next == nullptr)
        {
            addToEnd2(head, tail, value);
        }
        if (current == nullptr)
        {
            cout << "There is no element in the list after which the node should be added!" << "\n";
        }
        else
        {
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            current->next->prev = newNode;
        }
    }
}

void bubbleSort(Node *head)
{
    bool swapped;
    do
    {
        swapped = false;
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void bubbleSort2(Node2 *head)
{
    bool swapped;
    do
    {
        swapped = false;
        Node2 *current = head;
        while (current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void sort(Node *&head)
{
    Node *placement = head;
    while (placement != nullptr)
    {
        Node *current = placement;
        Node *min = placement;
        while (current != nullptr)
        {
            if (current->data < min->data)
            {
                min = current;
            }
            current = current->next;
        }
        if (min != placement)
        {
            swap(placement->data, min->data);
        }

        placement = placement->next;
    }
}

void sort2(Node2 *&head, Node2 *&tail)
{
    Node2 *placement = head;
    Node2 *last = head;
    while (placement != nullptr)
    {
        Node2 *current = placement;
        Node2 *min = placement;
        while (current != nullptr)
        {
            if (current->data < min->data)
            {
                min = current;
            }
            current = current->next;
        }
        if (min != placement)
        {
            swap(min->data, placement->data);
        }

        last = placement;
        placement = placement->next;
    }
    tail = last;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void printList2(Node2 *head)
{
    Node2 *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void printList2Back(Node2 *tail)
{
    Node2 *current = tail;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << "\n";
}

void printList(Node *head, bool recursive)
{
    if (recursive)
    {
        cout << head->data << " ";
        if (head->next != nullptr)
        {
            printList(head->next);
        }
    }
}

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

//- далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
double** matrixFiveSix()
{
    double** matrix = new double*[5];
    const int n = 5;
    const int m = 6;

    cout << "Insert the values of the matrix(5x6): ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
            matrix[i][j] = matrix[j][i];
    }
    return matrix;
}

double** sumMatrix(int size)
{
    double** matrix1 = new double*[size];

    //- Ініціалізація матриці: Заповнення статичного двовимірного масиву.
    cout << "Insert the values of the matrix(5x5): ";
    for (int i = 0; i < size; i++)
    {
        matrix1[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix1[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";

    double** matrix2 = new double*[size];
    cout << "Insert the values of the matrix(5x5): ";
    for (int i = 0; i < size; i++)
    {
        matrix2[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix2[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";

    //- Додавання двох матриць: Елемент за елементом додаються елементи двох матриць.
    double** sum = new double*[size];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
    }

    cout << "\n" << "Sum of two matrix is: " << "\n";
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << sum[i][j] << "  ";
            if(j == size - 1)
                cout << "\n";
        }
    }
    return sum;
}

//- Множення двох матриць: Класичний алгоритм множення матриць.
double** multipMatrix(int size)
{
    double** matrix1 = new double*[size];

    //- Ініціалізація матриці: Заповнення статичного двовимірного масиву.
    cout << "Insert the values of the matrix(5x5): ";
    for (int i = 0; i < size; i++)
    {
        matrix1[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix1[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";

    double** matrix2 = new double*[size];
    cout << "Insert the values of the matrix(5x5): ";
    for (int i = 0; i < size; i++)
    {
        matrix2[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix2[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    cout << "Multiplication of given two matrices is: " << "\n";
    double** matr = new double*[size];
    for (int i = 0; i < size; i++) 
    {
        matr[i] = new double[size];
        for (int j = 0; j < size; j++) 
        {
            matr[i][j] = 0;
 
            for (int k = 0; k < size; k++) 
            {
                matr[i][j] += matrix1[i][k] * matrix2[k][j];
            }
 
            cout << matr[i][j] << " ";
        }
 
        cout << "\n";
    }
    cout << "\n";
    return matr;
}

//- Транспонування матриці: Обмін рядків і стовпців місцями.
double** transposeMatrix(double** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[j][i] = matrix[i][j];
        }
    }
    return matrix;
}

//- Пошук максимуму/мінімуму в матриці.
double** minMaxMatrix(double** matrix, int size)
{
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(max < matrix[i][j]) max = matrix[i][j];
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(min > matrix[i][j]) min = matrix[i][j];
        }
    }
    cout << "Maximum = " << max << ", Minimum = " << min;
    return matrix;
}

//- Обчислення детермінанта (для квадратних матриць).
double** determinantMatrix(double** matrix, int size)
{
    cout << "Determinant of the matrix is: ";
    double det = 0.0;
    for(int x = 0; x < 5; x++)
    {
        int subMatrix[10][10];
        int subR = 0; // minor
        for(int i = 1; i < 5; i++)
        {
            int subC = 0; //мінор стовпчик
            for(int j = 0; j < 5; j++)
            {
                if(j == x)
                    continue;
                subMatrix[subR][subC] = matrix[i][j];
                subC++;
            }
            subR++;
        }
        int subDet = 1;
        if(size - 1 == 2)
        {
            //minor 2x2
            subDet = (subMatrix[0][0] * subMatrix[1][1]) - (subMatrix[0][1] * subMatrix[1][0]);
        }
        else if(size - 1 == 1)
        {
            //minor 1x1
            subDet = subMatrix[0][0];
        }
        det += pow(-1, x) * matrix[0][x] * subDet;
    }
    return matrix;
}

//- Пошук конкретного елемента в матриці
double** elementMatrix(double** matrix, int size)
{
    cout << "Enter element you are looking for: ";
    int search;
    cin >> search;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(search == matrix[i][j])
            {
                cout << "Element in position " << i+1 << " row " << j+1 << " column" << "\n";
            }
        }
    }
    return matrix;
}

//- Пошук суми всіх елементів
double** sumElement(double** matrix, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            sum += matrix[i][j];
        }
    }
    cout << "Sum of all elements: " << sum << "\n";
    return matrix;
}

//- Пошук середнього значення
double** arithmeticMean(double** matrix, int size)
{
    double sum = 0;
    double mean = 0;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            sum += matrix[i][j];
            mean = sum/(size + size);
        }
    }
    cout << "Arithmetic mean of all elements: " << mean << "\n";
    return matrix;
}

//- Пошук рядка з максимальною сумою
double** rowMaxSum(double** matrix, int size)
{
    cout << "Row with max sum is: ";
    double maxSum = 0.0;
    int maxRow;
    for(int i = 0; i < size; i++)
    {
        double rowSum = 0.0;
        for(int j = 0; j < size; j++)
        {
            rowSum += matrix[i][j];
        }
        if(rowSum > maxSum)
        {
            maxSum = rowSum;
            maxRow = i;
        }
    }
    cout << maxRow+1 << "\n";
    return matrix;
}

//- Пошук числа, що повторюється найбільше
double** commonElement(double** matrix, int size)
{
    cout << "The most common element: ";
    double common = 0.0;
    int common1 = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int time = 0;
            for(int k = 0; k < size; k++)
            {
                for(int l = 0; l < size; l++)
                {
                    if(matrix[i][j] == matrix[k][l])
                    {
                        time++;
                    }
                }
            }
            if(time > common)
            {
                common = time;
                common1 = matrix[i][j];
            }
        }
    }
    if(common == 1)
    {
        cout << "\n";
        cout << "There is no common element!" << "\n";
    }
    else
    {
        cout << common1 << "\n";
    }
}

//- Пошук парних елементів
double** pairedElements(double** matrix, int size)
{
    cout << "Paired elements in matrix: ";
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(matrix[i][j] % 2 == 0)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
    return matrix;
}

int main()
{
    Node *head = nullptr;
    addToBeginning(head, 1);
    addToBeginning(head, 2);
    addToBeginning(head, 9);
    cout << "The list after adding nodes to the beginning: " << "\n";
    printList(head);
    addToEnd(head, 4);
    addToEnd(head, 5);
    addToEnd(head, 6);
    cout << "The list after adding nodes to the end: " << "\n";
    printList(head);
    addToCenter(head, 2, 7);
    addToCenter(head, 5, 8);
    cout << "The list after adding nodes to a specific location: " << "\n";
    printList(head);
    bubbleSort(head);
    cout << "List after bubble sorting: " << "\n";
    printList(head);
    addToBeginning(head, 11);
    addToEnd(head, 3);
    addToCenter(head, 4, 13);
    cout << "List after adding new elements: " << "\n";
    printList(head);
    sort(head);
    cout << "List after sorting by selection method: " << "\n";
    printList(head);
    cout << "The list is output by recursive function: " << "\n";
    printList(head, true);
    Node2 *head2 = nullptr;
    Node2 *tail = nullptr;
    addToBeginning2(head2, tail, 1);
    addToBeginning2(head2, tail, 2);
    addToBeginning2(head2, tail, 7);
    cout << "Double-linked list after adding nodes to the beginning: " << "\n";
    printList2(head2);
    addToEnd2(head2, tail, 4);
    addToEnd2(head2, tail, 5);
    addToEnd2(head2, tail, 6);
    cout << "Double-linked list after adding nodes to the end: " << "\n";
    printList2(head2);
    cout << "The double-linked list is displayed from right to left: " << "\n";
    printList2Back(tail);
    addToCenter2(head2, tail, 2, 10);
    addToCenter2(head2, tail, 5, 8);
    cout << "Double-linked list after adding nodes to a specific location: " << "\n";
    printList2(head2);
    bubbleSort2(head2);
    cout << "Double-linked list after bubble sorting: " << "\n";
    printList2(head2);
    addToBeginning2(head2, tail, 9);
    addToEnd2(head2, tail, 3);
    addToCenter2(head2, tail, 4, 13);
    cout << "Double-linked list after adding new elements: " << "\n";
    printList2(head2);
    sort2(head2, tail);
    cout << "Double-linked list after sorting by selection method: " << "\n";
    printList2(head2);

    const int size = 5;
    double** matrix = matrixCreate(size);
    double* maxElemColumn = maxElemInColumn(matrix, size);
    double* minElemColumn = minElemInColumn(matrix, size);
    double* maxElemRow = maxElemInRow(matrix, size);
    double* minElemRow = minElemInRow(matrix, size);
    double** lower = lowerRightCornerUpAndDownTheColumn(matrix, size);
    double** swapped = numberSwappedDiagonal(matrix, size);
    double** reverse = reverseMatrix(matrix, size);
    double** symmetric = symmetrical(matrix, size);
    double** fiveSix = matrixFiveSix();
    double** sum = sumMatrix(size);
    double** multip = multipMatrix(size);
    double** transpose = transposeMatrix(matrix, size);
    double** minMax = minMaxMatrix(matrix, size);
    double** determinant = determinantMatrix(matrix, size);
    double** element = elementMatrix(matrix, size);
    double** sum = sumElement(matrix, size);
    double** mean = arithmeticMean(matrix, size);
    double** rowSum = rowMaxSum(matrix, size);
    double** common = commonElement(matrix, size);
    double** paired = pairedElements(matrix, size);
}
