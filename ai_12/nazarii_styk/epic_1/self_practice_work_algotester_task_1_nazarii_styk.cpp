#include <iostream>
using namespace std;

int main()
{
    cout << "Enter count of exams: ";
    int count; 
    cin >> count;

    cout << "Enter grades: ";
    int grades[7]; 
    bool Great = true;
    bool Good = true;

   
    for (int i = 0; i < count; i++)
    {
        cin >> grades[i];

        if (grades[i] < 90)
        {
            Great = false;
        }

        if (grades[i] < 51) 
        {
            Good = false;
        }
    }
    

    if (Great)
    {
        cout << "Pidvyshchena" << endl;
    }
    else if (Good) 
    {
        cout << "Zvychaina" << endl;
    }
    else 
    {
        cout << "Zabud pro stypendiiu" << endl;
    }

    return 0;
}
