#include <iostream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int a[1000];
    int b[1000];
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        bool unique = true;
        for (int j = 0; j < size; j++)
        {
            if (a[j] == x)
            {
                unique = false;
                break;
            }
            
        }
        if (unique)
        {
            a[size++] = x;
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
        }
        
    }
    K %= size;

    for (int i = 0; i < size; i++)
    {
        b[i] = a[(i + K) % size];
    }
    
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << b[i] << " ";
        
    }

    return 0;
}