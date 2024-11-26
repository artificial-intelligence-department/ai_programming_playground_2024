#include <stdio.h>
#include <iostream>
#include <array>

using namespace std;

int main(){
    int myarray[10] = {-50, -60, -85, 66, 41, 2, -2, -6, 44, 4};
    // 1
    for (int i = 0; i < 10; i++)
    {
        // myarray[i] = rand() % 200 + -100;
        cout << myarray[i] << " ";
    }
    cout << "\n";

    // 3
    int newsize = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 3 != 0)
        {
            myarray[newsize++] = myarray[i];
        }
    }

    int* myarray2 = new int[newsize];
    
    for (int i = 0; i < newsize; i++)
    {
        myarray2[i] = myarray[i];
    }
    for (int i = 0; i < newsize; i++) cout << myarray2[i] << " ";
    cout << endl;

    // 4

    for (int i = 0; i < newsize; )
    {
        if (myarray2[i] < 0)
        {
            int* newArr = new int[newsize + 1];
            memcpy(newArr, myarray2, (i+1) * sizeof(int));
            newArr[i+1] = myarray2[i]+1;
            memcpy(newArr + (i+1) + 1, myarray2 + (i+1), (newsize - (i+1)) * sizeof(int));
            delete[] myarray2;
            myarray2 = newArr;
            ++newsize;
            i += 2;
        }
        else{
            ++i;
        }
        
    }
    for (int i = 0; i < newsize; i++) cout << myarray2[i] << " ";
            cout << endl;

    delete[] myarray2;
}




