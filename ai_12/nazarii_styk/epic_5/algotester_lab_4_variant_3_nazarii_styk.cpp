#include <iostream>

void customSort(int arr[], int size, bool ascending) 
{
    // Просте сортування вставкою
    for (int i = 1; i < size; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        if (ascending) 
        {
            // Сортування за зростанням
            while (j >= 0 && arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                j--;
            }
        } 
        else 
        {
            // Сортування за спаданням
            while (j >= 0 && arr[j] < key) 
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

int main()
 {
    int n;
    std::cin >> n;

    int arr[1000];
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }

    // Масиви для збереження чисел з різними остачами
    int mod0[1000], mod1[1000], mod2[1000];
    int count0 = 0, count1 = 0, count2 = 0;

    // Розподіл чисел на три групи за остачею
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] % 3 == 0) 
        {
            mod0[count0++] = arr[i];
        } 
        else if (arr[i] % 3 == 1) 
        {
            mod1[count1++] = arr[i];
        } 
        else 
        {
            mod2[count2++] = arr[i];
        }
    }

    // Сортування груп за умовами
    customSort(mod0, count0, true);   // Числа з остачею 0 за зростанням
    customSort(mod1, count1, false);  // Числа з остачею 1 за спаданням
    customSort(mod2, count2, true);   // Числа з остачею 2 за зростанням

    // Об'єднання масивів у один та видалення дублікатів
    int result[1000];
    int resultSize = 0;

    auto addUnique = [&](int value) 
    {
        for (int i = 0; i < resultSize; ++i) 
        {
            if (result[i] == value) return; // Якщо значення вже існує, не додаємо
        }
        result[resultSize++] = value;
    };

    for (int i = 0; i < count0; ++i)
    { 
        addUnique(mod0[i]);
    }
    for (int i = 0; i < count1; ++i)
    {
        addUnique(mod1[i]);
    }
    for (int i = 0; i < count2; ++i)
    { 
        addUnique(mod2[i]);
    }

    // Виведення результату
    std::cout << resultSize << "\n";
    for (int i = 0; i < resultSize; ++i) 
    {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
