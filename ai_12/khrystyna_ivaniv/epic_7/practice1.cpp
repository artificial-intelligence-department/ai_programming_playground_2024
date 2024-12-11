#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void write_list_4(Node *head, ofstream &out_file)
{

    out_file << head->data;
    if (head == nullptr)
    {
        return;
    }
    out_file << head->data;
    if (head->next != nullptr)
    {
        out_file << ",";
    }
    write_list_4(head->next, out_file);
}

void write_list_4(Node* head) {
    Node* current = head;
    
    while (current != nullptr) {
        cout << current->data << " ";  
        current = current->next;        
    }
    cout << endl;  
}

void write_list_4(Node* head, ofstream& out_file) {
    Node* current = head; 
    
    while (current != nullptr) {
        out_file << current->data << endl;  
        current = current->next;           
    }
}

Node *create_node(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void push_back(Node *&head, int value)
{
    Node *newNode = create_node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void push_front(Node *&head, int value)
{
    Node *newNode = create_node(value);
    newNode->next = head;
    head = newNode;
}

void push_list(Node *head, int target, int value)
{
    Node *temp = head;
    while (temp != nullptr && temp->data != target)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "Target value not found in the list";
        return;
    }

    Node *newNode = create_node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void bubble_sort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

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

void free_list(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

struct Node1
{
    int data;
    Node1 *next;
    Node1 *previous;
};

Node1 *create_node1(int value)
{
    Node1 *newNode = new Node1;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    return newNode;
}

void push_back1(Node1 *&head, int value)
{
    Node1 *newNode = create_node1(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node1 *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
}

void push_front1(Node1 *&head, int value)
{
    Node1 *newNode = create_node1(value);
    if (head != nullptr)
    {
        head->previous = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void push_list1(Node1 *head, int target, int value)
{
    Node1 *temp = head;
    while (temp != nullptr && temp->data != target)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "Target value not found in the list";
        return;
    }

    Node1 *newNode = create_node1(value);
    newNode->next = temp->next;
    newNode->previous = temp;
    if (temp->next != nullptr)
    {
        temp->next->previous = newNode;
    }
    temp->next = newNode;
}

void print_list1(Node1 *head)
{
    Node1 *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void bubble_sort1(Node1 *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;
    do
    {
        swapped = false;
        Node1 *current = head;
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

void free_list(Node1 *&head)
{
    while (head != nullptr)
    {
        Node1 *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    int size = 5;
    int matrix[size][size];

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
    // найменший елемент стовбців
    int array1[size];

    for (int i = 0; i < size; i++)
    {
        int min = matrix[0][0];
        for (int j = 0; j < size; j++)
        {
            if (matrix[j][i] < min)
            {
                min = matrix[j][i];
            }
        }
        array1[i] = min;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array1[i] << " ";
    }

    // найбільший елемент стовбців
    int array2[size];
    for (int i = 0; i < size; i++)
    {
        int max = matrix[0][0];
        for (int j = 0; j < size; j++)
        {
            if (matrix[j][i] > max)
            {
                max = matrix[j][i];
            }
        }
        array2[i] = max;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array2[i] << " ";
    }

    // найбільший елемент стрічок
    int array3[size];

    for (int i = 0; i < size; i++)
    {
        int max = matrix[0][0];
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        array3[i] = max;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array3[i] << " ";
    }

    // найменший елемент стрічок
    int array4[size];

    for (int i = 0; i < size; i++)
    {
        int min = matrix[0][0];
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        array4[i] = min;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array4[i] << " ";
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // вивести матрицю з нижнього правого кута
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = size - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // обернути значення матриці відносно якоїсь діагоналі
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = matrix[j][i];
        }
    }
    // обернути значення матриці відносно якоїсь діагоналі
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = size - 1; j >= 0; j--)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    bool symmetric = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                symmetric = false;
            }
        }
        cout << endl;
    }

    if (symmetric)
    {
        cout << "is sym" << endl;
    }
    else
    {
        cout << "is not sym" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    srand(time(0));
    int size = 4;
    int matrix1[size][size];
    int matrix2[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix1[i][j] = rand() % 50 + 1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix2[i][j] = rand() % 50 + 1;
        }
    }
    // Додавання двох матриць
    int sum_matrix[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Множення двох матриць
    int mult_matrix[size][size];
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (int k = 0; k < size; ++k)
            {
                mult_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    //  Пошук конкретного елемента в матриці
    int value;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix1[i][j] == value)
            {
                cout << "value at " << i << " row and " << j << " column " << endl;
            }
        }
    }

    // Обчислення детермінанта
    int det = 0;
    int submat[size][size];
    for (int x = 0; x < size; ++x)
    {
        int subi = 0;
        for (int i = 1; i < size; ++i)
        {
            int subj = 0;
            for (int j = 0; j < size; ++j)
            {
                if (j == x)
                    continue;
                submat[subi][subj] = matrix1[i][j];
                subj++;
            }
            subi++;
        }
        // det += (x % 2 == 0 ? 1 : -1) * matrix1[0][x] * det(submat, size - 1);
    }
    //  Пошук мінімального елемента
    int min_value = matrix1[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix1[i][j] < min_value)
                ;
            {
                min_value = matrix1[i][j];
            }
        }
    }

    // - Пошук максимального елемента
    int max_value = matrix1[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix1[i][j] > max_value)
                ;
            {
                max_value = matrix1[i][j];
            }
        }
    }

    // - Пошук суми всіх елементів
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += matrix1[i][j];
        }
    }

    // - Пошук середнього значення
    int avarage = sum / (size * size);

    // - Пошук діагональних елементів
    bool diagonal = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                diagonal = true;
            }
        }
    }

    // - Пошук рядка з максимальною сумою
    int sums[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sums[i] += matrix1[i][j];
        }
    }
    int max_sum = sums[0];
    for (int i = 0; i < size; i++)
    {
        if (sums[i] > max_sum)
        {
            max_sum = sums[i];
        }
    }

    // - Пошук парних елементів
    bool is_even = false;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix1[i][j] % 2 == 0)
            {
                is_even = true;
            }
        }
    }

    ofstream out_file("example.txt");
    out_file << "число, місяць, рік" << endl;
    out_file << "17, лютий, 2007" << endl;
    out_file << "23, березень, 2009" << endl;
    out_file.close();

    ifstream in_file("example.txt");
    string line;
    while (getline(in_file, line))
    {
        stringstream ss(line);
        string item;
        while (getline(ss, item, ','))
        {
            cout << item << " ";
        }
        cout << endl;
    }
    in_file.close();

    struct Data
    {
        int number;
        char name[20];
    };

    ofstream out_file("example.binary", ios::binary);
    Data d1 = {1, "A"};
    Data d2 = {2, "B"};
    out_file.write(reinterpret_cast<char *>(&d1), sizeof(Data));
    out_file.write(reinterpret_cast<char *>(&d2), sizeof(Data));
    out_file.close();

    ifstream in_file("example.binary", ios::binary);
    Data d;
    while (in_file.read(reinterpret_cast<char *>(&d), sizeof(Data)))
    {
        cout << "number: " << d.number << ", Name: " << d.name << endl;
    }

    in_file.close();

    return 0;
}
