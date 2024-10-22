#include <iostream>
int main()
{
    int n, m;
    std::cout << "Enter two digits: ";
    std::cin >> n >> m;
    int first = ++n * ++m; // pre increment
    int second = m++ < n;  // post increment
    int third = n++ > m;   // post increment
    std::cout << "1) ++n*++m: " << first << '\n';
    std::cout << "2) m++<n: " << second << '\n';
    std::cout << "3) n++>m: " << third << '\n';
}
