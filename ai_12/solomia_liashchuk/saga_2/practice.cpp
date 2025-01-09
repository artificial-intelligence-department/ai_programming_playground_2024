#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std; 

 //Операції з матрицями

void ElementCols(int arr[5][5], int cols, int max[], int min[]) //Мінімальні та максимальні значенння для стовпців
{
    for(int j = 0; j < cols; j++)
    {
        min[j] = arr[0][j];
        max[j] = arr[0][j];
        for(int i = 1; i < 5; i++)
        {
            if(arr[i][j] < min[j])
            {
                min[j] = arr[i][j];
            }
            if(arr[i][j] > max[j])
            {
                max[j]= arr[i][j];
            }

        }
        cout << "Min element(cols): " << min[j] << endl;
        cout << "Max element(cols): " << max[j] << endl;
    }
}

void ElementRows(int arr[5][5], int rows, int max[], int min[]) //Мінімальне та максимальне значенння для рядків
{
    for(int i = 0; i < rows; i++)
    {
        min[i] = arr[i][0];
        max[i] = arr[i][0];
        for(int j = 1; j < 5; j++)
        {
            if(arr[i][j] < min[j])
            {
                min[i] = arr[i][j];
            }
            if(arr[i][j] > max[j])
            {
                max[i]= arr[i][j];
            }
        }
        cout << "Min element(rows): " << min[i] << endl;
        cout << "Max element(rows): " << min[i] << endl;
    }
}

void MatrixUpAnDown(int arr[5][5], int rows, int cols) //Виведення матриці з правого кута, з верху в низ
{
    cout << "Elements from down to up: " << endl;
    for(int j = cols - 1; j >= 0; j--)
    {
        for(int i = rows - 1; i >= 0; i--)
        {
            cout << arr[i][j] << setw(2);
        }
        cout << endl;
    }
}

void MatrixDownAndUp(int arr[5][5], int rows, int cols) //Виведення матриці з правого кута, з низу в вурх
{
    cout << "Elements from up to down: " << endl;
    for(int j = 0; j < 5; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << arr[i][j] << setw(2);
        }
        cout << endl;
    }
}

void MatrixFromLeftToRight(int arr[5][5], int rows, int cols) //Виведення матриці зліва на право
{
    cout << "Elements from right to left: " << endl;
    for(int j = cols - 1; j >= 0; j--)
    {
        for(int i = 0; i < rows; i++)
        {
            cout << arr[i][j] << setw(2);
        }
        cout << endl;
    }
}

void MatrixChange(int arr[5][5], int rows, int cols) //Зміна елементів один з одним
{
    cout << "Swapped elements: " << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

void MatrixRotated(int arr[5][5], int rows, int cols) //Повернення матриі на 90 градусів 
{
    for(int i = 0; i < rows-1; i++)
    {
        for(int j = i + 1; j < cols; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i = 0; i < rows; i++)
    {
        reverse(arr[i], arr[i] + cols);
    }

    cout << "Rotated elements: " << endl;
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixSymmetrical(int arr[5][5], int rows, int cols) //Перевірка матриці на симетричність
{
    bool result = true;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] != arr[j][i])
            {
                result = false;
                break;
            }
        }
        if(!result) break;
    }
    if(result == true)
    {
        cout << "Matrix is symmetric" << endl;
    }
    else
    {
        result = false;
        cout << "Matrix isn't symmetrical" << endl;
    }
} 

//Операції з списками

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

void ShowList(Node* head)
{
    if(head == nullptr)
    cout << "List is emty" << endl;
    Node* current = head;

    while(current != nullptr)
    {
        cout << current->data << " " << endl;
        current = current->next;
    }
}

void PushFront(Node*& head, int newData) //Додавання вузла на початок
{
    Node* newNode = new Node{newData, head};
    head = newNode;
}

void PushBack(Node*& head, int newData) //Додавання вузла в кінець
{
    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = new Node{newData, nullptr};
}


int main()
{
    const int size = 5;

    int arr[size][size] = 
    {
        {5, 7, 8, 9, 5},
        {3, 6, 0, 7, 4},
        {7, 5, 4, 1, 2},
        {7, 8, 9, 6, 3},
        {7, 8, 5, 6, 8}
        
    };
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << arr[i][j] << setw(2);
        }
        cout << endl;
    }

    Node* head = new Node{78, nullptr}; 
    head->next = new Node{24, nullptr};
    head->next->next = new Node{31, nullptr};

    cout << "List: " << endl;
    ShowList(head);

    cout << "List after add node to the begin: " << endl;
    PushFront(head, 5);
    ShowList(head);

    cout << "List after add node to the end: " << endl;
    PushBack(head, 100);
    ShowList(head);

    int min[size];
    int max[size];
    ElementCols(arr, size, min, max);
    ElementRows(arr, size, min, max);
    MatrixUpAnDown(arr, size, size);
    MatrixDownAndUp(arr, size, size);
    MatrixFromLeftToRight(arr, size, size);
    MatrixChange(arr, size, size);
    MatrixRotated(arr, size, size);
    MatrixSymmetrical(arr, size, size);

    return 0;
}