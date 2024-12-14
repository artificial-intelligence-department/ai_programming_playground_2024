#include <iostream>

int main()
{
	int n = 5, m = 3;

	int result1 = n-- - m;
	std::cout << "Result of n---m: " << result1 << ", n after: " << n << std::endl;

	n = 5, m = 3;

	bool result2 = m-- < n;
	std::cout << "Result of m--<n: " << std::boolalpha << result2 << ", m after: " << m << std::endl;

	n = 5, m = 3;

	bool result3 = n++ > m;
	std::cout << "Result of n++>m: " << std::boolalpha << result3 << ", n after: " << n << std::endl;

	return 0;
}
