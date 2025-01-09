#include <iostream>

using namespace std;

int main()
{
    int teams, people;
    cin >> people >> teams;
    int arr[teams] = {};
    if (people > teams * 3 || teams > people)
    {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < teams; i++)
    {

        if (people - teams > 0)
        {
            for (int j = 0; j < teams; j++)
                arr[j]++;

            people -= teams;
        }
    }
    int count = 0;
    while (people > 0)
    {
        arr[count]++;
        count++;
        people--;
    }
    for (int i = 0; i < teams; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}