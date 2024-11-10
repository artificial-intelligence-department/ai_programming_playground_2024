#include <cstdio>
#include <cstdlib>
#include <vector>
int main()
{
    std::vector<int> r;
    int n;
    int a, b, c;
    int dummy;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dummy);
        r.push_back(dummy);
    }
    std::scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i] == a || r[i] == b || r[i] == c)
        {
            r.erase(r.begin() + i);
            --i;
        }
    }
    if (r.size() != 0 && r.size() != 1)
    {
        printf("%ld\n", r.size() - 1);

        for (int i = 0; i < r.size() - 1; i++)
        {
            printf("%d ", r[i] + r[i + 1]);
        }
    }
    else
    {
        printf("0");
    }
    return 0;
}
