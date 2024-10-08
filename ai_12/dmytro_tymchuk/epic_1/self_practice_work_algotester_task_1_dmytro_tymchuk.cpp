///Щасливенькі числа (1402)

#include<iostream>
using namespace std;

int main()
{
    int n, s=0 ,kil=0, m, f=0;

    cin>>n;

    for (int i = 4; i <= n; i++)
    {
        m=i; s=0; f=0;
        while (m>0)
        {
            s+=m % 10;
            m/=10;
        }

        while  ((s>0) && (f==0))
        {
            if ((s % 10 != 7) && (s % 10 != 4))
            {
                f = 1;
            }
            else s/=10;
        }

        if (f==0) kil++;

    }
    
    cout<<kil<<endl;

    return 0;
}