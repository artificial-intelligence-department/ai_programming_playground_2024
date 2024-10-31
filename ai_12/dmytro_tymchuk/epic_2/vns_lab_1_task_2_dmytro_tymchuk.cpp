#include<iostream>
using namespace std;

int main()
{
    int m = 0, n = 0;
    int result = 0;

    result = m+--n; // спочатку n зменшується на 1, потім додається до m
    cout<<result<<endl;

    m = 0; n = 0;
    result = m++<++n; // спершу значення m підставляється у вираз, а вже потім збульшується на 1
    cout<<result<<endl;

    m = 0; n = 0;
    result = n--<--m;
    cout<<result<<endl;

    return 0;
}