#include <iostream>

void print_arr(int arr[], int size, int start, FILE* fptr);
void print_arr(int arr[], int size, const char* file_name);

int main()
{
    int const SIZE = 6;
    const char* file_name = "file_for_practice_task_4.txt";
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        std::cin >> arr[i];
    
    ///the 1 way
    FILE* fptr;
    fptr = fopen(file_name, "w");
    if (fptr != nullptr)
        print_arr(arr, SIZE, 0, fptr);
    fclose(fptr);

    ///the 2 way
    print_arr(arr, SIZE, file_name);
    return 0;
}

void print_arr(int arr[], int size, int start, FILE* fptr)
{
    if (start == size)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << arr[start] << " ";
    fprintf(fptr, "%d ", arr[start]);
    print_arr(arr, size, start + 1, fptr);
}

void print_arr(int arr[], int size, const char* file_name) ///fucntion oveloading
{
    int i = 0;
    FILE* fptr;
    fptr = fopen(file_name, "w");
    while (i != size)
    {
        std::cout << arr[i] << " ";
        fprintf(fptr, "%d ", arr[i]);
        i++;
    }
    std::cout << std::endl;
    fclose(fptr);
}