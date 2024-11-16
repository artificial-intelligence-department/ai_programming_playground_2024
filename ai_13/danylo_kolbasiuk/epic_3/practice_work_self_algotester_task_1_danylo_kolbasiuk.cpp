#include <iostream>

int main()
{
    int n,daynum;
    std::string currentday;
    int k[7]={0,0,0,0,0,0,0};
    std::string day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    std::cin >> currentday;
    std::cin >> n;
    for (int i=0; i<7; i++)
    {
        if(day[i]==currentday)
        {
            daynum=i;
            break;
        }
    }
    int remain_day=n%7;
    for (int i=0;i<7;i++)
    {
        k[i]+=n/7;
    }
    for (int i=0; i<remain_day; i++)
    {
        k[(daynum+i)%7]++;
    }
    for (int i=0; i<7; i++)
    {
        std::cout << k[i] << " ";
    }
    return 0;
}