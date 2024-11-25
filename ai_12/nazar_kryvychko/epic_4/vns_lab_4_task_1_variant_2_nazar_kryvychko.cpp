#include<iostream>
using namespace std;

// 1) При виконанні роботи використовуються статичні масиви. Для організації
// статичних масивів із псевдозмінними межами необхідно оголосити масив
// досить великої довжини, наприклад, 100 елементів:
// int N=100;
// int a[N];

// Потім користувач вводить реальну довжину масиву (не більше N) і працює з
// масивом тієї довжини, що він сам вказав. Інші елементи (хоча пам'ять під них і
// буде виділена) не розглядаються.
// 2) При зменшенні або збільшенні довжини масиву необхідно змінювати його
// реальну довжину.

// 1) Сформувати одновимірний масив цілих чисел, використовуючи генератор
// випадкових чисел.
// 2) Роздрукувати отриманий масив.
// 3) Знищити перший елемент, який дорівнює 0.

// 4) Додати після кожного парного елемента масиву елемент зі значенням M[I-
// 1]+2.

// 5) Роздрукувати отриманий масив.


template<typename T>
void print_array(T* array, const size_t& size, const char& delim = ' ')
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << delim;
    }
    std::cout << "\b\b"; // erasing last delimiter
    std::cout << std::endl;
}


template<typename T>
void fill_random(T* array,const size_t& size)
{
    srand((unsigned) time(NULL)); // for time dependency
    for (size_t i = 0; i < size; i++)
    {
        *(array + i) = rand() % 10 + 1  ;
    }
}

void destroy_first_zero(int* arr, const size_t& size)
{
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] == 0)
        {
            for (size_t j = i; j < size-1; j++)
            {
                arr[j] = arr[j+1];
            }
            arr[size-1] = -1; // for garbage ( deleted ) value
            break;
        }
    }
}

void add_after_even(int* arr, size_t& size)
{
    // Skiping first because it doesnt have past element
    for (size_t i = 1; i < size; i++) {
        if (arr[i] % 2 == 0) {
            for (size_t j = size; j > i + 1; --j) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = arr[i-1] + 2;
            size++;
            i++;
        }
    }
    
}

int main(void)
{
    const int N = 100;
    int array[N];
    size_t userN;
    std::cout << "Enter array length: ";
    cin >> userN;
    if(userN > N)
    {
        std::cout << "Ooops... too much memory allocated, try again with less size" << std::endl;
        exit(-1);
    }

    fill_random(array,userN);
    print_array(array,userN);
    add_after_even(array,userN);
    print_array(array,userN);

    return 0;
}