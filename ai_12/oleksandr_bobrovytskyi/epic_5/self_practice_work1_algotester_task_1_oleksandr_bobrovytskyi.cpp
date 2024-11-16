#include<bits/stdc++.h>

using  namespace std;

int main()
{
    int left, count = 1;
    int right = 1e9;
    int middle;
    string response;

    while (left <= right && count !=48)
    {
        middle = left + (right - left) / 2; 
        cout << middle << endl << flush; 

        cin >> response;

        if(response != "=" && response != ">" && response != "<")
        {
            continue;
        }

        if (response == "=")
        {
            break; 
        }
        else if (response == ">")
        {
            right = middle - 1; 
        }
        else if (response == "<")
        {
            left = middle + 1; 
        }
        count++;
    }

    return 0;
}
