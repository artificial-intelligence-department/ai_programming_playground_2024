// lab3 v2

#include <iostream>

using namespace std;

bool isInMass(int mass[], int size, int value) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (mass[i] == value) 
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    int N, M;

    cin >> N;
    int *MassA = new int[N];

    for (int i = 0; i < N; ++i) 
    {
        cin >> MassA[i];
    }

    cin >> M;
    int *MassB = new int[M];

    for (int i = 0; i < M; ++i) 
    {
        cin >> MassB[i];
    }

    int *uniqueMass = new int[N + M];
    int uniqueSize = 0;

    int *commonMass = new int[N + M];
    int commonSize = 0;

    for (int i = 0; i < N; ++i) 
    {
        if (isInMass(MassB, M, MassA[i]) && !isInMass(commonMass, commonSize, MassA[i])) 
        {
            commonMass[commonSize++] = MassA[i];
        }
    }

    for (int i = 0; i < N; ++i) 
    {
        if (!isInMass(uniqueMass, uniqueSize, MassA[i])) 
        {
            uniqueMass[uniqueSize++] = MassA[i];
        }
    }

    for (int i = 0; i < M; ++i) 
    {
        if (!isInMass(uniqueMass, uniqueSize, MassB[i])) 
        {
            uniqueMass[uniqueSize++] = MassB[i];
        }
    }

    cout << commonSize << endl;
    cout << uniqueSize << endl;

    delete[] MassA;
    MassA = 0;

    delete[] MassB;
    MassB = 0;
    
    return 0;
}
