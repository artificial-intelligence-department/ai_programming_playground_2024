#include <iostream>
int main()
{
    int n, m;
    std::cout << "Enter two digits: ";
    std::cin >> n >> m;
    int first = ++n * ++m;
    int second = m++ < n;
    int third = n++ > m;
    std::cout << "1) ++n*++m: " << first << '\n';
    std::cout << "2) m++<n: " << second << '\n';
    std::cout << "3) n++>m: " << third << '\n';
}
