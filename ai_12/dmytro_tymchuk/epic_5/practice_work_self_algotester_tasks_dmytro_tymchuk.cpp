#include<iostream>
#include<string>
using namespace std;


int main()
{
    string s1, s2;
    int arr[1000]{};

    cin>>s1;
    cin>>s2;
    
    for (int i = 0; i < s1.length(); i++)
    {
        arr[(int)s1[i]]++;
    }

    int flag = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        if (arr[(int)s2[i]] == 0) 
        {
            flag = 1;
            break;
        }
        else arr[(int)s2[i]]--; 
    }
    
    if (flag == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    

    return 0;
}