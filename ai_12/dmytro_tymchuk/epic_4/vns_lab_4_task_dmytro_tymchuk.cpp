#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int change_min_max (double* arr, int size)
{
    double min = arr[0], max = arr[0];
    int max_index = 0, min_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (min > arr[i]) 
        {
            min = arr[i];
            min_index = i;
        }
        if (max < arr[i])
        {
            max = arr[i];
            max_index = i;
        }
    }
    cout<<"Мінімум :"<<min<<endl;
    cout<<"Максимум :"<<max<<endl;
    
    int change;
    change = arr[min_index];
    arr[min_index] = arr[max_index];
    arr[max_index] = change;
    
    return 0;
}

double average_sum (double* arr, int size)
{
    double av_sum = 0;
    for (int i = 0; i < size; i++)
    {
       av_sum += arr[i]; 
    }

    return (av_sum / size);
}

/*double delete_elements (double* arr, int size, double av_sum)
{
    int i = 0, j;
    double* new_arr = new double[size - 1];

    while (i < size)
    {
        if ((arr[i] > av_sum) && (av_sum - arr[i] > av_sum * 0.1))
        {
            for (int j = i + 1; j < size; j++)
            {
                new_arr[j - 1] = arr[j];
            }
            break;
            
        }
        else new_arr[i] = arr[i];
    }

    if (i >= size )
    {
        arr = new_arr;
        return 0;
    }
    else return delete_elements(new_arr, size - 1, av_sum);

}*/


int print_arr (double* arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
    }

int main()
{
    int size = 10;
    srand(static_cast<unsigned int>(std::time(0)));
    double* arr = new double [size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % 100;
    }
    cout<<"Масив випадкових чисел: ";
    
    print_arr(arr, size);

    change_min_max(arr, size);

    cout<<"Масив зі зміненим мінімом і максимумом: ";
    print_arr(arr, size);
    

    double av_sum = average_sum(arr, size);

    /*double* new_arr = new double [size];
    
    new_arr = delete_elements(arr, size, av_sum);

    for (int i = 0; i < sizeof(new_arr) / sizeof(double); i++)
    {
        cout << new_arr[i]<<" ";
    }*/
    
   int i = 0;
   while (i < size)
   {
        if ((arr[i] > av_sum) && (arr[i] - av_sum > av_sum * 0.1))
        {
            double* new_arr = new double[size - 1];
            int j = 0, new_size = 0;
            while (j < size)
            {
                if (i != j)
                {
                    new_arr[new_size] = arr[j];
                    j++;
                    new_size++;
                }
                else j++;
            }
            
            i = 0;
            for (int k = 0; k < new_size; k++)
            {
                arr[k] = new_arr[k];
            }
            
            size = new_size;
            delete[] new_arr;
        }
        else i++;
   }

    cout<<"Середнє значення: "<<av_sum<<endl;

    cout<<"Масив з видаленими елементами: ";
   print_arr(arr, size);
   
    delete[] arr;
    return 0;
}