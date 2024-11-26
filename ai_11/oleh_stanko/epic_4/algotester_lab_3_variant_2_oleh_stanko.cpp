#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i<N;i++)
    {
        cin >> a[i];
    }
    int M;
    cin >> M;
    int b[M];
    for (int i = 0; i<M;i++)
    {
        cin >> b[i];
    }
    int s=0;
    for (int i = 0; i<N;i++)
    {
        
        for (int j = 0; j<M; j++)
        {
            if (a[i]==b[j])
            {
                s++;
            }   
        }
    }
    cout<<s<<"\n";
    cout<<N+M-s; 
    return 0;   
}