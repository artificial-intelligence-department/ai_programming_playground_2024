#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int r[N];
    for (int i=0; i<N; i++)
    {
        cin>>r[i];
    }
    int a,b,c;
    cin>>a>>b>>c;
    int M=0;
    int r1[N];
    for (int i=0; i<N; i++)
    {
        if (r[i] != a && r[i] != b && r[i] != c)
        {
            r1[M] = r[i];
            M++;
        }
    }
    if (M>0)
    {
        M--;
    }
    cout<<M<<"\n";
    for (int i=0; i<M; i++)
    {
        cout<<r1[i]+r1[i+1]<<" ";
    }
    
    return 0;
}

