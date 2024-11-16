#include <iostream>

int MaxIndex (const int* road, int size)
{
    int maxindex=0;
    for (int i=0; i<size; i++)
    {
        if (road[i]>road[maxindex])
        {
            maxindex=i;
        }
    }
    return maxindex;
}

int MinIndex (const int* road, int size)
{
    int minindex=0;
    for (int i=0; i<size; i++)
    {
        if (road[i]<road[minindex])
        {
            minindex=i;
        }
    }
    return minindex;
}

void removeanelement (int* road, int size, int m)
{
    for (int i=0; i<size; i++)
    {
        if (road[i]==road[m])
        {
            size--;
            for (int j=i; j<size; j++)
            {
                road[j] = road[j+1];
            }
            break;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    int* road=new int[n];
    int* road1=new int[n];
    int* road2=new int[n];
    for (int i=0; i<n; i++)
    {
        std::cin >> road[i];
        road1[i]=road[i];
        road2[i]=road[i];
    }
    removeanelement(road1, n, MaxIndex(road, n));
    removeanelement(road2, n, MinIndex(road, n));
    int fatigue1=road1[MaxIndex(road1, n-1)]-road1[MinIndex(road1, n-1)];
    int fatigue2=road2[MaxIndex(road2, n-1)]-road2[MinIndex(road2, n-1)];
    std::cout << std::min(fatigue1, fatigue2);
}