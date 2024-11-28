#include <iostream>
#include <vector>

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> path(size);
    int index1=0;
    int index2=size-1;
    for(int i=0; i<size; i++)
    {
        std::cin >> path[i];
    }
    do
    {
        if(index1==index2)
        {
            std::cout << index1+1 << " " << index2+1 << std::endl << "Collision";
            break;
        }
        else if (index2<index1)
        {
            std::cout << index1+1 << " " << index2+1 << std::endl << "Miss";
            break;
        }
        else if ((index2-index1)==1)
        {
            std::cout << index1+1 << " " << index2+1 << std::endl << "Stopped";
            break;
        }
        index1+=path[index1];
        index2-=path[index2];
    } while(true);
}