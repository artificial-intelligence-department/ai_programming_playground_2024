// 1691 https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40788
#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))

int main()
{
    int rm,sm,pm,rz,sz,pz;
    std::cin >> rm >> sm >> pm;
    std::cin >> rz >> sz >> pz;
    std::cout << MIN(rm,sz)+MIN(sm,pz)+MIN(pm,rz);
}