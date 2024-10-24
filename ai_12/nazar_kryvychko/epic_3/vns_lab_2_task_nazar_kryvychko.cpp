#include<iostream>

int main()
{
	unsigned short sum = 0;
	for (unsigned short i = 0; i < 100; i++)
	{
		i % 2 == 0 ? sum++ : true;
	}
	std::cout << "Sum of all pair numbers from 0 to 100 -> " << sum << std::endl;
	return 0;
}