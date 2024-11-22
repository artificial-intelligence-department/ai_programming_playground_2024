#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    int n1, n2;
    int temp;
    std::cin >> n1 >> n2;
    std::set<int> tasks1, tasks2;
    for (int i=0; i<n1; i++)
    {
        std::cin >> temp;
        tasks1.insert(temp);
    }   
    for (int i=0; i<n2; i++)
    {
        std::cin >> temp;
        tasks2.insert(temp);
    }  
    std::set<int> unions;
    std::set_union(tasks1.begin(), tasks1.end(), tasks2.begin(), tasks2.end(), inserter(unions, unions.begin()));
    std::set<int> intersections;
    std::set_intersection(tasks1.begin(), tasks1.end(), tasks2.begin(), tasks2.end(), inserter(intersections, intersections.begin()));
    std::cout << unions.size() << " " << intersections.size();
    return 0;
}
