#include <iostream>

using namespace std;

const int number_variant = 13; //  одна цілочисельна константа
int function_1(){
    int x; //одна цілочисельна змінна
    int cili [4]; // одновимірний масив
    float f; //одна дійсний з подвійною точністю змінна
    for (int i = 0; i < 5; i++)
    {
        cin >> cili[i];
    }
    cin >> f;
    
    int naybilsh[3];
    int naymensh[3];
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cili[j] > cili[j + 1])
            {
                swap(cili[j], cili[j + 1]);
            }
            
        }
        
    }
    if (f > cili[2])
    {
        naybilsh[0] = f;
        naymensh[3] = cili[2];
    }else{
        naymensh[0] = f;
        naybilsh[3] = cili[2];
    }
    
    naymensh[1] = cili[0];
    naymensh[2] = cili[1];
    naybilsh[1] = cili[3];
    naybilsh[2] = cili[4];

    int sum_naybilsh = 0;
    for (int i = 0; i < 4; i++)
    {
        sum_naybilsh += naybilsh[i]; 
    }
    int sum_naymensh = 0;
    for (int i = 0; i < 4; i++)
    {
        sum_naymensh += naymensh[i];
    }
    
    int oparation = 0;
    
    if (sum_naybilsh > sum_naymensh * 2)
    {
        oparation = sum_naybilsh * sum_naymensh;
        
    }else if (sum_naybilsh > sum_naymensh * 3)
    {
        oparation = sum_naybilsh / sum_naymensh;
    }else if (sum_naybilsh > sum_naymensh * 4)
    {
        oparation = sum_naybilsh + sum_naymensh;
        
    }
    
    x = oparation / number_variant;
    cout << x << endl;
    return x;
}

void function_2 (int arr[5][5], int x){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = x;
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int opartion = (x + number_variant + j - i) * rand() % 100 + 1;
            arr[i][j] = opartion;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void function_3 (int tower[5][5]){
    int arr[5];
    for (int col = 0; col < 10; col++) 
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9 - i; j++) 
            {
                if (tower[j][col] > tower[j + 1][col]) 
                {
                    swap(tower[j][col], tower[j + 1][col]);
                }
            }
        }
    }
}

int main(){
    int x = function_1();
    int matrix[5][5];
    function_2(matrix, x);
    return 0;
}