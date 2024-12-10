#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

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
            cout << "Елемента, після якого має додатись вузол в списку нема!" << endl;
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
    cout << endl;
}

void printList2(Node2 *head)
{
    Node2 *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void printList2Back(Node2 *tail)
{
    Node2 *current = tail;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
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

int main()
{
    Node *head = nullptr;

    addToBeginning(head, 1);
    addToBeginning(head, 2);
    addToBeginning(head, 9);
    cout << "Список після додавання вузлів на початок: " << endl;
    printList(head);

    addToEnd(head, 4);
    addToEnd(head, 5);
    addToEnd(head, 6);
    cout << "Список після додавання вузлів на кінець: " << endl;
    printList(head);

    addToCenter(head, 2, 7);
    addToCenter(head, 5, 8);
    cout << "Список після додавання вузлів на конкретне місце: " << endl;
    printList(head);

    bubbleSort(head);
    cout << "Список після сортування бульбашковим методом:" << endl;
    printList(head);

    addToBeginning(head, 11);
    addToEnd(head, 3);
    addToCenter(head, 4, 13);
    cout << "Cписок після додавання нових елементів:" << endl;
    printList(head);

    sort(head);
    cout << "Список після сортування методом вибору:" << endl;
    printList(head);

    cout << "Список виведений рекурсивною ф-єю:" << endl;
    printList(head, true);

    Node2 *head2 = nullptr;
    Node2 *tail = nullptr;

    addToBeginning2(head2, tail, 1);
    addToBeginning2(head2, tail, 2);
    addToBeginning2(head2, tail, 7);
    cout << "Двозв. список після додавання вузлів на початок: " << endl;
    printList2(head2);

    addToEnd2(head2, tail, 4);
    addToEnd2(head2, tail, 5);
    addToEnd2(head2, tail, 6);
    cout << "Двозв. список після додавання вузлів на кінець: " << endl;
    printList2(head2);

    cout << "Двозв. список виведений зправа наліво: " << endl;
    printList2Back(tail);

    addToCenter2(head2, tail, 2, 10);
    addToCenter2(head2, tail, 5, 8);
    cout << "Двозв. список після додавання вузлів на конкретне місце: " << endl;
    printList2(head2);

    bubbleSort2(head2);
    cout << "Двозв. список після сортування бульбашковим методом:" << endl;
    printList2(head2);

    addToBeginning2(head2, tail, 9);
    addToEnd2(head2, tail, 3);
    addToCenter2(head2, tail, 4, 13);
    cout << "Двозв. список після додавання нових елементів:" << endl;
    printList2(head2);

    sort2(head2, tail);
    cout << "Двозв. список після сортування методом вибору:" << endl;
    printList2(head2);

    int **matrix = new int *[5];
    int x = 1;
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
           matrix[i][j] = x;
           x++;
        }
    }

    // int matrix[5][5] = {
    //     {1, 2, 3, 4, 5},
    //     {6, 7, 8, 9, 10},
    //     {11, 12, 13, 14, 15},
    //     {16, 17, 18, 19, 20},
    //     {21, 22, 23, 7, 25}};

    cout << "Початкова матриця:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int minarrcol[5];
    int maxarrcol[5];

    // знайти найменший елемент стовбців і записати в масив з 5 елементів
    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = matrix[j][i];
        }
        minarrcol[i] = *min_element(temp, temp + 5);
    }

    // знайти найбільший елемент стовбців і записати в масив з 5 елементів
    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = matrix[j][i];
        }
        maxarrcol[i] = *max_element(temp, temp + 5);
    }

    int minarrow[5];
    int maxarrow[5];

    // знайти найменший елемент стрічок і записати в масив з 5 елементів
    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = matrix[i][j];
        }
        minarrow[i] = *min_element(temp, temp + 5);
    }

    // знайти найбільший елемент стрічок і записати в масив з 5 елементів
    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = matrix[i][j];
        }
        maxarrow[i] = *max_element(temp, temp + 5);
    }

    cout << "Стовпець " << '\t' << "min " << '\t' << "max" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << '\t' << '\t' << minarrcol[i] << '\t' << maxarrcol[i] << endl;
    }

    cout << "Рядок " << '\t' << '\t' << "min " << '\t' << "max" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << '\t' << '\t' << minarrow[i] << '\t' << maxarrow[i] << endl;
    }

    // вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
    cout << "Матриця з нижнього правого кута вверх і вниз по стовпцям:" << endl;
    for (int i = 4; i >= 0; i--)
    {
        if (i % 2 != 0)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << matrix[j][i] << " ";
            }
        }
        else
        {
            for (int j = 4; j >= 0; j--)
            {
                cout << matrix[j][i] << " ";
            }
        }
    }
    cout << endl;

    // вивести матрицю з нижнього правого кута з ліва на право, з верху вниз
    cout << "Матриця з нижнього правого кута з ліва на право, з верху вниз:" << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
    cout << "Матриця обернена відносно головної діагоналі:" << endl;
    int rotatedmatr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            rotatedmatr[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << rotatedmatr[i][j] << " ";
        }
        cout << endl;
    }

    // зробити поворот матриці на 90 градусів
    cout << "Матриця обернена на 90 градусів: " << endl;
    int rotatedby90[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            rotatedby90[i][j] = rotatedmatr[i][4 - j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << rotatedby90[i][j] << " ";
        }
        cout << endl;
    }

    // перевірити чи матриця симетрична
    bool symmetryc = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                symmetryc = false;
            }
        }
    }
    if (symmetryc)
    {
        cout << "Матриця симетрична!" << endl;
    }
    else
    {
        cout << "Матриця не симетрична!" << endl;
    }

    // взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
    cout << "Матриця 5*6:" << endl;
    int matr56[5][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}};
    int trans[6][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            trans[j][i] = matr56[i][j];
            cout << matr56[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Транспонована матриця:" << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    // Ініціалізація матриці: Заповнення статичного двовимірного масиву.
    int inputmatr[5][5];
    cout << "Введіть матрицю: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> inputmatr[i][j];
        }
    }

    // Додавання двох матриць: Елемент за елементом додаються елементи двох матриць.
    int sum[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum[i][j] = matrix[i][j] + inputmatr[i][j];
        }
    }

    cout << "Матриця суми:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    // Множення двох матриць: Класичний алгоритм множення матриць.
    int mnoz[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                mnoz[i][j] += matrix[i][k] * inputmatr[k][j];
            }
        }
    }
    cout << "Перемножені матриці:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mnoz[i][j] << " ";
        }
        cout << endl;
    }

    // Пошук максимуму/мінімуму в матриці.
    cout << "Максимум матриці: " << endl;
    int max = *max_element(maxarrcol, maxarrcol + 5);
    cout << max << endl;

    cout << "Мінімум матриці: " << endl;
    int min = *min_element(minarrcol, minarrcol + 5);
    cout << min << endl;

    // Обчислення детермінанта (для квадратних матриць).
    cout << "Детермінант матриці: ";
    int det = 0;
    for (int x = 0; x < 5; x++)
    {
        // Створення мінору
        int submatrix[10][10];
        int subr = 0; // Рядок мінору
        for (int i = 1; i < 5; i++)
        {
            int subc = 0; // Стовпець мінору
            for (int j = 0; j < 5; j++)
            {
                if (j == x)
                    continue; // Пропускаємо стовпець, по якому розкладаємо
                submatrix[subr][subc] = matrix[i][j];
                subc++;
            }
            subr++;
        }

        // Рекурсивне обчислення детермінанта мінору
        int sub_det = 1; // Початкове значення для детермінанта мінору
        if (5 - 1 == 2)
        {
            // Якщо мінор 2x2
            sub_det = (submatrix[0][0] * submatrix[1][1]) - (submatrix[0][1] * submatrix[1][0]);
        }
        else if (5 - 1 == 1)
        {
            // Якщо мінор 1x1
            sub_det = submatrix[0][0];
        }

        det += pow(-1, x) * matrix[0][x] * sub_det;
    }
    cout << det << endl;

    // Пошук конкретного елемента в матриці
    cout << "Введіть елемент розташування якого хочете знайти: ";
    int find;
    cin >> find;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (find == matrix[i][j])
            {
                cout << "Елемент розташований у " << i + 1 << " рядку " << j + 1 << " стовпці" << endl;
            }
        }
    }

    // Пошук суми всіх елементів
    cout << "Сума всіх елементів матриці:" << endl;
    int sumel = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sumel += matrix[i][j];
        }
    }
    cout << sumel << endl;

    // Пошук середнього значення
    cout << "Середнє значення всіх елементів матриці:" << endl;
    int mid, count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            count++;
        }
    }
    mid = sumel / count;
    cout << mid << endl;

    // Пошук діагональних елементів
    cout << "Всі діагональні елементи матриці: ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
    cout << endl;

    // Пошук рядка з максимальною сумою
    cout << "Рядок з максимальною сумою: ";
    int maxsum = 0;
    int maxrow;
    for (int i = 0; i < 5; i++)
    {
        int rowsum = 0;
        for (int j = 0; j < 5; j++)
        {
            rowsum += matrix[i][j];
        }
        if (rowsum > maxsum)
        {
            maxsum = rowsum;
            maxrow = i;
        }
    }
    cout << maxrow + 1 << endl;

    // Пошук числа, що повторюється найбільше
    cout << "Елемент що повторюється найбільше: ";
    int common = 0;
    int commonel;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int times = 0;
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if (matrix[i][j] == matrix[k][l])
                    {
                        times++;
                    }
                }
            }
            if (times > common)
            {
                common = times;
                commonel = matrix[i][j];
            }
        }
    }
    if (common == 1)
    {
        cout << endl;
        cout << "Нема одного найчастішого елементу!" << endl;
    }
    else
    {
        cout << commonel << endl;
    }

    // Пошук парних елементів
    cout << "Парні елементи матриці: ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    return 0;
}

// 25 24 23 22 21
// 20 19 18 17 16
// 15 14 13 12 11
// 10 9 8 7 6
// 5 4 3 2 1