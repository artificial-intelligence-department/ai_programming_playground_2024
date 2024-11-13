#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool IsPalindrome(const string& str, int start, int end)
{
    if (start >= end)
        return true;
    
    if (str[start] != str[end])
        return false;

    return IsPalindrome(str, start + 1, end - 1);
}

bool IsPalindrom(int num)
{
   if (num < 0)
        return false;

    string str = to_string(num);
    
    return IsPalindrome(str, 0, str.size() - 1);
}

int main()
{
   string arr[] = {"programming","1254521", "winter", "coca-cola", "radar", "Lviv"};

   int arr_size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_size; ++i) 
    {
        if (IsPalindrome(arr[i], 0, arr[i].size() - 1)) 
        {
            cout << "\"" << arr[i] << "\" є паліндромом." << endl;
        } else 
        {
            cout << "\"" << arr[i] << "\" не є паліндромом." << endl;
        }
    }

    int numbers[] = {121, 12321, 12345, 111, -121};

    int num_size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < num_size; ++i) 
    {
        if (IsPalindrom(numbers[i]))  
        {
            cout << numbers[i] << " є паліндромом." << endl;
        } else 
        {
            cout << numbers[i] << " не є паліндромом." << endl;
        }
    }

    return 0;
}
