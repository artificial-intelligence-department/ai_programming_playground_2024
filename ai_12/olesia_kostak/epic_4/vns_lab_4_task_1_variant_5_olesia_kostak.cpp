 #include <iostream>
#include <cstdlib>
#include <ctime>

void print_array(int arr[], int N);


int main()
{
    int N = 20;
    int* arr = new int[N];
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < N; i++) //initialization
        arr[i] = rand();

    std::cout << "Start array: " << std::endl;
    print_array(arr, N);   
    std::cout << std::endl;

    // Removing elements
    for(int i = 0; i < N; i++)
    {
        if(arr[i] % 7 == 0)
        {
            N--;
            for(int j = i; j < N; j++)
                arr[j] = arr [j + 1];
        }
    }

    //Adding an element after odd
    for(int i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 1)
        {
            for(int j = N; j > i; j--)
                arr[j] = arr[j - 1];

            arr[i + 1] = 0;
            i++;
            N++;
        }
    }
    
    std::cout << "Resulting array: " << std::endl;
    print_array(arr, N); 
    delete[] arr;

    return 0;

}

void print_array(int arr[], int N)
{
    for(int i = 0; i < N; i++) //printing
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return;
}