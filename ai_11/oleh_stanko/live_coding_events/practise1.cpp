#include <iostream>

using namespace std;

int main()
{
    int arr[5][5];
    int res1[5] = {-1110000,-1110000,-1110000,-1110000,-1110000};
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (arr[i][j]>res1[j])
            {
                res1[j]=arr[i][j];
            }
        }
    }
    cout << "answear for first point\n";
    for (int i=0; i<5; i++)
    {
        cout << res1[i] << " ";
    }
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (arr[i][j]<res1[j])
            {
                res1[j]=arr[i][j];
            }
        }
    }
    cout << "\nanswear for second point\n";
    for (int i=0; i<5; i++)
    {
        cout << res1[i] << " ";
    }
    
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (arr[i][j]>res1[i])
            {
                res1[i]=arr[i][j];
            }
        }
    }
    cout << "\nanswear for third point\n";
    for (int i=0; i<5; i++)
    {
        cout << res1[i] << " ";
    }
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (arr[i][j]<res1[i])
            {
                res1[i]=arr[i][j];
            }
        }
    }
    cout << "\nanswear for fourth point\n";
    for (int i=0; i<5; i++)
    {
        cout << res1[i] << " ";
    }
    cout << "\nanswear for sixth point\n";
    for (int i=4; i>=0; i--)
    {
        for (int j=4; j>=0; j--)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<=i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp; 
        }
    }
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   
    int rotated[5][5];
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            rotated[j][4 - i] = arr[i][j];
        }
    }
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    } 

    bool is_simetric=1;
    for (int i=0; i<5; i++)
    {
        if (!is_simetric)
        {
            break;
        }
        for (int j=0; j<5; j++)
        {
            if (rotated[i][j]!=rotated[j][i])
            {
                cout << "\nNO\n";
                is_simetric=0;
                break;
            }
        }
        cout << endl;
    }        
     
    int matrix_5x6[5][6];
 
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<6; j++)
        {
            cout << matrix_5x6[j][i];
        }
    }   
}