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
            if (counter == 1)
                std::cout << str[i];
            else
                std::cout << str[i] << counter;
                
            counter = 1;
        }
 }
 return 0;
 
}
