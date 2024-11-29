#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

    
int main()
{
    string num1, num2, box;
    cin>>num1>>num2;
    int arr[1000]{};

    if (num1.length() < num2.length())
    {
        box = num1;
        num1 = num2;
        num2= box;
    }

    int current2 = num2.length() - 1;
    int current1 = num1.length() - 1;
    int s = 0, r = 0;
    int len = 0;
    while (current2 >= 0)
    {
        s = (int)num1[current1] - 48 + (int)num2[current2] - 48 + r;

        if (s > 9)
        {
            arr[len] = s % 10;
            r = s / 10;
            len++;
        }
        else
        {
            arr[len] = s;
            r = 0;
            len++;
        }
        current2--;
        current1--;
    }

    
    if (current1 >= 0)
    {
        while (current1 >= 0 )
        {
            s = (int)num1[current1] - 48 + r;

            if (s > 9)
            {
                arr[len] = s % 10;
                r = s / 10;
                len++;
            }
            else
            {
                arr[len] = s;
                r = 0;
                len++;
            }

            current1--;
        } 
    }
    else if (r != 0)
    {
        arr[len] = r;
        len++;
    }
    
    for (int i = len - 1; i >= 0; i--)
    {
        cout<<arr[i];
    }
         
    return 0;
}