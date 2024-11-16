#include <iostream>
using namespace std;

void Sort(int temp[], int size);
void Show(int temp[], int size);
void Rotate(int temp[], int size, int K);
int main(){

    int N, K;
    cin >> N;
    if( N > 1000 || N < 1) return 1;
    cin >> K;
    if( K > 1000 || K < 1) return 1;


    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if(arr[i] > 100 || arr[i] < 0){
            return 1;
        }
    }

    int* temp = new int[N];
    int uniqueSize = 0;
    for (int i = 0; i < N; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueSize; j++) {
            if (arr[i] == temp[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            temp[uniqueSize++] = arr[i];
        }
    }
    delete[] arr;

    Sort(temp, uniqueSize);

    Rotate(temp, uniqueSize, K);

    Show(temp, uniqueSize);

    delete[] temp;
    return 0;
}

void Sort(int temp[], int size)
{
    
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(temp[i] > temp[j])
            {
                int temporary = temp[j];
                temp[j] = temp[i];
                temp[i] = temporary;
            }
        }
    }
}
void Show(int temp[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << temp[i] << " ";
    }
}
void Rotate(int temp[], int size, int K) {
    K = K % size;
    int* rotated = new int[size];

    for (int i = 0; i < size; i++) {
        rotated[i] = temp[(i + K) % size];
    }

    for (int i = 0; i < size; i++) {
        temp[i] = rotated[i];
    }

    delete[] rotated;
}