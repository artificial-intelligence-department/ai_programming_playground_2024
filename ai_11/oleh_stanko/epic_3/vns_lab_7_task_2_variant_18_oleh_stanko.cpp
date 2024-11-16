#include <iostream>
#include <sstream>  

using namespace std;

int res(string& str)
{ 
    istringstream iss(str);
    string word; 
    int maxLength = 0; 
    while (iss >> word)
    { 
        if (word.length() > maxLength)
        {
            maxLength = word.length();
        } 
    } 
    return maxLength;
}

void res(int a[],int n)
{
    int maxim = a[0];
    for (int i = 1; i < n; i++)  
    {
        if (a[i] > maxim)  
        {
            maxim = a[i]; 
        }
    }   
    cout << "The largest number is " << maxim << endl;
}


int main()
{

    int n;
    cout << "Enter an amount of numbers: \n";
    cin >> n;
    int a[n]; 
    cout << "Enter an array of numbers: \n";
    for (int i = 0; i < n; i++)  
    {
        cin >> a[i];  
    }

    res(a,n);
    string s;
    cout << "Enter a string: \n";
    cin.ignore();  
    getline(cin, s);
    
    int longest_word_length = res(s);
    cout << "The length of the longest word is: " << longest_word_length << endl;

    return 0;
}
