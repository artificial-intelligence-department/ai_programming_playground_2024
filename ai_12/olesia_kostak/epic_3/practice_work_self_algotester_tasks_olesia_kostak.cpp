#include <iostream>
#include <string>


int main()
{
 std::string str;
 std::cin >> str;
 int counter = 1;
 for (int i = 0; i < str.length(); i++)
 {
    if (str [i] == str[i + 1])
        counter++;
    else 
        {
            std::cout << counter << str[i];
            counter = 1;
        }
 }
 return 0;
 
}