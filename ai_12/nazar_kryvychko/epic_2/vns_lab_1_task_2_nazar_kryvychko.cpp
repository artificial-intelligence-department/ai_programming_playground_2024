#include<iostream>

int main(void)
{
	int n, m;
	std::cin >> n >> m;

	std::cout << n++ * m << std::endl;
	std::cout << std::boolalpha;
	std::cout << (n++ < m) << std::endl;
	std::cout << (m-- > m) << std::endl;


	return 0;
}