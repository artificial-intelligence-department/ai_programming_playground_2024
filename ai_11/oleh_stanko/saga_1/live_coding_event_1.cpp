#include <iostream>

using namespace std;

void first_exercise()
{
    float a,b;
    cin >> a >> b;
    int c,d,e;
    cin >> c >> d >> e;
    double f;
    cin >> f;
    double arr[6] = {a,b,c,d,e,f};
    for (int i=0; i<6; i++)
    {
        bool was_changed=0;
        for (int j=0; j<6; j++)
        {
            if (arr[j]<arr[j+1])
            {
                double temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                was_changed=1;
            }
        } 
        if (!was_changed)
        {
            break;
        }
    }
    cout << arr[0];
} 

int main()
{
    first_exercise();
}