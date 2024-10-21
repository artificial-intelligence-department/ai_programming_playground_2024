#include <iostream>
using namespace std;

int main()
 {
    int k, n; 
    cin >> k >> n;
    
    int c[n];  
    for (int i = 0; i < n; i++)
     {
        cin >> c[i];
    }
    
    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (c[j] > c[j + 1])
             {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    
    int count = 0; 
    for (int i = 0; i < n; i++)
     {
        if (k >= c[i])
         {
            k -= c[i];  
            count++;  
        }
         else
        {
            break; 
        }
    }
    
    cout << count << endl;  
    return 0;
}
