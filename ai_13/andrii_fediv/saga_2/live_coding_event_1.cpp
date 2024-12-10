#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;
int MY_VARIANT = 80;

void buble(double *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int randomFN(const int from, const int to)//цілочисельна константа (для безпеки)
{
    random_device rd;
    return from + (rd() % (to - from + 1));//математичні операції та математичні функції для генерації
}

double function_1()
{
    float a, b;//дійсна змінна (за умовою)
    int c, d, e;//цілочисельна змінна (за умовою)
    double f;//дійсна з подвійною точністю змінна (за умовою)

    cin >> a >> b >> c >> d >> e >> f;//оператор виведення даних 

    double *arr = new double[6]{a, b, c, d, e, f};

    buble(arr, 6);
    double min_sum = arr[0] + arr[1] + arr[2];
    double max_sum = arr[3] + arr[4] + arr[5];

    double result;
    if (max_sum > min_sum * 2)//розгалуження (для виконання умови)
    {
        result = max_sum * min_sum;
    }
    else if (max_sum > min_sum * 3)//розгалуження (для виконання умови)
    {
        result = max_sum / min_sum;
    }
    else if (max_sum > min_sum * 4)
    {
        result = max_sum + min_sum;
    }

    result = result / MY_VARIANT;
    return result;
}

double **function_2(double *x)
{
    double **matrix = new double *[5];//двовимірний масив + (вказівник по умові)
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5]{*x, *x, *x, *x, *x};
    }

    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrix[i][j] = (matrix[i][j] + MY_VARIANT + j - i) * randomFN(1, 100);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

double *function_3(double **matrix)
{
    double *arr1 = new double[5];
    double *arr2 = new double[5];

    double **m_rotated = new double *[5];
    for (int i = 0; i < 5; i++)
    {
        m_rotated[i] = new double[5];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            m_rotated[i][j] = matrix[j][i];
        }
        buble(m_rotated[i], 5);
        arr1[i] = m_rotated[i][0];
    }

    for (size_t i = 0; i < 5; i++)
    {
        int min = 0;
        for (int j = 0; j < 5; j++)
        {
            if (matrix[j][i] < matrix[min][i])
            {
                min = j;
            }
        }
        arr2[i] = matrix[min][i];
    }

    bool acc = true;
    for (size_t i = 0; i < 5; i++)
    {
        if (arr1[i] != arr2[i])
            acc = false;
    }

    if (acc)
    {
        cout << "YEEEESSS\n";//оператор введення даних 
    }
    else
    {
        cout << "NOOOOOOOO\n";
    }
    return arr1;
}

struct Student//своя структура даних
{
    string name;
    string surname;
    double money;

    Student(string n1, string n2, double n3) : name(n1), surname(n2), money(n3) {};
};

struct DCL
{
    Student *data;
    DCL *prev;
    DCL *next;
};

DCL *function_4(double *arr)
{
    DCL *head = nullptr;

    DCL *current = head;
    for (int i = 0; i < 7; i++)///цикл щоб провести 7 ітераціій
    {
        string name, surname;
        double money;

        double *arrr_copy = new double[5];
        for (int i1 = 0; i1 < 5; i1++)
        {
            arrr_copy[i1] = arr[i1];
        }

        buble(arrr_copy, 5);
        if (i == 0)
        {
            money = arrr_copy[4];
        }
        else if (i >= 1 && i <= 5)
        {
            double arr_sum = 0;
            for (int i = 0; i < 5; i++)
            {
                arr_sum += arr[i];
            }
            money = arr_sum;
        }
        else if (i == 6)
        {
            money = arrr_copy[0];
        }

        for (int i1 = 0; i1 < 7; i1++)
        {
            name += static_cast<char>(randomFN(97, 122));
            surname += static_cast<char>(randomFN(97, 122));
        }

        if (current == nullptr)
        {
            current = new DCL();
            current->data = new Student(name, surname, money);
            current->next = nullptr;
            current->prev = nullptr;
            head = current;
        }
        else
        {
            current->next = new DCL();
            current->next->data = new Student(name, surname, money);
            current->next->prev = current;
            current->next->next = nullptr;
            current = current->next;
        }
    }

    current = head;
    while (current != nullptr)
    {
        cout << current->data->name << " " << current->data->surname << " " << current->data->money << endl;
        current = current->next;
    }
    return head;
}

void help_for_function_5(fstream *file, DCL *current, bool first_iter)//перевантаження функції + рекурсія + параметри та аргументи (за умовою)
{
    if (first_iter)
    {

        while (current->next != nullptr)
        {
            current = current->next;
        }
    }
    if (current == nullptr)
        return;

    *file << current->data->name << " " << current->data->surname << " " << current->data->money << "\n";//запис у файл

    help_for_function_5(file, current->prev, false);
}

void help_for_function_5(fstream *file, DCL *current)//перевантаження функції (за умовою)
{
    while (current != nullptr)//цикл щоб достукатися до всіх елементів list
    {
        *file << current->data->name << " " << current->data->surname << " " << current->data->money << "\n";
        current = current->next;
    }
}

void function_5(DCL *students)
{
    fstream file("students.txt", ios::out);
    if (MY_VARIANT % 2 == 0)
    {

        help_for_function_5(&file, students, true);
    }
    else
        help_for_function_5(&file, students);

    file.close();

    ifstream file1;
    file1.open("students.txt");
    if (!file)
    {
        cout << "errror\n";
        return;
    }
    cout << "from file:\n";
    for (int i = 0; i < 7; i++)
    {
        string s;
        getline(file1, s);//зчитування з файлу
        cout << s << endl;
    }
}

int main()
{
    double x = function_1();
    double **tower = function_2(&x);
    double *arr = function_3(tower);//одновимірний масив (по умові)
    DCL *students = function_4(arr);
    function_5(students);
    return 0;
} // 0.75 0.0008 24 2435 1 0.00003