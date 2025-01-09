#include <iostream>
#include <set>

int main()
{
    std::set<std::string> alcohol_names;
    int n,m;
    std::string temp;
    std::cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        std::cin >> temp;
        alcohol_names.insert(temp);
    }
    for(int i=0; i<m; i++)
    {
        std::cin >> temp;
        alcohol_names.insert(temp);
    }
    std::cout << alcohol_names.size();
}
