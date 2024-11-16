#include <iostream>
#include <initializer_list>
#include <algorithm>

using namespace std;

auto min (initializer_list<int> numbers)
{
auto min_number = *numbers.begin(); 
    for (auto number : numbers) 
    { 
        if (number < min_number) 
        { 
            min_number = number; 
        } 
    }
return min_number;
}

int main()
{
cout << "Мінімальне значення (1, 2, 3, 4, 5): " << min({1, 2, 3, 4, 5}) << endl;
cout << "Мінімальне значення (74, 23, 81, 56, 34, 68, 97, 12, 45, 89): " << min({74, 23, 81, 56, 34, 68, 97, 12, 45, 89}) << endl;
cout << "Мінімальне значення (3, 59, 24, 77, 51, 36, 82, 15, 92, 68, 40, 11): " << min({3, 59, 24, 77, 51, 36, 82, 15, 92, 68, 40, 11}) << endl;
return 0;
}
